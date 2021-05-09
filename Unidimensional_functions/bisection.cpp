#include "functions.h"
#include "../Algebra/algebra.h"

double bisection(function<double(double)> phi, double a, double b, double tol)
{
    double c;
    do
    {
        c = (a + b) / 2;
        if (derivative_1(phi, c) * derivative_1(phi, b) <= 0)
        {
            if (derivative_1(phi, c) == 0 && derivative_2(phi, c) > 0)
                break;
            a = c;
        }
        else
            b = c;
    } while (fabs(b - a) > tol);
    return c;
}