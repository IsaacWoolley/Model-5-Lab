#pragma once

#include <vector>
#include <iostream>
#include "Color.h"

class Picture
{
private:
    std::vector<std::vector<Color>> pixels;

    int width;
    int height;

public:
    Picture(int w, int h);

    void setPixel(int x, int y, Color c);

    int getWidth() const;
    int getHeight() const;

    friend std::ostream& operator<<(std::ostream& out,
        const Picture& picture);
};