#include <iostream>
#include <fstream>
#define PDC_DLL_BUILD 
#include "curses.h"

const char* VERSION = "Beta v1.0";

using namespace std;
int printWelcomePanel(string _str)
{
	ifstream myTextFile;
	myTextFile.open(_str);
	if (!myTextFile.is_open())
		return 1;
	
	myTextFile.close();
	return 0;
}

int printRamka(int _row, int _col)
{
	for (int i = 0; i < _col; i++)
		printw("*");
	move(2,0);
	for (int i = 0; i < _col; i++)
		printw ("*");
	
	move(1, 0);
	printw("*");
	
	move(1, _col -1);
	printw("*");
	
	for (int i = 3; i < _row - 1; i++)
	{
		move(i,0);
		printw("*");
		move(i, _col-1);
		printw("*");
	}
	move(_row,0);
	for (int i = 0; i < _col; i ++)
		printw("*");
	move(1, _col-10); // TODO strlen & string for VERSION
	printw(VERSION);
	return 0;
}

int main(int argc, char **argv)
{	
	int row, col;
	
	initscr();
	getmaxyx(stdscr, row, col);
	printRamka(row, col);
	printWelcomePanel(argv[1]);
	
	
	
	
	noecho();
	
	
	getch();
	endwin();
	return 0;
}