#include <vector>

#include "person.hpp"

#ifndef TRIBE_HPP
#define TRIBE_HPP

class tribe
{
    private:
        std::vector<person> tribesmen;
        int storedFood = 50;
        int technology = 0;
        int birth(void);
        int eat(void);

    public:
        int end(void);
        std::vector<person> getTribesmen(void);
        int getFood(void);
        int forceBirth(void);
        int addFood(int);
        std::vector<int> averageStats(void);
        int males(void);
};

#endif
