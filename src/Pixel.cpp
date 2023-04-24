#include "Pixel.h"

void Pixel::save_on_file(std::ofstream &fout)
{
    fout.write((char *)&this->blue, sizeof(uint8_t));
    fout.write((char *)&this->green, sizeof(uint8_t));
    fout.write((char *)&this->red, sizeof(uint8_t));
}