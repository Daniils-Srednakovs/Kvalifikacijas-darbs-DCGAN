#pragma once
#include <iostream>
#include <vector>
#include <filesystem>
#include <atlstr.h>
#include "tensor.h"

namespace ImageProcessing {
	void getImageValues(Tensor3d<double>& ix, std::wstring wfilename);
	void normalizeImageValues(Tensor3d<double>& x, double oldMin = 0, double oldMax = 255, double newMin = -1, double newMax = 1);
	void save_jpg_image(Tensor3d<double>& x, std::wstring filename);
	void save_png_image(Tensor3d<double>& x, std::wstring filename);
	void save_bmp_image(Tensor3d<double>& x, std::wstring filename);
}