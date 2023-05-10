#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = n * (1 + n) / 2;
    if (s % 2 == 0)
    {
        cout << "-1" << endl;
        return 0;
    }

    int halfSum = s / 2;
    int curSum = 0;
    for (int M = 2; M <= n; M++)
    {
        curSum += M;
        if (curSum == halfSum)
        {
            cout << M << " ";
            return 0;
        }
        else if (curSum > halfSum)
        {
            cout << "-1" << endl;
            return 0;
        }
    }

    cout << "-1" << endl;
    return 0;
}