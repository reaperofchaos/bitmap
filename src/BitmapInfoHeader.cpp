#include "BitmapInfoHeader.h"

void BitmapInfoHeader::save_on_file(std::ofstream &fout)
{
    fout.write((char *)&this->sizeOfThisHeader, sizeof(uint32_t));
    fout.write((char *)&this->width, sizeof(int32_t));
    fout.write((char *)&this->height, sizeof(int32_t));
    fout.write((char *)&this->numberOfColorPlanes, sizeof(uint16_t));
    fout.write((char *)&this->colorDepth, sizeof(uint16_t));
    fout.write((char *)&this->compressionMethod, sizeof(uint32_t));
    fout.write((char *)&this->rawBitmapDataSize, sizeof(uint32_t));
    fout.write((char *)&this->horizontalResolution, sizeof(int32_t));
    fout.write((char *)&this->verticalResolution, sizeof(int32_t));
    fout.write((char *)&this->colorTableEntries, sizeof(uint32_t));
    fout.write((char *)&this->importantColors, sizeof(uint32_t));
}