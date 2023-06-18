#include "imagerw.h"
extern "C" {
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
}

//_CRT_SECURE_NO_WARNINGS SDL CHECK IS OFF IN PROJECT PROPERTIES C/C++/GENERAL

void ImageProcessing::getImageValues(Tensor3d<double>& ix, std::wstring wfilename)
{
    int width, height;
    std::vector<unsigned char> image;
    int n;
    CStringA filename(wfilename.c_str());
    unsigned char* data = stbi_load(filename, &width, &height, &n, 3);
    if (data != nullptr)
    {
        image = std::vector<unsigned char>(data, data + width * height * 3);
    }
    stbi_image_free(data);

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

    ix = iv;
}

void ImageProcessing::normalizeImageValues(Tensor3d<double>& x, double oldMin, double oldMax, double newMin, double newMax) {

    /*double oldRange = oldMax - oldMin;
    double newRange = newMax - newMin;*/

    /*int minValue = INT_MAX;
    for (size_t i = 0; i < x.getX(); ++i) {
        for (size_t j = 0; j < x.getY(); ++j) {
            for (size_t k = 0; k < x.getZ(); ++k) {
                if (x(i,j,k) < minValue) {
                    minValue = x(i, j, k);
                }
            }
        }
    }

    int maxValue = INT_MIN;
    for (size_t i = 0; i < x.getX(); ++i) {
        for (size_t j = 0; j < x.getY(); ++j) {
            for (size_t k = 0; k < x.getZ(); ++k) {
                if (x(i, j, k) > maxValue) {
                    maxValue = x(i, j, k);
                }
            }
        }
    }

    oldMin = minValue;
    oldMax = maxValue;*/
    for (int i = 0; i < x.getX(); i++) {
        for (int j = 0; j < x.getY(); j++) {
            for (int k = 0; k < x.getZ(); k++) {
                /*double scale = (x(i, j, k) - oldMin) / oldRange;
                x(i, j, k) = newMin + (newRange * scale);*/
                x(i, j, k) = (x(i, j, k) - oldMin) * ((newMax - newMin) / (oldMax - oldMin)) + newMin;
            }
        }
    }
}

void ImageProcessing::save_jpg_image(Tensor3d<double>& x, std::wstring wfilename)
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

    CStringA filename(wfilename.c_str());
    stbi_write_jpg(filename, w, h, c, data, w * c);
}

void ImageProcessing::save_png_image(Tensor3d<double>& x, std::wstring wfilename)
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

    CStringA filename(wfilename.c_str());
    stbi_write_png(filename, w, h, c, data, 32);
}

void ImageProcessing::save_bmp_image(Tensor3d<double>& x, std::wstring wfilename)
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

    CStringA filename(wfilename.c_str());
    stbi_write_bmp(filename, w, h, c, data);
}