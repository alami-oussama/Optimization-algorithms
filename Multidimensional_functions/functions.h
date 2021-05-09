#pragma once

#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

/***** Multidimensional functions *****/
vector<double> gradient_descent(function<double(vector<double>)> f, vector<double> x0, double tol);
vector<double> unconstrained_gradient_descent(function<double(vector<double>)> f, vector<double> x0, double tol);