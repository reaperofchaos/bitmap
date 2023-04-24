#include "BitmapHeader.h"

void BmpHeader::save_on_file(std::ofstream &fout)
{
    fout.write(this->bitmapSignatureBytes, 2);
    fout.write((char *)&this->sizeOfBitmapFile, sizeof(uint32_t));
    fout.write((char *)&this->reservedBytes, sizeof(uint32_t));
    fout.write((char *)&this->pixelDataOffset, sizeof(uint32_t));
}