#include <iostream>
#include <cmath>

using namespace std;

double f(double x) 
{
    return x * x * x - x - 11;
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

    while (iteration < max_iterations) 
    {
        c = b - (f(b) * (b - a)) / (f(b) - f(a));

        if (fabs(f(c)) < 0.001) 
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

    cout.precision(3);
    cout << fixed << "The root of the function is approximately: " << c << endl;

    return 0;
}
