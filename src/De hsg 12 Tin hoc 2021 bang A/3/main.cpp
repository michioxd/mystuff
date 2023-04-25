#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int stepper(bool isNam, int n, int input[], int count)
{
    int lap = 0, lastNum = 0;
    bool isDone = false;
    while (isDone != true)
    {
        int currentCount = 0;
        for (int i = 0; i < n; i++)
        {
            if ((isNam == true ? input[i] % 2 == 0 : input[i] % 2 != 0) && input[i] != -1)
            {
                if (input[i] - lastNum <= 2)
                {
                    lastNum = input[i];
                    input[i] = -1;
                    currentCount++;
                }
            }
            else if (input[i] == -1)
            {
                currentCount++;
            }

            if (currentCount == count)
            {
                isDone = true;
            }
        }
        lap++;
    }

    return lap;
}

int main()
{
    freopen("BacNam.inp", "r", stdin);
    freopen("BacNam.out", "w", stdout);

    int n;
    cin >> n;
    int input[n],
        countB = 0,
        countN = 0,
        lapB = 0,
        lapN = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        input[i] % 2 == 0 ? countN++ : countB++;
    }

    lapB = stepper(false, n, input, countB);
    lapN = stepper(true, n, input, countN);

    cout << lapB << endl
         << lapN;

    return 0;
}