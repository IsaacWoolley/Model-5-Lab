#include <iostream>
#include <vector>
#include "factors.h"

using namespace std;

int main()
{
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    if (number <= 1)
    {
        cout << "Please enter an integer greater than 1." << endl;
        return 1;
    }

    vector<int> factors = getFactors(number);

    cout << "Prime factors: ";

    for (int factor : factors)
    {
        cout << factor << " ";
    }

    cout << endl;

    return 0;
}