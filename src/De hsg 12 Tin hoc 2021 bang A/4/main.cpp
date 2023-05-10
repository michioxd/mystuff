#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    freopen("DaiLy.inp", "r", stdin);
    // freopen("DaiLy.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int position[n], carInfo[m][4];
    for (int i = 0; i < n; i++)
    {
        cin >> position[i];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> carInfo[i][j];
        }
    }

        return 0;
}