// Lab_03.2.cpp
// Балинська Каріна
// Розгалуження, задане формулою: функція з параметрами.
// Варіант 1

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp; // початок інтервалу X_поч
    double xk; // кінець інтервалу X_кін
    double dx; // крок
    double x;  // вхідний аргумент
    double a;  // вхідний параметр
    double b;  // вхідний параметр
    double c;  // вхідний параметр
    double F1; // результат обчислення виразу (спосіб 1)
    double F2; // результат обчислення виразу (спосіб 2)

    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    cout << "c = "; cin >> c;

    cout << "X_поч = "; cin >> xp;
    cout << "X_кін = "; cin >> xk;
    cout << "dX = ";    cin >> dx;

    if (dx <= 0)
    {
        cout << "Крок dX має бути додатним!" << endl;
        return 1;
    }

    // кількість кроків (щоб не накопичувалась похибка при додаванні dx)
    int n = (int)floor((xk - xp) / dx + 1e-9);

    cout << endl;
    cout << "+------------+----------------+----------------+" << endl;
    cout << "|     x      |   F (спосіб 1) |   F (спосіб 2) |" << endl;
    cout << "+------------+----------------+----------------+" << endl;

    for (int i = 0; i <= n; i++)
    {
        x = xp + i * dx;

        // спосіб 1: розгалуження в скороченій формі

        if (x < 0 && b != 0)
            F1 = a * x * x + b;
        if (x > 0 && b == 0)
            F1 = (x - a) / (x - c);
        if (!(x < 0 && b != 0) && !(x > 0 && b == 0))
            F1 = x / c;

        // спосіб 2: розгалуження в повній формі

        if (x < 0 && b != 0)
            F2 = a * x * x + b;
        else
            if (x > 0 && b == 0)
                F2 = (x - a) / (x - c);
            else
                F2 = x / c;

        cout << "| " << setw(10) << fixed << setprecision(3) << x
             << " | " << setw(14) << setprecision(4) << F1
             << " | " << setw(14) << F2 << " |" << endl;
    }

    cout << "+------------+----------------+----------------+" << endl;

    cin.get();
    cin.get();
    return 0;
}