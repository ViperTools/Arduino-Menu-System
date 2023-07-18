#include "MenuList.h"

static constexpr int TEXT_OFFSET = 2;

void MenuList::draw(Menu& menu) const {
    int start = max(0, selectedIndex - menu.rows + 1);
    int end = min(listItems.length, start + menu.rows);

    for (int i = start; i < end; i++) {
        int row = i - start;

        if (i == selectedIndex) {
            menu.lcd.setCursor(0, row);
            menu.lcd.print("~ ");
        }

        menu.lcd.setCursor(TEXT_OFFSET, row);
        menu.lcd.print(listItems[i]->text);
    }
}

void MenuList::nextItem() {
    if (++selectedIndex == listItems.length) {
        selectedIndex = 0;
    }
}

void MenuList::previousItem() {
    if (--selectedIndex == -1) {
        selectedIndex = listItems.length - 1;
    }
}

void MenuList::clicked(Menu& menu) {
    listItems[selectedIndex]->clicked(menu);
}

void MenuList::up(Menu& menu) {
    previousItem();
}

void MenuList::down(Menu& menu) {
    nextItem();
}