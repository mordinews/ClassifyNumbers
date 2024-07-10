#include "CGenerateNumbers.h"




void CGenerateNumbers::genrateNumbers(int size, vector <unsigned int>& Numbers)
{

    //selects X random numbers(between 1 - 999)

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib(1, 999);

    //file vector
    for (int n = 0; n < size ; n++)
    {
        Numbers.insert(Numbers.begin() + n, distrib(gen));
    }


}
