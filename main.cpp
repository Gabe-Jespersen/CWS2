#include <vector>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <string>

#include "tribe.hpp"

using namespace std;

int main(int argc, char** argv)
{
    srand(0);//testing
    //srand(time(NULL));//seeding random

    int tribeChoice = 4;

    int tribeNumber = 10;
    if(tribeNumber > 99)
    {
        return 0;
    }

    int initPopulation = 1000;

    vector<tribe> tribes;
    tribes.resize(tribeNumber);

    for(unsigned i = 0; i < tribes.size(); i++)
    {
        for(int j = 0; j < initPopulation; j++)
        {
            tribes.at(i).forceBirth();
        }
    }

    //this is an abortion of ncurses
    initscr();
    keypad(stdscr, TRUE);//reads arrow keys

    unsigned choice = 0;

    //temp
    tribeChoice = 0;
    //temp
    
    while(tribeChoice == 4)
    {
        move(0,0);
        for(unsigned i = 0; i < tribes.size(); ++i)
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
            choice = tribes.size() - 1;
        }
        if(choice > tribes.size() - 1)
        {
            choice = 0;
        }
    }

    //temp
    while(true)
    {
        if(tribes.size() == 0)
        {
            break;
        }

        clear();

        for(unsigned j = 0; j < tribes.size(); ++j)
        {
            tribes.at(j).hunt(tribes.at(j).getTribesmen().size());
            tribes.at(j).aiCycle();
            tribes.at(j).stdCycle();
            printw("%d,%d,%d\n",tribes.at(j).getTribesmen().size(),tribes.at(j).getFood(),tribes.at(j).getTech());
            if(tribes.at(j).getTribesmen().size() == 0)
            {
                tribes.erase(tribes.begin() + j);

                //temp
                /*
                for(int i = 0; i < 1000; ++i)
                {
                    tribes.at(j).forceBirth();
                }
                */
            }
            if(tribes.at(j).getTech() >= 100)//current win condition
            {
                endwin();
                return 0;
            }
        }

        printw("\n");
        refresh();
    }

    endwin();

    return 0;
}
