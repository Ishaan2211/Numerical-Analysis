#include <iostream>
#include <math.h>

using namespace std;

double f(double x) 
{
    return x*x*x - x - 11;
}

int main() 
{
    double a, b, c;
    int max_iterations, iteration = 0;

    cout << "Enter the initial guesses a and b (a < b): ";
    cin >> a >> b;
    cout << "Enter the maximum number of iterations: ";
    cin >> max_iterations;

    if (f(a) * f(b) > 0) 
    {
        cout << "The function does not have opposite signs at the endpoints a and b." << endl;
        return 1;
    }

    while ((b - a) / 2.0 > 0.001 && iteration < max_iterations) 
    {
        c = (a + b) / 2.0;

        if (f(c) == 0.0) 
        {
            break;
        }

        if (f(c) * f(a) < 0) 
        {
            b = c;
        }
        else 
        {
            a = c;
        }

        iteration++;
    }

    cout << "The root of the function is approximately: ";
    cout.precision(3);
    cout << fixed << (a + b) / 2.0 << endl;

    return 0;
}
