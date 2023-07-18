#pragma once
#include "Menu.h"

class AutoScrollMenuItem : public MenuItem {
public:
    int delay = 500;

    void update(Menu& menu) override;
    void draw(Menu& menu) const override;

    inline const String& getText() const { return text; }
    void setText(String text);

    AutoScrollMenuItem();
    AutoScrollMenuItem(String text)
        : text(text),
        render(text)
    {};

private:
    String text, render;
    unsigned long lastScrollTime = millis();
    int index = 0;

    void scroll(Menu& menu);
};