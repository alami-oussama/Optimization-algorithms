#include <iostream>
#include <math.h>
#include "Algebra/algebra.h"
#include "Unidimensional_functions/functions.h"
#include "Multidimensional_functions/functions.h"

using namespace std;

/* Example of unidimensional functionn */
double
phi(double alpha)
{
    return pow(alpha, 3) + 3 * pow(alpha, 2) - 1;
}

/* Example of multidimensional functionn */
double f(vector<double> x)
{
    return 0.5 * (pow(x[0], 2) + pow(x[1], 2)) + 0.5 * x[0] - x[1];
}

int main()
{
    vector<double> x;
    x.push_back(2.0);
    x.push_back(1.0);
    vector<double> y;
    y.push_back(1.0);
    y.push_back(5.0);
    vector<double> result = multiply(x, -1);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
}