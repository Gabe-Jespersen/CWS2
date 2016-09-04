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
