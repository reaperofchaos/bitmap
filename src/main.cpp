#include <cstdint>
#include <fstream>
#include "BitmapHeader.h"
#include "BitmapInfoHeader.h"
#include "Pixel.h"

using namespace std;

int main()
{
    ofstream fout("output.bmp", ios::binary);
    BmpHeader *bitmapHeader = new BmpHeader();
    BmpInfoHeader *infoHeader = new BmpInfoHeader();
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