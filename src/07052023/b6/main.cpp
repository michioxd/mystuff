#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    freopen("tongdoan.inp", "r", stdin);
    freopen("tongdoan.out", "w", stdout);

    int a, b;
    cin >> a >> b;

    cout << (b - a + 1) * (b + a) / 2;

    return 0;
}