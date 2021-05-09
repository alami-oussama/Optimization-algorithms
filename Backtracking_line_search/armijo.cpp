#include "functions.h"
#include "../Algebra/algebra.h"

double armijo(function<double(double)> phi, double eps)
{
    double alpha = 1;
    while (phi(alpha) <= phi(0) + eps * derivative_1(phi, 0))
        alpha = 2 * alpha;

    while (phi(alpha) > phi(0) + eps * derivative_1(phi, 0))
        alpha = alpha / 2;

    return alpha;
}