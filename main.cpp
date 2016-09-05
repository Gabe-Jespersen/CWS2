#include <vector>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

#include "tribe.hpp"

using namespace std;

int main(int argc, char** argv)
{
    srand(time(NULL));//seeding random

    int tribeChoice = 4;
    tribe alpha;//making
    tribe beta; //three
    tribe cappa;//tribes

    for(int i = 0; i < 100; i++)
    {
        alpha.forceBirth();
    }
    for(int i = 0; i < 100; i++)
    {
        beta.forceBirth();
    }
    for(int i = 0; i < 100; i++)
    {
        cappa.forceBirth();
    }

    //this is an abortion of ncurses
    initscr();
    keypad(stdscr, TRUE);//reads arrow keys

    int choice = 0;
    while(tribeChoice == 4)
    {
        move(0,0);
        printw("Alpha [ ]\nBeta  [ ]\nCappa [ ]\n");
        move(choice, 7);
        refresh();

        int temp = getch();
        switch(temp)
        {
            case KEY_UP:
                choice--;
                break;
            case KEY_DOWN:
                choice++;
                break;
            case 10:
                tribeChoice = choice;
                break;
        }
        if(choice < 0)
        {
            choice = 2;
        }
        if(choice > 2)
        {
            choice = 0;
        }
    }

    endwin();

    return 0;
}
