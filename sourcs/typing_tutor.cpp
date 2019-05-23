#include "tutur.h"
#include "stdfix.h"
#include <ctime>
#include <vector>
#include <string>

long long unsigned int printMenu(std::vector <std::string>& _vec);
int printRamka(int _row, int _col);

int lewel (int row, int col)
{
	erase();
    printRamka(row, col);
	vector <std::string> mStr = {
		"  Slozhn", // TODO eng
		"1. level 1 to 5",
		"2. level 6 to 10",
		"3. level 11 to 15"
		
	};

	noecho();
	keypad(stdscr, TRUE);
	
	return printMenu(mStr);
}

void lewel_select(int slozh, int row, int col)
{
	erase();
    printRamka(row, col);
	
	switch (slozh) {
        case 1:
		{
			
			break;
		}
        
		case 2:{
			
			break;
		}
			
		case 3:{
				
				break;
		}
		case 4:
			break;
    }	
}