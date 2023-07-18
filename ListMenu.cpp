#include "ListMenu.h"

static constexpr int TEXT_OFFSET = 2;

void ListMenu::draw(Menu& menu) const {
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

void ListMenu::nextItem() {
    if (++selectedIndex == listItems.length) {
        selectedIndex = 0;
    }
}

void ListMenu::previousItem() {
    if (--selectedIndex == -1) {
        selectedIndex = listItems.length - 1;
    }
}

void ListMenu::clicked(Menu& menu) {
    listItems[selectedIndex]->clicked(menu);
}

void ListMenu::up(Menu& menu) {
    previousItem();
}

void ListMenu::down(Menu& menu) {
    nextItem();
}