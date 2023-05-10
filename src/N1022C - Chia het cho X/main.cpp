#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long A, B, X;
    cin >> A >> B >> X;

    long long count_B = B / X;

    long long count_A = (A - 1) / X;

    long long count_AB = count_B - count_A;

    cout << count_AB << endl;

    return 0;
}