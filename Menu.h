#pragma once
#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include "ItemsList.h"

constexpr int MAX_MENU_ITEMS = 25;

struct Menu;

struct MenuItem {
    virtual void draw(Menu& menu) const = 0;
    virtual void up(Menu& menu) {};
    virtual void down(Menu& menu) {};
    virtual void clicked(Menu& menu) {};
};

class Menu {
public:
    ItemsList<MenuItem*> menuItems = ItemsList<MenuItem*>(MAX_MENU_ITEMS);
    int numItems = 0;
    const int rows, cols;
    hd44780_I2Cexp lcd;
    unsigned long lastMillis = 0;
    
    void draw();
    void printCenter(int row, const char* text);
    void loadMenuItem(MenuItem* item);

    void up();
    void down();
    void clicked();

    Menu(int rows, int cols)
        : rows(rows),
        cols(cols),
        lcd(0x27, cols, rows)
    {
        lcd.init();
        lcd.clear();
    };
};