#include <iostream>
#include <math.h>

using namespace std;

#define f1(y, z)  (17 - y + 2 * z) / 20
#define f2(x, z)  (-18 - 3 * x + z) / 20
#define f3(x, y)  (25 - 2 * x + 3 * y) / 20

int main() 
{
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    int count = 1;

    cout << "Enter tolerable error: ";
    cin >> e;

    cout << "\nCount\tx\ty\tz\n";

    do {
        x1 = f1(y0, z0);
        y1 = f2(x1, z0);
        z1 = f3(x1, y1);

        cout << count << "\t" << fixed;
        cout.precision(4);
        cout << x1 << "\t" << y1 << "\t" << z1 << "\n";

        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);

        count++;
        x0 = x1;
        y0 = y1;
        z0 = z1;

    } while (e1 > e && e2 > e && e3 > e);

    cout.precision(4);
    cout << "\nSolution: x = " << x1 << ", y = " << y1 << ", z = " << z1 << endl;

    return 0;
}
