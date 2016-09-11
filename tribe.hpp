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
        double technology = std::sqrt(10);
        int art = 0;
        int birth(void);
        int eat(void);

    public:
        int end(void);
        std::vector<person> getTribesmen(void) const;
        int getFood(void) const;
        int forceBirth(void);
        int addFood(int);
        std::vector<int> averageStats(void) const;
        int males(void) const;
        int getTech(void) const;
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
};

#endif
