#include <cstdint>
#include <fstream>

using namespace std;

class BmpInfoHeader
{
private:
    uint32_t sizeOfThisHeader = 40;
    int32_t width = 512;
    int32_t height = 512;
    uint16_t numberOfColorPlanes = 1;
    uint16_t colorDepth = 24;
    uint32_t compressionMethod = 0;
    uint32_t rawBitmapDataSize = 0;
    int32_t horizontalResolution = 3780;
    int32_t verticalResolution = 3780;
    uint32_t colorTableEntries = 0;
    uint32_t importantColors = 0;

public:
    void save_on_file(std::ofstream &fout);
    int32_t getWidth() { return this->width; };
    int32_t getHeight() { return this->height; };
};