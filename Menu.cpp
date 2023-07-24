#include "Menu.h"
#include "RotaryEncoder.h"

void Menu::draw() {
    lcd.clear();
    
    for (int i = 0; i < menuItems.length; i++) {
        menuItems[i]->draw(*this);
    }
}

void Menu::update() {
    if (RotaryEncoder::update(*this)) {
        lastMillis = millis();
        lcd.on();
    }

    if (autoTurnOffDelay && millis() - lastMillis >= autoTurnOffDelay) {
        lastMillis = millis();
        lcd.off();
    }

    for (int i = 0; i < menuItems.length; i++) {
        menuItems[i]->update(*this);
    }
}

void Menu::loadMenuItem(MenuItem* item) {
    menuItems.clear();
    menuItems.pushBack(item);
}

void Menu::printCenter(int row, const char* text) {
    int len = strlen(text);

    if (len > cols) {
        return;
    }

    int col = cols / 2 - (len - 2) / 2 - 1;

    lcd.setCursor(col, row);
    lcd.print(text);
}

void Menu::down() {
    for (int i = 0; i < menuItems.length; i++) {
        menuItems[i]->down(*this);
    }
    
    draw();
}

void Menu::up() {
    for (int i = 0; i < menuItems.length; i++) {
        menuItems[i]->up(*this);
    }

    draw();
}

void Menu::clicked() {
    for (int i = 0; i < menuItems.length; i++) {
        menuItems[i]->clicked(*this);
    }

    draw();
}