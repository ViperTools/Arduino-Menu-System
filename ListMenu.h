#pragma once
#include "Menu.h"

struct ListMenuItem {
    const char* text;
    virtual void clicked(Menu& menu) {};

    ListMenuItem();
    ListMenuItem(const char* text)
        : text(text)
    {};
};

struct ListMenu : public MenuItem {
    ItemsList<ListMenuItem*> listItems = ItemsList<ListMenuItem*>(MAX_MENU_ITEMS);
    int selectedIndex = 0;

    void nextItem();
    void previousItem();

    void draw(Menu& menu) const override;
    void clicked(Menu& menu) override;
    void up(Menu& menu) override;
    void down(Menu& menu) override;
};

template<typename T>
struct RedirectMenuListItem : ListMenuItem {
    using ListMenuItem::ListMenuItem;

    void clicked(Menu& menu) override;
};

template<typename T>
void RedirectMenuListItem<T>::clicked(Menu& menu) {
    menu.loadMenuItem(new T());
}