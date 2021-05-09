#pragma once

#include <vector>
#include <math.h>
#include <functional>

using namespace std;

/***** Algebra functions *****/
double norm(vector<double> x);
vector<double> sum(vector<double> x, vector<double> y);
vector<double> subtract(vector<double> x, vector<double> y);
vector<double> multiply(vector<double> x, double number);
vector<double> gradient(function<double(vector<double>)> f, vector<double> x);
/***** General mathematical functions *****/
int fibonacci_sequence(int n);
double derivative_1(function<double(double)> f, double x);
double derivative_2(function<double(double)> f, double x);