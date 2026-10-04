#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int k, N, i;
    double S;

    cout << "k = "; cin >> k;
    cout << "N = "; cin >> N;

    // 1) while
    S = 0;
    i = k;
    while (i <= N)
    {
        S += (double)(i * i) / (k * k + N * N);
        i++;
    }
    cout << S << endl;

    // 2) do-while
    S = 0;
    i = k;
    do {
        S += (double)(i * i) / (k * k + N * N);
        i++;
    } while ( i <= N);
    cout << S << endl;

    // 3) for (i++)
    S = 0;
    for (i = k; i <= N; i++)
    {
        S += (double)(i * i) / (k * k + N * N);
    }
    cout << S << endl;

    // 4) for (i--)
    S = 0;
    for (i = N; i >= k; i--)
    {
        S += (double)(i * i) / (k * k + N * N);
    }
    cout << S << endl;

    return 0;
}