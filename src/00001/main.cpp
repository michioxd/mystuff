#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    freopen("TongUoc.inp", "r", stdin);
    freopen("TongUoc.out", "w", stdout);

    int a, b, total = 0;
    cin >> a >> b;

    for (int i = 1; i <= (a > 3 * b ? a : b); i++)
    {
        if (a % i == 0 && 3 * b % i == 0)
        {
            total += i;
        }
    }

    cout << total;
    return 0;
}