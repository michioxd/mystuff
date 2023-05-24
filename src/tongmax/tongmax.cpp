#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    freopen("tongmax.inp", "r", stdin);
    freopen("tongmax.out", "w", stdout);

    int n = 0, x = 1, y = 1, sum = 0, crr = 0, best = INT_MIN;
    cin >> n;
    int a[n + 1];

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (sum + a[i] < a[i])
        {
            crr = i;
            sum = a[i];
        }
        else
        {
            sum += a[i];
        }

        if (best < sum)
        {
            best = sum;
            x = crr;
            y = i;
        }
    }

    cout << x << endl
         << y << endl
         << sum;

    return 0;
}