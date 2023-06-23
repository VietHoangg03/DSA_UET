// Bạn có M ($). Bạn muốn mua socola, trong đó 1 thanh socola có giá P ($). Cửa hàng bạn mua đang có chương trình khuyến mại đặc biệt: sau khi ăn xong, bạn có thể mang W giấy gói kẹo để đổi lấy thêm 1 thanh socola miễn phí. Hãy tính số thanh socola tối đa bạn có thể ăn được với số tiền bạn có.

// Input: 3 số nguyên dương M, P, W.

// Output: số socola tối đa có thể có.

// For example:

// Input	    Result
// 16 2 2      15
// 15 1 3      22

#include <bits/stdc++.h>

using namespace std;

int ans(int n, int w, int have){
    int get = n/w;
    have +=get;
    n=n-get*w+get;
    if(n<w){
        return have;
    }else {
        return ans(n,w,have);
    }
}

int main(){
    int m,p,w;
    cin >> m >> p >> w;
    int n = m/p;
    cout << ans(n,w,n);
}