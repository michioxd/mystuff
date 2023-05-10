#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    freopen("thoigian.inp", "r", stdin);
    freopen("thoigian.out", "w", stdout);

    int s = 0;
    cin >> s;

    int h = (s / 3600);
    int m = (s % 3600) / 60;
    int ss = (s % 60);

    cout << h << " " << m << " " << ss;

    return 0;
}