#include <iostream>
#include <conio.h>
#include <windows.h>

void gotoxy(short x, short y) //Defines gotoxy()
							  //Since we are still used to gotoxy()
							  //will adapt later on
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}