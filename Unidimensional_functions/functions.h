#pragma once

#include <vector>
#include <functional>

using namespace std;

/***** Unidimensional functions *****/
double bisection(function<double(double)> phi, double a, double b, double tol);
double newton_raphson(function<double(double)> phi, double x0, double tol);
double false_position(function<double(double)> phi, double x0, double x1, double tol);
double fibonacci(function<double(double)> phi, double a, double b, int N);
