#include <iostream>
#include <cmath>

using namespace std;

double f(double x) 
{
    return x * x * x - x - 11;
}

double f_derivative(double x) 
{
    return 3 * x * x - 1;
}

int main() 
{
    double a, c;
    int max_iterations, iteration = 0;

    cout << "Enter the initial guess a: ";
    cin >> a;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iterations;

    while (iteration < max_iterations) 
    {
        c = a - f(a) / f_derivative(a);

        if (fabs(f(c)) < 0.001) 
        {
            break;
        }

        a = c;

        iteration++;
    }

    cout.precision(5);
    cout << fixed << "The root of the function is approximately: " << c << endl;

    return 0;
}
