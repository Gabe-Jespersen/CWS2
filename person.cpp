#include <string>
#include <cstdlib>

#include "person.hpp"
#include "util.hpp"

using namespace std;

int person::generateRandom()
{
    //temp
    male = rand()%2;//rng 50/50

    if(male)
    {
        name = "Bob";
        height = gaussian(70,3);//for men, average height is 5'10", stddev is 3"
    }
    else
    {
        name = "Bobbette";
        height = gaussian(65,3);//average height is about 5'5"
    }

    age = rand()%100;//random between 0 and 99
    weight = makeWeight(height, age, male);//estimate based on ideal weight
    intelligence = gaussian(100,15);//iq
    strength = 0;//need to figure in height
    creativity = gaussian(100,10);//felt like it
    charisma = gaussian(100,20);//see above

    return 1; //ISO is retarded
}

int person::generateBased(int toWeight, int toHeight, int toAge, int toInt, int
                          toStr, int toCre, int toChar, bool toMale, string toName)
{
    //just copy what was given
    weight = toWeight;
    height = toHeight;
    age = toAge;
    intelligence = toInt;
    strength = toStr;
    creativity = toCre;
    charisma = toChar;

    male = toMale;

    name = toName;
    
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
int person::getCre()
{
    return creativity;
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
