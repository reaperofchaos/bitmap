#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include "BitmapHeader.h"
#include "BitmapInfoHeader.h"
#include "Pixel.h"

using namespace std;

int main(int argc, char *argv[])
{

    int height = -1;
    int width = -1;
    int dpi = -1;
    std::cout << "argc" << argc << "\n";

    if (argc > 2)
    {
        std::cout << "1 " << argv[1] << "\n";
        std::cout << "2 " << argv[2] << "\n";

        char *p;
        height = std::strtol(argv[1], &p, 10);
        std::cout << "height " << height << "\n";

        width = std::strtol(argv[2], &p, 10);
        std::cout << "width " << width << "\n";

        if (argc > 3)
        {
            dpi = std::strtol(argv[3], &p, 10);
            std::cout << "dpi " << dpi << "\n";
        }
    }

    ofstream fout("output.bmp", ios::binary);
    BmpHeader *bitmapHeader = new BmpHeader();
    BitmapInfoHeader *infoHeader = new BitmapInfoHeader();

    if (dpi != -1)
    {
        bitmapHeader = new BmpHeader(height, width);
        infoHeader = new BitmapInfoHeader(height, width, dpi);
    }
    else if (height != -1 && width != -1)
    {
        bitmapHeader = new BmpHeader(height, width);
        infoHeader = new BitmapInfoHeader(height, width);
    }

    Pixel *pixel = new Pixel();
    Pixel *otherPixel = new Pixel(0, 0, 255);
    bitmapHeader->save_on_file(fout);
    infoHeader->save_on_file(fout);

    // writing pixel data
    int numberOfPixels = infoHeader->getWidth() * infoHeader->getHeight();
    for (int i = 0; i < numberOfPixels; i++)
    {
        if (i % 32 == 0)
        {
            int a = 0;
            while (a <= 16)
            {
                pixel->save_on_file(fout);
                a++;
                i++;
            }
        }
        else
        {
            int a = 0;
            while (a <= 16)
            {
                otherPixel->save_on_file(fout);
                a++;
                i++;
            }
        }
    }

    fout.close();
}