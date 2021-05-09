#pragma once

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

double armijo(function<double(double)> phi, double eps);