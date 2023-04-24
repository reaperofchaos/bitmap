#include <cstdint>
#include <fstream>

using namespace std;

class BmpHeader
{
private:
    char bitmapSignatureBytes[2] = {'B', 'M'};
    uint32_t sizeOfBitmapFile = 54 + 786432;
    uint32_t reservedBytes = 0;
    uint32_t pixelDataOffset = 54;

public:
    BmpHeader() {}
    BmpHeader(int32_t height, int32_t width)
    {
        this->sizeOfBitmapFile = 54 + (height * width * 3);
    }
    void save_on_file(std::ofstream &fout);
};