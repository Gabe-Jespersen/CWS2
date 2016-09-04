#include <vector>

#include "person.hpp"

#ifndef TRIBE_HPP
#define TRIBE_HPP

class tribe
{
    private:
        std::vector<person> tribesmen;
        int storedFood;
        int birth(void);
        int eat(void);

    public:
        int end(void);
        std::vector<person> getTribesmen(void);
        int getFood(void);
        int forceBirth(void);
        int addFood(int);
};

#endif
