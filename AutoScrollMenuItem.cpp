#include "AutoScrollMenuItem.h"

void AutoScrollMenuItem::draw(Menu& menu) const {
    menu.lcd.print(render);
}

void AutoScrollMenuItem::update(Menu& menu) {
    if (millis() - lastScrollTime >= delay) {
        scroll(menu);
        lastScrollTime = millis();
    }
}

void AutoScrollMenuItem::scroll(Menu& menu) {
    int textLength = text.length();
    int renderLength = textLength - index;
    int maxRenderLength = menu.cols;

    if (textLength <= maxRenderLength) {
        return;
    }

    if (++index >= textLength) {
        index = 0;
    }

    render = text.substring(index);

    if (renderLength > maxRenderLength) {
        render = render.substring(0, maxRenderLength);
    }
    else if (renderLength < maxRenderLength) {
        render += " " + text.substring(0, maxRenderLength - renderLength);
    }

    menu.draw();
}

void AutoScrollMenuItem::setText(String text) {
    this->text = this->render = text;
    index = 0;
}