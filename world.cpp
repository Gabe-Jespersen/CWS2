#include <vector>
#include <cstdlib>

#include "world.hpp"

using namespace std;

vector<vector<int>> makeWorld(int worldSize)
{
    vector<vector<int>> worldMap;//temporary storage for return

    for(int i = 0; i < worldSize; ++i)//vertical
    {
        worldMap.push_back({});

        for(int j = 0; j < worldSize; ++j)//horizontal
        {
            worldMap.at(i).push_back(rand()%2);//just random whether land or not
        }
    }

    return worldMap;
}
