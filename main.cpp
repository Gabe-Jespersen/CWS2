#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "world.hpp"

using namespace std;

int main(int argc, char** argv)
{
    srand(time(NULL));//seeding random

    int worldSize = 50;//size of world, is a square
    vector<vector<int>> world = makeWorld(worldSize);//initializing map

    return 0;
}
