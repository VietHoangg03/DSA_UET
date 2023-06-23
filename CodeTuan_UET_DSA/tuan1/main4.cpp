// Cho mảng gồm N số nguyên từ 0 đến N - 1 và 1 số nguyên không âm x. Sử dụng union find, thực hiện M toán tử sau:

// +) xóa x khỏi mảng.

// +) in ra số kế tiếp x (số nhỏ nhất y trong mảng sao cho y >= x) . Nếu không tồn tại số này hoặc nếu x không nằm trong mảng, in ra "-1".

// For example:

// Input	Result
// 10 3
// 1
// 2
// 3       2 3 4
// 5 3
// 6
// 1
// 4.      -1 2 -1

#include <iostream>
using namespace std;
int main(){
    int n,m,a[100], num=-1, loop = 0;
    cin >> n >> m;
    for (int i = 0; i<m; i++){
        cin >> a[i];
    }
    for (int i = 0; i<m; i++){
        if (a[i] >= n-1){
            cout << -1;
            cout << "\n";
        }else{
            num = a[i]+1;
            while (loop != 0){
                loop = 0;
                for (int j = 0; j<i; j++){
                    if(a[j] == num){
                        num++;
                        loop++;
                        break;
                    }
                }
            }
            cout << num;
            cout << "\n";
        }
    }
}