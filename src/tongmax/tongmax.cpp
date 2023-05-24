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

    for (int i = 1; i <= n; i++)
    {
        int a = 0;
        cin >> a;
        if (sum + a < a)
        {
            crr = i;
            sum = a;
        }
        else
        {
            sum += a;
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
         << best;

    return 0;
}