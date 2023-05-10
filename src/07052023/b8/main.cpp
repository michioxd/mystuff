#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    freopen("somax.inp", "r", stdin);
    // freopen("somax.out", "w", stdout);

    string a;
    getline(cin, a);
    string last = "";

    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] >= 48 && a[i] <= 57)
        {
            last += a[i];
        }
    }

    // string maxNum = last.substr(0, 5);

    // for (int i = 1; i <= last.length() - 5; i++)
    // {
    //     string crr = last.substr(i, 5);
    //     maxNum = max(maxNum, crr);
    // }

    cout << last.substr(last.length() - 5, 5);
    return 0;
}