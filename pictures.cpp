#include "pictures.h"

Picture::Picture(int w, int h)
{
    width = w;
    height = h;

    // Fill picture with white
    pixels.resize(height, std::vector<Color>(width, Color(255, 255, 255)));
}

void Picture::setPixel(int x, int y, Color c)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        pixels[y][x] = c;
    }
}

int Picture::getWidth() const
{
    return width;
}

int Picture::getHeight() const
{
    return height;
}

std::ostream& operator<<(std::ostream& out,
    const Picture& picture)
{
    for (int y = 0; y < picture.height; y++)
    {
        for (int x = 0; x < picture.width; x++)
        {
            out << picture.pixels[y][x];
        }

        out << '\n';
    }

    return out;
}