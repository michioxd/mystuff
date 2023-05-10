#include <iostream>

using namespace std;

bool isPerfect(int num)
{
    int total = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            total += i;
        }
    }

    return total > num ? false : true;
}

int main()
{
    int s = 0, e = 0, count = 0;
    do
    {
        cin >> s >> e;
    } while (s < 2 || e < 2 || s > 100000 || e > 100000);

    for (int i = s; i <= e; i++)
    {

        if (!isPerfect(i))
        {
            count++;
        }
    }

    cout << count;

    return 0;
}