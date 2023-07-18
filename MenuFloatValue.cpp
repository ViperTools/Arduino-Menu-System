#include "MenuFloatValue.h"

void MenuFloatValue::draw(Menu& menu) const {
    menu.printCenter(0, title);
    menu.printCenter(menu.rows / 2, String(value).c_str());
}

void MenuFloatValue::clicked(Menu& menu) {
}

void MenuFloatValue::up(Menu& menu) {
    if (disabled) return;

    value -= increment;

    if (value < minValue) {
        value = minValue;
    }
}

void MenuFloatValue::down(Menu& menu) {
    if (disabled) return;

    value += increment;

    if (value > maxValue) {
        value = maxValue;
    }
}