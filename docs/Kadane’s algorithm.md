# Kadane’s algorithm

Thuật toán tìm dãy con có tổng số lớn nhất

## Độ phức tạp

`O(n)`

## Cách làm

1. Ta lấy tổng trước (`sum`) cộng với phân tử `i` của mảng (`sum + array[i]`), sau đó so sánh với phân tử `i` đấy.
    - Nếu tổng trên bé hơn phân tử `i` thì ta gắn cho nó tổng bằng phân tử `i` đấy (`sum = array[i]`) và gắn giá trị vị trí bắt đầu là `i`
    - Nếu tổng trến lớn hơn phân tử `i` thì ta cộng vào phân tử `i` vào `sum`

2. So sánh biến `best` và `sum`, nếu `sum` lớn hơn `best`, ta gắn giá trị của `sum` vào `best`, sau đó lấy giá trị bắt đầu là vị trí ở trên bước 1, vị trị cuối cùng là `i`.

## Ví dụ

C++

```c++
#include <iostream>

using namespace std;

int main()
{
    int n = 0, start = 1, end = 1, sum = 0, current = 0, best = INT_MIN;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a = 0;
        cin >> a;
        if (sum + a < a)
        {
            current = i;
            sum = a;
        }
        else
        {
            sum += a;
        }

        if (best < sum)
        {
            best = sum;
            start = current;
            end = i;
        }
    }

    cout << x << endl
         << y << endl
         << best;

    return 0;
}
```

| Đầu vào                    | Kết quả |
|----------------------------|---------|
| 8 12 -14 1 23 -6 22 -34 13 | 3 6 40  |
