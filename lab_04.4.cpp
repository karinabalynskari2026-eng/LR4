#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double xp; // початок інтервалу x_поч
    double xk; // кінець інтервалу x_кін
    double dx; // крок
    double x;  // вхідний аргумент
    double R;  // вхідний параметр (0 < R < 6)
    double y;  // результат обчислення виразу

    cout << "R = ";     cin >> R;
    cout << "x_поч = "; cin >> xp;
    cout << "x_кін = "; cin >> xk;
    cout << "dx = ";    cin >> dx;

    if (R <= 0 || R >= 6)
    {
        cout << "R має задовольняти умову 0 < R < 6!" << endl;
        return 1;
    }
    if (dx <= 0)
    {
        cout << "Крок dx має бути додатним!" << endl;
        return 1;
    }
    if (xp > xk)
    {
        cout << "x_поч має бути не більшим за x_кін!" << endl;
        return 1;
    }

    // кількість кроків (щоб не накопичувалась похибка при додаванні dx)
    int n = (int)floor((xk - xp) / dx + 1e-9);

    // заголовок і шапка таблиці
    cout << endl;
    cout << "      Таблиця значень функції y(x)" << endl;
    cout << "+------------+------------+" << endl;
    cout << "|     x      |     y      |" << endl;
    cout << "+------------+------------+" << endl;

    for (int i = 0; i <= n; i++)
    {
        x = xp + i * dx;

        // розгалуження в повній формі

        if (x <= -6 - R)
            y = 0;
        else
            if (-6 - R < x && x <= -6)
                y = -sqrt(R * R - (x + 6) * (x + 6));
            else
                if (-6 < x && x <= -R)
                    y = -R + R / (6 - R) * (x + 6);
                else
                    if (-R < x && x <= 0)
                        y = sqrt(R * R - x * x);
                    else
                        if (0 < x && x <= 3)
                            y = R - R * x / 3;
                        else
                            y = R / 6 * (x - 3);

        cout << "| " << setw(10) << fixed << setprecision(3) << x
             << " | " << setw(10) << y << " |" << endl;
    }

    cout << "+------------+------------+" << endl;

    cin.get();
    cin.get();
    return 0;
}