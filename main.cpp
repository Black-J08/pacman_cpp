#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include "include/ShowConsoleCursor.cpp"
#include "include/textcolor.cpp"
#include "include/gotoxy.cpp"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 77
#define KEY_RIGHT 75
#define ESC 27

using namespace std;

void menu();
void new_game();
void print_map();
void game();
void game_input();

bool gameover = false;
enum direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
direction dir = RIGHT;

int map[23][30] = {{32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32},
                   {32, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187},
                   {32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
                   {32, 186, 32, 201, 205, 205, 187, 32, 201, 205, 205, 205, 205, 187, 32, 186, 32, 201, 205, 205, 205, 205, 187, 32, 201, 205, 205, 187, 32, 186},
                   {32, 186, 32, 200, 205, 205, 188, 32, 200, 205, 205, 205, 205, 188, 32, 186, 32, 200, 205, 205, 205, 205, 188, 32, 200, 205, 205, 188, 32, 186},
                   {32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
                   {32, 186, 32, 205, 205, 205, 205, 32, 186, 32, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 32, 186, 32, 205, 205, 205, 205, 32, 186},
                   {32, 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 186},
                   {32, 200, 205, 205, 205, 205, 187, 32, 204, 205, 205, 205, 205, 205, 32, 186, 32, 205, 205, 205, 205, 205, 185, 32, 201, 205, 205, 205, 205, 188},
                   {32, 32, 32, 32, 32, 32, 186, 32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186, 32, 186, 32, 32, 32, 32, 32},
                   {32, 205, 205, 205, 205, 205, 188, 32, 186, 32, 201, 205, 205, 205, 205, 32, 205, 205, 205, 205, 187, 32, 186, 32, 200, 205, 205, 205, 205, 205},
                   {32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32},
                   {32, 205, 205, 205, 205, 205, 187, 32, 186, 32, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188, 32, 186, 32, 201, 205, 205, 205, 205, 205},
                   {32, 32, 32, 32, 32, 32, 186, 32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186, 32, 186, 32, 32, 32, 32, 32},
                   {32, 201, 205, 205, 205, 205, 188, 32, 186, 32, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 32, 186, 32, 200, 205, 205, 205, 205, 187},
                   {32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
                   {32, 186, 32, 205, 205, 205, 187, 32, 205, 205, 205, 205, 205, 205, 32, 186, 32, 205, 205, 205, 205, 205, 205, 32, 201, 205, 205, 205, 32, 186},
                   {32, 186, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 186},
                   {32, 204, 205, 205, 205, 32, 186, 32, 186, 32, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 32, 186, 32, 186, 32, 205, 205, 205, 185},
                   {32, 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 186, 32, 32, 32, 32, 32, 32, 186},
                   {32, 186, 32, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 32, 186, 32, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 32, 186},
                   {32, 186, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 186},
                   {32, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188}};

int main()
{
    ShowConsoleCursor(false);
    menu();
    getch();
    return 0;
}

void menu()
{
    int x = 6, y = 4;
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
    x = 35;
    y = 15;
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
    while (cursor != 13) //13 ASCII value of Enter Key
    {
        cursor = getch();
        switch (cursor)
        {
        case KEY_UP: //72 ASCII value of up arrow key
            gotoxy(x, y);
            cout << " ";
            gotoxy(x, --y);
            if (y == 15)
                y = 20;
            gotoxy(x, y);
            cout << ">";
            break;

        case KEY_DOWN: //80 ASCII value of down arrow key
            gotoxy(x, y);
            cout << " ";
            gotoxy(x, ++y);
            if (y == 21)
                y = 16;
            gotoxy(x, y);
            cout << ">";
            break;
        case ESC: //27 ASCII value of esc key
            exit(0);
        }
    }
    if (cursor == 13)
        switch (y)
        {
        case 16:
            new_game();
            //cout << "New Game WIP";
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
}

void new_game()
{
    
    system("cls");
    print_map();
    thread t1(game_input);
    thread t2(game);
    t1.join();
    t2.join();
}

void print_map()
{
    char temp;
    for (int y = 0; y < 23; y++)
    {
        for (int x = 0; x < 30; x++)
        {
            temp = map[y][x];
            cout << temp;
        }
        cout << endl;
    }
}

void game()
{
    int pacx = 15, pacy = 13;
    char input;
    while (gameover != true)
    {
        //cout << map[pacx][pacy];
        //input = getch();
        gotoxy(pacx, pacy);
        cout << " ";
        switch (dir)
        {
        case UP: //ASCII of up arrow key
            if (map[pacy - 1][pacx] == 32)
                pacy--;
            break;
        case DOWN: //ASCII of down arrow key
            if (map[pacy + 1][pacx] == 32)
                pacy++;
            break;
        case LEFT: //ASCII of left arrow key
            if (map[pacy][pacx - 1] == 32)
                pacx--;
            break;
        case RIGHT: //ASCII of right arrow key
            if (map[pacy][pacx + 1] == 32)
                pacx++;
        }
        gotoxy(pacx, pacy);
        cout << "<";
        Sleep(150);
    }
    return;
}

void game_input()
{
    char input;
    while (input != ESC)
    {
         input = getch();
        switch (input)
        {
        case KEY_UP:
            dir = UP;
            break;
        case KEY_DOWN:
            dir = DOWN;
            break;
        case KEY_LEFT:
            dir = RIGHT;
            break;
        case KEY_RIGHT:
            dir = LEFT;
            break;
        case ESC:
            gameover = true;
        }
    }
    return;
}
