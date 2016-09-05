#include <vector>
#include <cstdlib>
#include <ctime>

#include "tribe.hpp"

using namespace std;

int main(int argc, char** argv)
{
    srand(time(NULL));//seeding random

    tribe alpha;//making
    tribe beta; //three
    tribe cappa;//tribes

    for(int i = 0; i < 100; i++)
    {
        alpha.forceBirth();
    }
    for(int i = 0; i < 100; i++)
    {
        beta.forceBirth();
    }
    for(int i = 0; i < 100; i++)
    {
        cappa.forceBirth();
    }

    return 0;
}
