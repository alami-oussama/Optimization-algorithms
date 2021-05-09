#include "functions.h"
#include "../Algebra/algebra.h"

double false_position(function<double(double)> phi, double x0, double x1, double tol)
{
    double x = x1;
    double x_prev = x0;
    double d;
    while (fabs(x - x_prev) > tol || fabs(derivative_1(phi, x)) > tol)
    {
        d = -derivative_1(phi, x) * (x - x_prev) / (derivative_1(phi, x) - derivative_1(phi, x_prev));
        x_prev = x;
        x = x + d;
    }
    return x;
}