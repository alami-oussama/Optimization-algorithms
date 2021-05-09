#include "functions.h"
#include "../Algebra/algebra.h"

double newton_raphson(function<double(double)> phi, double x0, double tol)
{
    double x = x0;
    double x_prev;
    double d;
    do
    {
        d = -derivative_1(phi, x) / derivative_2(phi, x);
        x_prev = x;
        x = x + d;
    } while (fabs(x - x_prev) > tol || fabs(derivative_1(phi, x)) > tol);
    return x;
}