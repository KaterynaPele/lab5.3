#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f(const double x);

int main()
{
    double y_start, y_end;
    int n;

    cout << "y_start = "; cin >> y_start;
    cout << "y_end = "; cin >> y_end;
    cout << "n  = "; cin >> n;

    double dy = (y_end - y_start) / n;
    double y = y_start;

    cout << fixed << setprecision(6);
    cout << setw(10) << "y" << setw(20) << "F(y)" << endl;
    cout << string(30, '-') << endl;

    while (y <= y_end)
    {
        double value = f(1 + y * y) + pow(f(1) + pow(f(y * y), 2), 2);
        cout << setw(10) << y << setw(20) << value << endl;
        y += dy;
    }

    return 0;
}

double f(const double x)
{
    if (abs(x) >= 1)
        return cos(x / 2) / (1 + sin(x) * sin(x));
    else
    {
        double S = 1;
        double a = 1;
        int i = 1;

        do
        {
            a *= x * x * x / (2 * i * (2 * i - 1) * (2 * i - 2));
            S += a;
            i++;
        } while (i <= 6);

        return S;
    }
}
