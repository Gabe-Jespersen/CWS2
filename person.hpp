#include <string>

#ifndef PERSON_HPP
#define PERSON_HPP

class person
{
    private:
        int weight, height, age, intelligence, strength, creativity, charisma;
        bool male;
        std::string name;

    public:
        int generateRandom();
        int generateBased(int,int,int,int,int,int,int,bool,std::string);
        int getWeight(void);
        int getHeight(void);
        int getAge(void);
        int getInt(void);
        int getStr(void);
        int getCre(void);
        int getChar(void);
        bool isMale(void);
        std::string getName(void);
        int setAge(int);
        int makeOlder(void);
};

#endif
