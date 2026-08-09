#include "Color.h"

Color::Color()
{
    red = 255;
    green = 255;
    blue = 255;
}

Color::Color(int r, int g, int b)
{
    red = r;
    green = g;
    blue = b;
}

int Color::getRed() const
{
    return red;
}

int Color::getGreen() const
{
    return green;
}

int Color::getBlue() const
{
    return blue;
}

std::ostream& operator<<(std::ostream& out, const Color& color)
{
    int r = color.red;
    int g = color.green;
    int b = color.blue;

    
    if (r == g && g == b)
    {
        if (r > 250)
            out << 'W';
        else if (r < 50)
            out << 'D';
        else
            out << 'G';
    }
  
    else if (r == b && r > g)
    {
        out << 'P';
    }
    
    else if (r == g && r > b)
    {
        out << 'Y';
    }
    
    else if (b == g && b > r)
    {
        out << 'T';
    }

    else if (r > g && r > b)
    {
        out << 'R';
    }
    else if (g > r && g > b)
    {
        out << 'V';
    }
   
    else
    {
        out << 'B';
    }

    return out;
}