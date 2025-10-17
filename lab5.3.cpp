#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// функція f(x)
double f(double x) {
    if (abs(x) >= 1) {
        return cos(x / 2) / (1 + sin(x) * sin(x));
    }
    else {
        double S = 1;      // перший член ряду
        double a = 1;      // поточний член
        for (int i = 1; i <= 6; i++) {
            a *= x * x * x / (2 * i * (2 * i - 1) * (2 * i - 2)); // рекурентне співвідношення
            S += a;
        }
        return S;
    }
}

int main() {
    double y_start, y_end;
    int n;

    cout << "y_start = "; cin >> y_start;
    cout << "y_end = "; cin >> y_end;
    cout << "n = "; cin >> n;

    double dy = (y_end - y_start) / n;

    cout << fixed << setprecision(6);
    cout << "-----------------------------\n";
    cout << "|    y    |     F(y)        |\n";
    cout << "-----------------------------\n";

    for (int i = 0; i <= n; i++) {
        double y = y_start + i * dy;
        double value = f(1 + y * y) + pow(f(1) + pow(f(y * y), 2), 2);
        cout << "| " << setw(7) << y << " | " << setw(14) << value << " |\n";
    }

    cout << "-----------------------------\n";

    return 0;
}