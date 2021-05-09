#include "functions.h"
#include "../Algebra/algebra.h"
#include "../Unidimensional_functions/functions.h"
#include "../Backtracking_line_search/functions.h"

// With optimal step size (line search)
vector<double> gradient_descent(function<double(vector<double>)> f, vector<double> x0, double tol)
{
    vector<double> x = x0;
    vector<double> x_prev;
    vector<double> grad;
    double alpha;
    do
    {
        grad = gradient(f, x);
        auto phi = [=](double alpha) { return f(subtract(x, multiply(grad, alpha))); };
        alpha = max(0.0, newton_raphson(phi, 1, tol));
        x_prev = x;
        x = subtract(x, multiply(grad, alpha));
    } while (norm(gradient(f, x)) > tol || norm(subtract(x, x_prev)) > tol);
    return x;
}

// With approach step size (backtracking line search)
vector<double> unconstrained_gradient_descent(function<double(vector<double>)> f, vector<double> x0, double tol)
{
    vector<double> x = x0;
    vector<double> x_prev;
    vector<double> grad;
    double alpha;
    do
    {
        grad = gradient(f, x);
        auto phi = [=](double alpha) { return f(subtract(x, multiply(grad, alpha))); };
        alpha = armijo(phi, 0.2);
        x_prev = x;
        x = subtract(x, multiply(grad, alpha));
    } while (norm(gradient(f, x)) > tol || norm(subtract(x, x_prev)) > tol);
    return x;
}