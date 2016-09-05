#include <vector>

#include "tribe.hpp"
#include "person.hpp"

using namespace std;

int tribe::birth()
{
    //temp
    person temp;
    temp.generateRandom();
    tribesmen.push_back(temp);
    return 1;
}

int tribe::eat()
{
    storedFood -= tribesmen.size();
    return 1;
}


int tribe::end()
{
    storedFood = tribesmen.size() * -10;
    return 1;
}

vector<person> tribe::getTribesmen()
{
    return tribesmen;
}

int tribe::getFood()
{
    return storedFood;
}

int tribe::forceBirth()
{
    birth();
    return 1;
}

int tribe::addFood(int toAdd)
{
    storedFood += toAdd;
    return 1;
}

vector<int> tribe::averageStats()
{
    vector<int> temporaryStats;

    temporaryStats.push_back(0);//weight
    temporaryStats.push_back(0);//height
    temporaryStats.push_back(0);//age
    temporaryStats.push_back(0);//intelligence
    temporaryStats.push_back(0);//strength
    temporaryStats.push_back(0);//creativity
    temporaryStats.push_back(0);//charisma

    for(int i = 0; i < tribesmen.size(); ++i)
    {
        temporaryStats.at(0) += tribesmen.at(i).getWeight();
        temporaryStats.at(1) += tribesmen.at(i).getHeight();
        temporaryStats.at(2) += tribesmen.at(i).getAge();
        temporaryStats.at(3) += tribesmen.at(i).getInt();
        temporaryStats.at(4) += tribesmen.at(i).getStr();
        temporaryStats.at(5) += tribesmen.at(i).getCre();
        temporaryStats.at(6) += tribesmen.at(i).getChar();
    }

    for(int i = 0; i < temporaryStats.size(); ++i)
    {
        temporaryStats.at(i) /= tribesmen.size();//divide by population
    }
    
    return temporaryStats;
}

int tribe::males()
{
    int temp = 0;

    for(int i = 0; i < tribesmen.size(); ++i)
    {
        if(tribesmen.at(i).isMale())
        {
            temp++;//add one per male
        }
    }

    return temp;
}
