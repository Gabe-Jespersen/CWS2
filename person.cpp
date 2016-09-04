#include <string>
#include <cstdlib>

#include "person.hpp"
#include "util.hpp"

using namespace std;

int person::generateRandom()
{
    //temp
    bool male = rand()%2;

    if(male)
    {
        string name = "Bob";
        int height = gaussian(3,70);
    }
    else
    {
        string name = "Bobbette";
    }

    int age = rand()%100;
    int weight = 0;
    int intelligence = 0;
    int strength = 0;
    int creativity = 0;
    int charisma = 0;

    return 1; //ISO is retarded
}

int person::generateBased(int toWeight, int toHeight, int toAge, int toInt, int
                          toStr, int toCre, int toChar, bool toMale, string toName)
{
    int weight = toWeight;
    int height = toHeight;
    int age = toAge;
    int intelligence = toInt;
    int strength = toStr;
    int creativity = toCre;
    int charisma = toChar;

    bool male = toMale;

    string name = toName;
    
    return 1; //ISO is retarded
}

int person::getWeight()
{
    return weight;
}
int person::getHeight()
{
    return height;
}
int person::getAge()
{
    return age;
}
int person::getInt()
{
    return intelligence;
}
int person::getStr()
{
    return strength;
}
int person::getChar()
{
    return charisma;
}
bool person::isMale()
{
    return male;
}
string person::getName()
{
    return name;
}
