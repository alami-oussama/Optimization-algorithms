#include "algebra.h"

/***** Vector norm *****/
double norm(vector<double> x)
{
    double norm;
    double sum = 0;
    for (int i = 0; i < x.size(); i++)
        sum += pow(x[i], 2);
    norm = sqrt(sum);
    return norm;
}

/***** Sum of two vectors *****/
vector<double> sum(vector<double> x, vector<double> y)
{
    vector<double> result;
    for (int i = 0; i < x.size(); i++)
        result.push_back(x[i] + y[i]);
    return result;
}

/***** Subtraction of two vectors *****/
vector<double> subtract(vector<double> x, vector<double> y)
{
    vector<double> result;
    for (int i = 0; i < x.size(); i++)
        result.push_back(x[i] - y[i]);
    return result;
}

/***** Multiply a vector by a real number *****/
vector<double> multiply(vector<double> x, double number)
{
    vector<double> result;
    for (int i = 0; i < x.size(); i++)
        result.push_back(x[i] * number);
    return result;
}

/***** Gradient of a function *****/
vector<double> gradient(function<double(vector<double>)> f, vector<double> x)
{
    double eps = 0.000001;
    vector<double> result;
    for (int i = 0; i < x.size(); i++)
    {
        vector<double> y_1 = x;
        vector<double> y_0 = x;
        y_1[i] = x[i] + eps;
        y_0[i] = x[i] - eps;
        result.push_back((f(y_1) - f(y_0)) / (2 * eps));
    }
    return result;
}

/***** First-order derivative *****/
double derivative_1(function<double(double)> f, double x)
{
    double eps = 0.000001;
    double result = (f(x + eps) - f(x - eps)) / (2 * eps);
    return result;
}

/***** second-order derivative *****/
double derivative_2(function<double(double)> f, double x)
{
    double eps = 0.000001;
    double result = (derivative_1(f, x + eps) - derivative_1(f, x - eps)) / (2 * eps);
    return result;
}

/***** Fibonacci sequence *****/
int fibonacci_sequence(int n)
{
    int f_2 = 1;
    int f_1 = 1;
    int f = 1;
    for (int i = 2; i <= n; i++)
    {
        f = f_1 + f_2;
        f_2 = f_1;
        f_1 = f;
    }
    return f;
}