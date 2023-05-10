#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    freopen("thuong.inp", "r", stdin);
    freopen("thuong.out", "w", stdout);

    int n = 0;
    cin >> n;

    cout << ((n * (n + 1)) / 2) / n;

    return 0;
}