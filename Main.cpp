#include "kmenu.h"
#include "stdfix.h"

#define PDC_DLL_BUILD
int printWelcomePanel(string _str, int row, int col)
{
    ifstream myTextFile;
    myTextFile.open(_str);
    if (!myTextFile.is_open())
        return 1;
    move(row / 2, col / 2);
    printw("Hello");
    myTextFile.close();
    return 0;
}
int main(int argc, char** argv)
{
    int row, col;
    char ch;

    initscr();
    getmaxyx(stdscr, row, col);
    printRamka(row, col);
    printWelcomePanel(argv[1], row, col);

    while (1) {
        mainMenu(row, col);

        noecho();
        ch = getch();
        switch (ch) {
        case '1':
        case '2':
        case '3':
        case '4':
            return 0;
        }
    }

    getch();
    endwin();
    return 0;
}