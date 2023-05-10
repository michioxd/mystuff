#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    freopen("Daysodep.inp", "r", stdin);
    // freopen("Daysodep.out", "w", stdout);

    int n, k, count = 0;

    while (!(n <= 2 * pow(10, 5)) || !(k > 0 && k <= 100))
    {
        cin >> n >> k;
    }

    int val[n];
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        int x = 0,
            y = 0,
            countEven = 0,
            countOdd = 0;
        for (int j = i; j < n; j++)
        {
            if (val[j] % 2 == 0)
            {
                x += val[j];
                countEven++;
            }
            else
            {
                y += val[j];
                countOdd++;
            }
        }

        if ((x - y) >= 0 && (x - y) <= k && countEven > 0 && countOdd > 0)
        {
            count++;
        }
    }

    if (count > 0)
        cout << count;

    return 0;
}