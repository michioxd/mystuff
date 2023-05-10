#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    freopen("cstc.inp", "r", stdin);
    freopen("cstc.out", "w", stdout);

    int n = 0;
    cin >> n;

    int powed = pow(2024, n);

    cout << powed % 10;

    return 0;
}