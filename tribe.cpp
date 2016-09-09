#include <vector>
#include <cmath>
#include <cstdlib>

#include "tribe.hpp"
#include "person.hpp"
#include "util.hpp"

using namespace std;

int tribe::birth()
{
    //temp
    person temp;
    temp.generateRandom();
    temp.setAge(0);
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
    tribesmen.clear();
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

    for(unsigned i = 0; i < tribesmen.size(); ++i)//unsigned to eliminate warn
    {
        temporaryStats.at(0) += tribesmen.at(i).getWeight();
        temporaryStats.at(1) += tribesmen.at(i).getHeight();
        temporaryStats.at(2) += tribesmen.at(i).getAge();
        temporaryStats.at(3) += tribesmen.at(i).getInt();
        temporaryStats.at(4) += tribesmen.at(i).getStr();
        temporaryStats.at(5) += tribesmen.at(i).getCre();
        temporaryStats.at(6) += tribesmen.at(i).getChar();
    }

    for(unsigned i = 0; i < temporaryStats.size(); ++i)//unsigned to stop warn
    {
        temporaryStats.at(i) /= tribesmen.size();//divide by population
    }
    
    return temporaryStats;
}

int tribe::males()
{
    int temp = 0;

    for(unsigned i = 0; i < tribesmen.size(); ++i)//unsigned to remove warn
    {
        if(tribesmen.at(i).isMale())
        {
            temp++;//add one per male
        }
    }

    return temp;
}

int tribe::getTech()
{
    return technology;
}

int tribe::hunt(int hunters)
{
    storedFood += (1 + (technology * 0.1)) * gaussian((hunters * 0.8) + (hunters * technology * 0.15), log(hunters));
    return 1;
}

int tribe::forage(int foragers)
{
    storedFood += foragers;
    return 1;
}

int tribe::stdCycle()
{
    //eating
    double toEat = 0;
    for(unsigned i = 0; i < tribesmen.size(); ++i)//unsigned to end warn
    {
        if((tribesmen.at(i).isMale() && tribesmen.at(i).getAge() >= 20) ||
          (!tribesmen.at(i).isMale() && tribesmen.at(i).getAge() >= 16)) //is grown
        {
            toEat++;
        }
        else
        {
            if(tribesmen.at(i).isMale())
            {
                toEat += tribesmen.at(i).getWeight() / 100;
            }
            else
            {
                toEat += 0.8 * (tribesmen.at(i).getWeight() / 100);
            }
        }
    }
    storedFood -= toEat;
    while(storedFood < 0)
    {
        if(tribesmen.size() > 0)
        {
            killRandom();
        }
        storedFood++;
    }

    //aging
    for(unsigned i = 0; i < tribesmen.size(); ++i)
    {
        tribesmen.at(i).makeOlder();
    }

    //mating
    for(unsigned i = 0; i < tribesmen.size(); ++i)
    {
        if(tribesmen.at(i).isMale() && tribesmen.at(i).getAge() > 16 &&
                                       tribesmen.at(i).getAge() < 40)
        {
            for(unsigned j = 0; j < tribesmen.size(); ++j)
            {
                if(!tribesmen.at(j).isMale() && tribesmen.at(j).getAge() > 16 && 
                                                tribesmen.at(j).getAge() < 40 &&
                                                rand() % 1 == 0)
                                                //math is hard
                {
                    birth();
                }
            }
            break;
        }
    }

    //dying
    //temp
    for(unsigned i = 0; i < tribesmen.size(); ++i)
    {
        if(rand()%((health/10000)+20+(3*int(log(technology/10))))==0)
        {
            killRandom();
        }
    }

    return 1;
}

int tribe::killRandom()
{
    if(tribesmen.size() == 0)
    {
        return 1;
    }
    int toKill = rand() % tribesmen.size();
    tribesmen.erase(tribesmen.begin() + toKill);
    return 1;
}

int tribe::kill(int toKill)
{
    if(tribesmen.size() == 0)
    {
        return 1;
    }
    tribesmen.erase(tribesmen.begin() + toKill);
    return 1;
}

int tribe::aiCycle()
{
    vector<person> toForage;
    vector<person> toHunt;
    vector<person> toCare;
    vector<person> toResearch;
    vector<person> toCreate;

    for(unsigned i = 0; i < tribesmen.size(); ++i)
    {
        int skill = tribesmen.at(i).getInt() / 20;
        {
            if(tribesmen.at(i).getCre() > 150)
            {
                toCreate.push_back(tribesmen.at(i));
            }
            else if(skill > 7)
            {
                toResearch.push_back(tribesmen.at(i));
            }
            else if(skill > 4 && !tribesmen.at(i).isMale() && rand() % 4 == 0)
            {
                toCare.push_back(tribesmen.at(i));
            }
            else if(skill > 3 && tribesmen.at(i).isMale())
            {
                toHunt.push_back(tribesmen.at(i));
            }
            else
            {
                toForage.push_back(tribesmen.at(i));
            }
        }
    }
    
    forage(toForage.size());
    for(unsigned i = 0; i < toForage.size(); ++i)
    {
        if(toForage.at(i).getHeight() > 72)
        {
            storedFood++;//bonus for tall foragers
        }
    }

    if(storedFood < 5 * tribesmen.size())
    {
        hunt(toHunt.size());
        for(unsigned i = 0; i < toHunt.size(); ++i)
        {
            if(toHunt.at(i).getStr() < 80)
            {
                killRandom();//if people are weak and hunt, others die
            }
        }
    }
    else
    {
    }


    create(toCreate.size());

    research(toResearch.size());

    care(toCare.size());

    return 1;
}

int tribe::create(int people)
{
    art += people/10;
    return 1;
}
int tribe::research(int researchers)
{
    for(int i = 0; i < researchers; ++i)
    {
        if(rand() % 10 == 0)
        {
            technology += researchers;
        }
    }
    return 1;
}
int tribe::care(int toCare)
{
    health += toCare;
    return 1;
}
int tribe::setNumber(int toSet)
{
    number = toSet;
    return 1;
}
int tribe::getNumber()
{
    return number;
}
