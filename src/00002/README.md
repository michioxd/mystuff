# Thành phố xanh đẹp

Thành phố của Bình có nhiều con đường được trồng cây xanh. Mỗi cây xanh được đặt tên bằng một chữ cái latinh hoa. Theo Bình, một đoạn đường được gọi là xanh đẹp nếu đoạn đường đó chỉ trồng một loại cây xanh (tức là trên đoạn đường đó, các cây được trồng ở vị trí liên tiếp, có tên giống nhau và thuộc một con đường).

**Yêu cầu** : Hãy giúp Bình tìm đoạn đường xanh đẹp gồm nhiều cây xanh nhất trong tất cả các con đường của thành phố.

**Dữ liệu** cho trong file **Xanhdep.Inp** gồm:

- Dòng 1 ghi số nguyên dương `N (N ≤ 100)` là số con đường trong thành phố.
- dòng tiếp theo, mỗi dòng ghi một xâu kí tự gồm các chữ cái latinh hoa mô tả tên của các cây xanh được trồng liên tiếp từ đầu con đường đến cuối con đường. Số lượng cây trên mỗi con đường không lớn hơn `10^4`.

**Kết quả** ghi ra file **Xanhdep.Out** một số nguyên là số lượng cây xanh trên đoạn đường xanh đẹp gồm nhiều cây xanh nhất trong các con đường của thành phố.

_Ví dụ:_

| **Xanhdep.Inp** | **Xanhdep.Out** | **Giải thích** |
| --- | --- | --- |
| 3<br />ABBBABAAH<br />HHHHHAHHHA<br />EEAE
 | 5 | Đoạn đường xanh đẹp gồm nhiều cây nhất là 5 cây (HHHHH) trong con đường thứ 2. |

**Giới hạn:**

- Có 80% số test ứng với `N ≤ 10`  và số cây trên mỗi con đường không quá 100 cây;
- Có 20% số test không có giới hạn gì thêm.
