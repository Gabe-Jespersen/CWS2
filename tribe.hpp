#include <vector>
#include <cmath>

#include "person.hpp"

#ifndef TRIBE_HPP
#define TRIBE_HPP

class tribe
{
    private:
        std::vector<person> tribesmen;
        int number;
        int storedFood = 0;
        int health = 0;
        double technology = std::log(3.5);
        int art = 0;
        int birth(void);
        int eat(void);
        int happiness = 0;
        int age = 0;

    public:
        int end(void);
        std::vector<person> getTribesmen(void) const;
        int getFood(void) const;
        int forceBirth(void);
        int addFood(int);
        std::vector<int> averageStats(void) const;
        int males(void) const;
        double getTech(void) const;
        int hunt(int);
        int forage(int);
        int stdCycle(void);
        int aiCycle(void);
        int killRandom(void);
        int kill(int);
        int create(int);
        int research(int);
        int care(int);
        int setNumber(int);
        int getNumber(void) const;
        int getHappy(void) const;
        int setHappy(int);
        int getAge(void) const;
        int setAge(int);
};

#endif
