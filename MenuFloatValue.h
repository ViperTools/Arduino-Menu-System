#pragma once
#include "Menu.h"

struct MenuFloatValue : public MenuItem {
    const char* title;
    float increment;
    float value, minValue, maxValue;
    bool disabled = false;

    void draw(Menu& menu) const override;
    void clicked(Menu& menu) override;
    void up(Menu& menu) override;
    void down(Menu& menu) override;

    MenuFloatValue(const char* title, float minValue, float maxValue, float value, float increment)
        : title(title),
        minValue(minValue),
        maxValue(maxValue),
        value(value),
        increment(increment)
    {};

    MenuFloatValue(const char* title, float minValue, float maxValue)
        : MenuFloatValue(title, minValue, maxValue, minValue, 0.1)
    {};
};