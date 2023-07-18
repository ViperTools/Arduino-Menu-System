#include "FloatValueMenu.h"

void FloatValueMenu::draw(Menu& menu) const {
    menu.printCenter(0, title);
    menu.printCenter(menu.rows / 2, String(value).c_str());
}

void FloatValueMenu::clicked(Menu& menu) {
}

void FloatValueMenu::up(Menu& menu) {
    if (disabled) return;

    value -= increment;

    if (value < minValue) {
        value = minValue;
    }
}

void FloatValueMenu::down(Menu& menu) {
    if (disabled) return;

    value += increment;

    if (value > maxValue) {
        value = maxValue;
    }
}