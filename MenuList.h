#pragma once
#include "Menu.h"

struct MenuListItem {
    const char* text;
    virtual void clicked(Menu& menu) {};

    MenuListItem(const char* text)
        : text(text)
    {};
};

struct MenuList : public MenuItem {
    ItemsList<MenuListItem*> listItems = ItemsList<MenuListItem*>(MAX_MENU_ITEMS);
    int selectedIndex = 0;

    void nextItem();
    void previousItem();

    void draw(Menu& menu) const override;
    void clicked(Menu& menu) override;
    void up(Menu& menu) override;
    void down(Menu& menu) override;
};

template<typename T>
struct MenuRedirectListItem : MenuListItem {
    using MenuListItem::MenuListItem;

    void clicked(Menu& menu) override;
};

template<typename T>
void MenuRedirectListItem<T>::clicked(Menu& menu) {
    menu.loadMenuItem(new T());
}