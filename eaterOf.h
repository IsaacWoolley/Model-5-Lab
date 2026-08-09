#pragma once

#include <iostream>
#include <string>

using namespace std;

class NotEdibleException : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Not edible!";
    }
};

template <typename T>
class EaterOf
{
private:
    T sum;

public:
    EaterOf()
    {
        sum = T();
    }

    void eat(T food)
    {
        cout << "nom-nom" << endl;

        try
        {
            sum = sum + food;
        }
        catch (...)
        {
            throw NotEdibleException();
        }
    }

    T burp()
    {
        return sum;
    }
};