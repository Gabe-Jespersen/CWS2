#include <vector>
#include <algorithm>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <string>

#include "tribe.hpp"
#include "util.hpp"

using namespace std;

int main(int argc, char** argv)
{
    srand(time(NULL));//seeding random

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
        tribes.at(i).setNumber(i);
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
    vector<thread> threads;
    while(true)
    {
        if(tribes.size() == 0)
        {
            break;
        }

        clear();

        for(unsigned j = 0; j < tribes.size(); ++j)//end/win/kill/whatever
        {
            if(tribes.at(j).getTech() >= 1000 || tribes.size() == 1)//current win condition
            {
                clear();
                printw("Tribe %d wins\n",tribes.at(j).getNumber());
                refresh();
                getch();
                endwin();
                return 1;
            }
            else if(tribes.at(j).getTribesmen().size() == 0)//if they're dead
            {
                tribes.erase(tribes.begin() + j);
            }
            /*
            //tribes.at(j).hunt(tribes.at(j).getTribesmen().size());
            tribes.at(j).aiCycle();
            tribes.at(j).stdCycle();
            printw("Tribe %d: %d,%d,%d\n",tribes.at(j).getNumber(), 
            tribes.at(j).getTribesmen().size(),tribes.at(j).getFood(),tribes.at(j).getTech());
            */
        }

        /* works fine
        for(unsigned i = 0; i < tribes.size(); ++i)
        {
            //tribes.at(j).hunt(tribes.at(j).getTribesmen().size());
            tribes.at(i).aiCycle();
            tribes.at(i).stdCycle();
            printw("Tribe %d: %d,%d,%d\n",tribes.at(i).getNumber(), 
            tribes.at(i).getTribesmen().size(),tribes.at(i).getFood(),tribes.at(i).getTech());
        }
        */

        //initiate multiAIDS
        printw("mark 1\n");
        refresh();
        //getch();
        for(unsigned i = 0; i < tribes.size(); ++i)
        {
            threads.push_back(thread([&tribes,&i]{printw("test\n");
                                                  tribes.at(i).aiCycle();
                                                  tribes.at(i).stdCycle();
                                                  printw("Tribe %d: %d,%d,%d\n",tribes.at(i).getNumber(),
                                                  tribes.at(i).getTribesmen().size(),tribes.at(i).getFood(),
                                                  tribes.at(i).getTech());
                                                  }));
            //threads.push_back(thread([]{printw("test\n");}));
        }
        printw("mark 2\n");
        refresh();
        getch();
        for(unsigned i = 0; i < tribes.size(); ++i)
        {
            threads.at(i).join();
        }
        printw("mark 3\n");
        refresh();
        //getch();
        for(unsigned i = 0; i < tribes.size(); ++i)
        {
            threads.erase(threads.begin() + i);
        }
        printw("mark 4\n");
        refresh();
        //getch();

        refresh();
    }

    endwin();

    return 0;
}
