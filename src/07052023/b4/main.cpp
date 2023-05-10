#include <iostream>

using namespace std;

int main()
{
    freopen("hoagao.inp", "r", stdin);
    freopen("hoagao.out", "w", stdout);

    int x = 0;
    cin >> x;

    if (x % 2 == 0 && x % 5 == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}