#include "imagerw.h"
extern "C" {
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
}

//_CRT_SECURE_NO_WARNINGS SDL CHECK IS OFF IN PROJECT PROPERTIES C/C++/GENERAL

bool load_image(std::vector<unsigned char>& image, const std::string& filename, int& x, int& y)
{
    int n;
    unsigned char* data = stbi_load(filename.c_str(), &x, &y, &n, 3);
    if (data != nullptr)
    {
        image = std::vector<unsigned char>(data, data + x * y * 3);
    }
    stbi_image_free(data);
    return (data != nullptr);
}

Tensor3d<double> getImageValues(std::string filename)
{
    int width, height;
    std::vector<unsigned char> image;
    bool success = load_image(image, filename, width, height);
    if (!success)
    {
        throw std::exception("Error: loading image failed\n");
    }

    const size_t RGB = 3;

    Tensor3d<double> iv(height, width, RGB);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            size_t index = RGB * (y * width + x);
            for (int c = 0; c < RGB; c++) {
                iv(y, x, c) = image[index + c];
            }
        }
    }

    return iv;
}

void normalizeImageValues(Tensor3d<double>& x, double oldMin, double oldMax, double newMin, double newMax) {

    //vozmozhno pridetsa zamenit min na znachenija minimalnie konkretno v tensore
    double oldRange = oldMax - oldMin;
    double newRange = newMax - newMin;

    for (int i = 0; i < x.getX(); i++) {
        for (int j = 0; j < x.getY(); j++) {
            for (int k = 0; k < x.getZ(); k++) {
                double scale = (x(i, j, k) - oldMin) / oldRange;
                x(i, j, k) = newMin + (newRange * scale);
            }
        }
    }
}

void save_jpg_image(Tensor3d<double>& x, std::string filename)
{
    unsigned char data[64 * 64 * 3];

    int w = static_cast<int>(x.getY());
    int h = static_cast<int>(x.getX());
    int c = 3;

    int index = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < c; k++) {
                data[index++] = static_cast<int>(round(x(i, j, k)));
            }
        }
    }

    stbi_write_jpg(filename.c_str(), w, h, c, data, w * c);
}