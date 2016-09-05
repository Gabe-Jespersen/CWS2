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

    int tribeNumber = 3;
    if(tribeNumber > 9)
    {
        return 0;
    }

    int initPopulation = 50;

    vector<tribe> tribes;
    tribes.resize(tribeNumber);

    for(int i = 0; i < tribeNumber; i++)
    {
        for(int j = 0; j < initPopulation; j++)
        {
            tribes.at(i).forceBirth();
        }
    }

    //this is an abortion of ncurses
    initscr();
    keypad(stdscr, TRUE);//reads arrow keys

    int choice = 0;
    while(tribeChoice == 4)
    {
        move(0,0);
        for(int i = 0; i < tribeNumber; ++i)
        {
            printw("Tribe %d [ ]\n", i);
        }
        move(choice, 9);
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
            choice = tribeNumber - 1;
        }
        if(choice > tribeNumber - 1)
        {
            choice = 0;
        }
    }

    //temp
    clear();
    for(int i = 0; i < 100; ++i)
    {
        for(int j = 0; j < tribeNumber; ++j)
        {
            tribes.at(j).hunt(tribes.at(j).getTribesmen().size());
            tribes.at(j).stdCycle();
            printw("%d\n",tribes.at(j).getTribesmen().size());
        }
        printw("\n");
        refresh();
    }

    endwin();

    return 0;
}
