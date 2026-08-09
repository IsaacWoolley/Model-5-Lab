#include <iostream>
#include <fstream>
#include "Color.h"
#include "pictures.h"
#include "Exceptions.h"

using namespace std;

int main()
{
    string filename;

    cout << "Enter the color file name (<hint> its colors.txt): ";
    cin >> filename;

    ifstream file(filename);

    if (!file)
    {
        try
        {
            throw FileNotFoundException();
        }
        catch (const FileNotFoundException& e)
        {
            cout << e.what() << endl;
            return 1;
        }
    }

    Picture picture(20, 20);

    int x, y, r, g, b;

    while (true)
    {
        if (file >> x >> y >> r >> g >> b)
        {
            if (x < 0 || y < 0)
            {
                try
                {
                    throw CoordinateOutOfRangeException();
                }
                catch (const CoordinateOutOfRangeException& e)
                {
                    cout << e.what()
                        << " X: " << x
                        << " Y: " << y << endl;

                    continue;
                }
            }

            if (r < 0 || r > 255)
            {
                try
                {
                    throw ColorVectorOutOfRangeException("Red", r);
                }
                catch (const ColorVectorOutOfRangeException& e)
                {
                    cout << e.what() << endl;

                    if (r < 0)
                        r = 0;
                    else
                        r = 255;
                }
            }

            if (g < 0 || g > 255)
            {
                try
                {
                    throw ColorVectorOutOfRangeException("Green", g);
                }
                catch (const ColorVectorOutOfRangeException& e)
                {
                    cout << e.what() << endl;

                    if (g < 0)
                        g = 0;
                    else
                        g = 255;
                }
            }

            if (b < 0 || b > 255)
            {
                try
                {
                    throw ColorVectorOutOfRangeException("Blue", b);
                }
                catch (const ColorVectorOutOfRangeException& e)
                {
                    cout << e.what() << endl;

                    if (b < 0)
                        b = 0;
                    else
                        b = 255;
                }
            }

            Color color(r, g, b);

            if (x < picture.getWidth() &&
                y < picture.getHeight())
            {
                picture.setPixel(x, y, color);
            }
        }
        else
        {
            if (file.eof())
            {
                break;
            }

            try
            {
                throw ColorFileFormatException();
            }
            catch (const ColorFileFormatException& e)
            {
                cout << e.what() << endl;
                return 1;
            }
        }
    }

    cout << "\nPicture:\n";
    cout << picture;

    return 0;
}