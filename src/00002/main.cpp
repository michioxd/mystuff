#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main()
{
    freopen("Xanhdep.inp", "r", stdin);
    freopen("Xanhdep.out", "w", stdout);

    int n, lastCount = 0, currentCount = 0;
    cin >> n;
    string str[n];
    char lastChar;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < str[i].size(); j++)
        {
            currentCount++;

            if (str[i][j] == lastChar)
            {
                lastCount = currentCount > lastCount ? currentCount : lastCount;
            }
            else
            {
                lastChar = str[i][j];
                currentCount = 0;
            }
        }
    }

    cout << lastCount;

    return 0;
}