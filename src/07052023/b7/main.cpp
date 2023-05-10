#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    freopen("tongxau.inp", "r", stdin);
    freopen("tongxau.out", "w", stdout);

    string a;
    getline(cin, a);
    int sum = 0;

    for (int i = 0; i < a.length(); i++)
    {
        int num = a[i] - '0';
        sum += num;
    }

    cout << sum;

    return 0;
}