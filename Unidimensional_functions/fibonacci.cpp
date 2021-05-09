#include "functions.h"
#include "../Algebra/algebra.h"

double fibonacci(function<double(double)> phi, double a, double b, int N)
{
    int k = 1;
    while (k <= N)
    {
        double x_left = a + (fibonacci_sequence(N - k) / (double)fibonacci_sequence(N + 2 - k)) * (b - a);
        double x_right = a + (fibonacci_sequence(N + 1 - k) / (double)fibonacci_sequence(N + 2 - k)) * (b - a);
        if (phi(x_left) < phi(x_right))
            b = x_right;
        else if (phi(x_left) > phi(x_right))
            a = x_left;
        else
        {
            a = x_left;
            b = x_right;
            k++;
        }
        k++;
    }
    return a;
}