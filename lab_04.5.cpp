#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
    double x, y;
    double R;

    cout << "R = "; cin >> R;

    srand((unsigned) time(NULL));

    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        if ( (x*x + y*y <= R*R) &&
             ((x >= 0 && y >= x) ||
              (x <= 0 && y <= x)) )
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    cout << endl << fixed;

    for (int i = 0; i < 10; i++)
    {
        x = 2. * R * rand() / RAND_MAX - R;
        y = 2. * R * rand() / RAND_MAX - R;

        if ( (x*x + y*y <= R*R) &&
             ((x >= 0 && y >= x) ||
              (x <= 0 && y <= x)) )
            cout << setw(8) << setprecision(4) << x << "  "
                 << setw(8) << setprecision(4) << y << "  " << "yes" << endl;
        else
            cout << setw(8) << setprecision(4) << x << "  "
                 << setw(8) << setprecision(4) << y << "  " << "no" << endl;
    }

    cin.get();
    cin.get();
    return 0;
}