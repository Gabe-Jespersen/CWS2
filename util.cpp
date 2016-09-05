#include <cmath>
#include <cstdlib>

#include "util.hpp"

using namespace std;

double gaussian(int base, int standardDeviation)
{
    //uses box-muller transformation or something
    double u1 = (1.0+rand())/(1.0+RAND_MAX);//generating 2 linearly random numbers between 1 & 0
    double u2 = (1.0+rand())/(1.0+RAND_MAX);

    double answer = cos(8.0*atan(1.0)*u2)*sqrt(-2.0*log(u1));//uses the box- 
                                                             //muller transfor-
                                                             //mation
                                                             //
                                                             //using decimals 
                                                             //to force it to
                                                             //be a float
                                                             //
                                                             //you could also
                                                             //use a pi int
    answer *= standardDeviation;//multiplies the value by the standard deviation
    answer += base;//adds the base
    return answer;
}

int makeWeight(int height, int age, bool male)
{
    int idealWeight = 100 + (5.1 * (height-60));//Devine formula
    int realWeight;

    if(male)
    {
        idealWeight += 10;
    }

    do
    {
        realWeight = gaussian(idealWeight, idealWeight/10);
    }
    while(realWeight < idealWeight * 0.5);

    return realWeight;
}
