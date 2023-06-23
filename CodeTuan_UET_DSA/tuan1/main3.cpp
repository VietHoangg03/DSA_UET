// Cho đồ thị gồm N đỉnh, M cạnh và 1 số nguyên a. Sử dụng union find, tìm đỉnh lớn nhất trong thành phần liên thông chứa a của đồ thị.

// Input:

// +) Dòng đầu chứa 2 số nguyên N, M.

// +) M dòng tiếp theo là M cặp số nguyên không âm (x, y)

// +) Dòng cuối cùng là 1 số nguyên không âm a,

// Output: Đỉnh lớn nhất của thành phần liên thông chứa a trong đồ thị. Nếu a không có trong đồ thị, in ra "-1".
// Input	Result
// 3 3
// 0 1
// 1 2
// 2 0     1
// 2
// 3 1
// 0 1
// 3       -1

#include <iostream>
using namespace std;
int main(){
    int n,m, a[100][2], x, clone = -1, max, loop = 1, appear = 0;
    cin >> n >> m;
    for (int i = 0; i<m; i++){
        cin >> a[i][0] >> a[i][1];
    }
    cin >> x;
    max = x;
    if(m == 0){
        cout << x;
        return 0;
    }
    while (loop!=0){
        loop = 0;
        for (int i = 0; i<m; i++){
            if(a[i][0] == x && a[i][1] != x){
                loop++;
                appear++;
                clone = a[i][1];
                for(int j = 0; j<m; j++){
                    if(a[j][0] == clone){
                        a[j][0] = x;
                    }
                    if(a[j][1] == clone){
                        a[j][1] = x;
                    }
                }
                if (clone > max){
                    max = clone;
                }
                break;
            }
            if(a[i][1] == x && a[i][0] != x){
                loop++;
                appear++;
                clone = a[i][0];
                for(int j = 0; j<m; j++){
                    if(a[j][0] == clone){
                        a[j][0] = x;
                    }
                    if(a[j][1] == clone){
                        a[j][1] = x;
                    }
                }
                if (clone > max){
                    max = clone;
                }
                break;
            }
        }
    }
    if (appear == 0){
        cout << -1;
    }else{
        cout << max;
    }
}