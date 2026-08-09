#include <iostream>
#include <string>
#include "eaterOf.h"

using namespace std;

int main()
{
    EaterOf<int> intEater;
    EaterOf<double> doubleEater;
    EaterOf<string> stringEater;


    intEater.eat(5);
    intEater.eat(10);
    intEater.eat(15);

    cout << "Integer burp: " << intEater.burp() << endl;

    cout << endl;

    doubleEater.eat(5.5);
    doubleEater.eat(10.25);
    doubleEater.eat(15);

    cout << "Double burp: " << doubleEater.burp() << endl;

    cout << endl;

    
    stringEater.eat("Drake ");
    stringEater.eat("Maye ");
    stringEater.eat("Is My Hero");

    cout << "String burp: " << stringEater.burp() << endl;

    return 0;
}