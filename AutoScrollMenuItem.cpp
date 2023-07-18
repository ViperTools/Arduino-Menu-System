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
    int maxRenderLength = menu.cols;

    if (textLength <= maxRenderLength) {
        return;
    }

    if (++index > textLength) {
        index = 0;
    }

    int renderLength = textLength - index;
    render = text.substring(index, min(index + maxRenderLength, textLength));

    if (renderLength < maxRenderLength) {
        render += " " + text.substring(0, maxRenderLength - renderLength);
    }

    Serial.println(renderLength);
    Serial.println(render);

    menu.draw();
}

void AutoScrollMenuItem::setText(String text) {
    this->text = this->render = text;
    index = 0;
}