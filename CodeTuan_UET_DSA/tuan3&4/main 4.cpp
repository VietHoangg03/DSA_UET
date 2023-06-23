// 1 lớp học gồm N bạn sinh viên tổ chức chụp ảnh. Lớp muốn chụp ảnh sao cho các bạn xếp thành hàng theo đúng thứ tự chiều cao, với bạn cao thứ i đứng ở vị trí thứ i trong hàng. Tuy nhiên, khi xếp hàng, các bạn trong lớp lại không đứng theo thứ tự này. Tìm số bạn không đứng đúng theo thứ tự trong hàng.

// Input: Dòng đầu là số nguyên N. Dòng thứ hai là hàng hiện tại

// Output: Số bạn đứng sai thứ tự.

// For example:

// Input	       Result
// 5
// 1 3 2 5 4       4
// 6
// 1 1 4 2 1 3     3


#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a[100], b[100], count = 0;
    cin >> n;
    for(int i=0;i < n; i++ ){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    for(int i= 0; i < n; i++) {
        if(a[i] != b[i]){
            count ++;
        }
    }
    cout << count;
    return 0;
}