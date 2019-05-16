#include "kmenu.h"
#include "stdfix.h"
#include <ctime>
#include <vector>
#include <string>
using namespace std;
const char* VERSION = "Beta v1.0";
const unsigned int SEC = 1;

int mainMenu(int row, int col)
{
    erase();
    printRamka(row, col);
	std::string mStr[5] = {
		"    Menu",
		"1. Speed mode",
		"2. Time mode",
		"3. Blind seal mode",
		"4. Exit"
	};
	
	int c = 1;
	//start_color();
	int temp;
	noecho();
	keypad(stdscr, TRUE);
	do{
		for(int i = 0; i < 5; i++){//TODO 5 ->size
			move(row/2 + i, col/2 - 9);
			if (i == c){
				//attron(A_BLINK);
				for (long long unsigned int j=0; j< mStr[i].length(); j++)
				addch(mStr[i][j] | A_BLINK);
			}
			else{
				printw("%s", mStr[i].c_str());
			}
		}
		temp = getch();
		if (temp == KEY_UP){
				if (c != 1)
					c--;
				else
					c = 4;
			}
		if (temp == KEY_DOWN){
			if (c != 4)
				c++;
			else
				c = 1;
		}
		refresh();
	}while(temp != '\n');
	return c;
}
int printRamka(int _row, int _col)
{
	curs_set(0);
	refresh();
	WINDOW *win = newwin(3, _col, 0, 0);
	box(win,0,0);
	
	WINDOW *win1 = newwin(_row - 3, _col, 3, 0); 
	box(win1, 0, 0);
	
	mvaddstr(1, _col - 10, VERSION);
	wrefresh(win1);
	wrefresh(win);
    return 0;
}

int slozhnost(int row, int col)
{
	erase();
    printRamka(row, col);
	std::string mStr[5] = {
		"  Slozhn", // TODO eng
		"1. Eazy",
		"2. Normal",
		"3. Hard",
		"4. Back"
	};
	
	int c = 1;
	int temp;
	noecho();
	keypad(stdscr, TRUE);
	do{
		for(int i = 0; i < 5; i++){//TODO 5 ->size
			move(row/2 + i, col/2 - 9);
			if (i == c){
				//attron(A_BLINK);
				for (long long unsigned int j=0; j< mStr[i].length(); j++)
				addch(mStr[i][j] | A_BLINK);
			}
			else{
				printw("%s", mStr[i].c_str());
			}
		}
		temp = getch();
		if (temp == KEY_UP){
				if (c != 1)
					c--;
				else
					c = 4;
			}
		if (temp == KEY_DOWN){
			if (c != 4)
				c++;
			else
				c = 1;
		}
		refresh();
	}while(temp != '\n');
	return c;
}

void speedNormal(string _dataFile, int row, int col)
{
	std::ifstream dataFile(_dataFile);
	std::vector <std::string> vec;
	
	while(!dataFile.eof()){
		std::string temp;
		std::getline(dataFile, temp);
		vec.push_back(temp);
	}
	
	unsigned int result = 0;
			unsigned int startTime = clock();
			unsigned int endTime = startTime;
			
			nodelay(stdscr, TRUE);
			int ch;
			int temp;
			long long unsigned int i =0;
			std::string tempA;
			bool flag = 1;
			int x,y, x_temp;
			do{
				
				if ((ch = getch()) == ERR){
					if (flag){
						tempA = vec.at(rand() % vec.size());
						x = (rand() % (col- tempA.length()-1)+1) ;
						y = (rand() % (row-5)) + 4;
						erase();
						printRamka(row, col);
						move(y,x);
						printw("%s", tempA.c_str());
						flag = 0;
					}
					
					endTime = clock();
					move(1,5);
					printw("%d ms", endTime - startTime);
					move(1,1);
					printw("%d", result);
				}
				
				else{
					temp = ch;
					flag = 0;
					
					if ((int)tempA[i] != temp || i == 0){
						if(tempA[i] != temp){
							i=0;
							flag = 1;
						}
						else{
							x_temp = x;
							move(y, x_temp++);
							addch(tempA.at(i)| A_BLINK );
							i++;
						}
						refresh();
					}else{
						move(y, x_temp++);
						addch(tempA.at(i)| A_BLINK );
						i++;
						if (i == tempA.length()){
							flag =1;
							i=0;
							if (endTime < startTime + SEC * 1000)
							result++;
						}
						refresh();						
					}
				}
			}while(endTime < startTime + SEC * 1000);
			nodelay(stdscr, FALSE);
			
			erase();
			printRamka(row, col);
			//int col_t = 0, row_t = 0;
			int ySize = 9,
				xSize = col -(row - ySize +3 +2),
				yy = (row - ySize - 5) / 2 + 4,
				xx = (col - xSize) / 2;
				if ((col - xSize)%2 != 0)
					xSize++;
				if ((row - ySize)%2 == 0)
					ySize++;
				
		//	if ((col - (col - 1 - (row-9+4)))%2 != 0)
			//	col_t = 1; 
			//if (row%2 != 0)
				//row_t = 1;
			//WINDOW *win = newwin(9 - row_t, col - 1 - (row-9+4)+ col_t, (row-9+4)/2, (row - 9 +5)/2);// TODO сделать переменные ширины и тд.
				WINDOW *win = newwin(ySize, xSize, yy, xx);
				move(yy + 2, xx+xSize/2);
				printw("Result: %d", result);
				move(yy + 3, xx+xSize/2);
				// TODO add: time, % ...
				result > 0? 
					printw("MOLODEC! :)"):
					printw("NE MOLODEC! :(");
				box(win,0,0);
				wrefresh(win);
				getch();
}
void speedMode(int slozh, int row, int col)
{
	erase();
    printRamka(row, col);
	
	switch (slozh) {
        case 1:
		{
			unsigned int result = 0;
			unsigned int startTime = clock();
			unsigned int endTime = startTime;
			
			do{
				move(rand() % (row-4) + 3,
					 rand() % (col - 2) + 1);
				char tempA = rand() % 26 + 0x61;
				addch(tempA);
				if (getch() == tempA && endTime <= startTime + 10 * 1000)
					result++;
				erase();
				printRamka(row, col);
				move(1,1);
				printw("%d", result);
				endTime = clock();
				move(1,5);
				printw("%d ms", endTime - startTime);
				
			}while(endTime < startTime + 10 * 1000);
			WINDOW *win = newwin(9, 60, (row-9)/2, (col-60)/2);
				
				move((row-9)/2 + 4, (col-60)/2 + 25);
				printw("Result: %d", result);
				move((row-9)/2 + 5, (col-60)/2 + 25);
				printw("MOLODEC!");
				box(win,0,0);
				wrefresh(win);
				getch();
			break;
		}
        
		case 2:{
			speedNormal("Word.txt", row, col);
			break;
		}
			
		case 3:{
				speedNormal("Pred.txt", row, col);
				break;
		}
		case 4:
			break;
    }	
}















