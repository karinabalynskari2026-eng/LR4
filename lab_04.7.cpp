#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(7)  << "x"          << "   |"
                << setw(12) << "ln((x+1)/(x-1))" << " |"
                << setw(10) << "S"          << "   |"
                << setw(5)  << "n"          << "   |"
                << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        n = 0;
        a = 1 / x;                      // перший доданок: 1/x
        S = a;
        do {
            n++;
            R = (2.0 * n - 1) / ((2.0 * n + 1) * x * x);   // рекурентне співвідношення
            a *= R;
            S += a;
        } while (fabs(a) >= eps);

        S *= 2;                          // ряд множиться на 2

        cout << "|" << setw(7)  << setprecision(2) << x                    << "   |"
                    << setw(15) << setprecision(5) << log((x + 1) / (x - 1)) << " |"
                    << setw(10) << setprecision(5) << S                    << "   |"
                    << setw(5)  << n                                       << "   |"
                    << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;

    return 0;
}