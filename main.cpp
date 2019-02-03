#include <iostream>
#include <conio.h>
#include <stdlib>
#include <stdio.h>
#include "include/gotoxy.cpp"

using namespace std;

int main()
{	int x = 6, y = 4;
    char cursor;
    system("cls");
	textcolor(6);
	gotoxy(x, y++);
	printf(" /$$$$$$$                           /$$      /$$                    \n");
	gotoxy(x, y++);
	printf("| $$__  $$                         | $$$    /$$$                    \n");
	gotoxy(x, y++);
	printf("| $$    $$ /$$$$$$   /$$$$$$$      | $$$$  /$$$$  /$$$$$$  /$$$$$$$ \n");
	gotoxy(x, y++);
	printf("| $$$$$$$/|____  $$ /$$_____/      | $$ $$/$$ $$ |____  $$| $$__  $$\n");
	gotoxy(x, y++);
	printf("| $$____/  /$$$$$$$| $$            | $$  $$$| $$  /$$$$$$$| $$    $$\n");
	gotoxy(x, y++);
	printf("| $$      /$$__  $$| $$            | $$   $ | $$ /$$__  $$| $$  | $$\n");
	gotoxy(x, y++);
	printf("| $$     |  $$$$$$$|  $$$$$$$      | $$  /  | $$|  $$$$$$$| $$  | $$\n");
	gotoxy(x, y++);
	printf("|__/       _______/  _______/      |__/     |__/  _______/|__/  |__/\n");
    x = 35; y = 15;
    textcolor(3);
    for (int i = 0; i < 6; ++i)
    {
        gotoxy(x, ++y);
        switch (i)
        {
        case 0:
            cout << "New Game";
            break;
        case 1:
            cout << "High Score";
            break;
        case 2:
            cout << "Difficulty Level";
            break;
        case 3:
            cout << "Help";
            break;
        case 4:
            cout << "About";
            break;
        case 5:

            gotoxy(30, y);
            cout << "(use esc to exit)";
            break;
        }
    }
    x = 34;
    y = 15;
    gotoxy(x, ++y);
    cout << ">";
    while (cursor != 13)
    {
        cursor = getch();
        switch (cursor)
        {
        case 72: //72 ASCII value of up arrow key
            gotoxy(x, y);
            cout << " ";
            gotoxy(x, --y);
            if (y == 15)
                y = 20;
            gotoxy(x, y);
            cout << ">";
            break;

        case 80: //80 ASCII value of down arrow key
            gotoxy(x, y);
            cout << " ";
            gotoxy(x, ++y);
            if (y == 21)
                y = 16;
            gotoxy(x, y);
            cout << ">";
            break;
        case 27: //27 ASCII value of esc key
            return 0;
        }
    }
    if (cursor == 13)
        switch (y)
        {
        case 16:
            system("cls");
            cout << "New Game WIP";
            break;
        case 17:
            system("cls");
            cout << "High Score WIP";
            break;
        case 18:
            system("cls");
            cout << "Level WIP";
            break;
        case 19:
            system("cls");
            cout << "Help WIP";
            break;
        case 20:
            system("cls");
            cout << "About WIP";
            break;
        }
    getch();
    return 0;
}
