#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    freopen("daoham.inp", "r", stdin);
    freopen("daoham.out", "w", stdout);

    int q, n;
    cin >> q >> n;

    cout << (n * (n + 1)) / 2 + (q * n);

    return 0;
}
