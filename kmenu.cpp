#include "kmenu.h"
#include "stdfix.h"
const char* VERSION = "Beta v1.0";
void mainMenu(int row, int col)
{
    erase();
    printRamka(row, col);
    move(row / 2, col / 2);
    printw("Menu");
    move(row / 2 + 1, col / 2);
    printw("1. Speed mode");
    move(row / 2 + 2, col / 2);
    printw("2. Time mode");
    move(row / 2 + 3, col / 2);
    printw("3. Blind seal mode");
    move(row / 2 + 4, col / 2);
    printw("4. Exit");
}
int printRamka(int _row, int _col)
{
    for (int i = 0; i < _col; i++)
        printw("*");
    move(2, 0);
    for (int i = 0; i < _col; i++)
        printw("*");

    move(1, 0);
    printw("*");

    move(1, _col - 1);
    printw("*");

    for (int i = 3; i < _row - 1; i++) {
        move(i, 0);
        printw("*");
        move(i, _col - 1);
        printw("*");
    }
    move(_row, 0);
    for (int i = 0; i < _col; i++)
        printw("*");
    move(1, _col - 10); // TODO strlen & string for VERSION
    printw(VERSION);
    return 0;
}