#include "factors.h"

int findLowestFactor(int num)
{
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return i;
        }
    }

    return 0;
}

std::vector<int> getFactors(int num)
{
    std::vector<int> factors;

    // Base case
    if (num <= 1)
    {
        return factors;
    }

    int lowestFactor = findLowestFactor(num);

    // No factor means num itself is prime
    if (lowestFactor == 0)
    {
        factors.push_back(num);
        return factors;
    }

    // Add the lowest factor
    factors.push_back(lowestFactor);

    // Recursively find factors of the remaining number
    std::vector<int> remainingFactors =
        getFactors(num / lowestFactor);

    // Add remaining factors
    for (int factor : remainingFactors)
    {
        factors.push_back(factor);
    }

    return factors;
}