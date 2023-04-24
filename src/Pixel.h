#include <cstdint>
#include <fstream>

using namespace std;

class Pixel
{
private:
    uint8_t blue = 255;
    uint8_t green = 0;
    uint8_t red = 0;

public:
    Pixel() {}
    Pixel(uint8_t blue, uint8_t green, uint8_t red)
    {
        this->blue = blue;
        this->green = green;
        this->red = red;
    }
    void save_on_file(std::ofstream &fout);
};