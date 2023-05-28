#pragma once
#include <iostream>
#include <vector>
#include <filesystem>
#include "tensor.h"


Tensor3d<double> getImageValues(std::string filename);
void normalizeImageValues(Tensor3d<double>& x, double oldMin = 0, double oldMax = 255, double newMin = -1, double newMax = 1);
void save_jpg_image(Tensor3d<double>& x, std::string filename);