// Cho 1 số A có 4 chữ số. Ta chia A thành 2 số bất kì chứa các chữ số của A (chấp nhận số 0 đứng đầu). Viết chương trình tính tổng nhỏ nhất có thể có khi chia A như vậy.

// VD: A = 2022. A có thể được chia thành các số như sau: [20, 22], [0, 222], [02, 22], [220, 2], [022, 2]. Tổng nhỏ nhất là 02 + 22 = 022 + 2 = 24.

// For example:

// Input	Result
// 2022.    24


#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,n,t,c,dv,arr[4];
    cin >> a;
    n= a /1000; 
    t= a /100;
    a= a - n*1000;
    c= a/10;
    dv=a%10;
    arr[0] = n;
    arr[1] = t;
    arr[2] = c;
    arr[3] = dv;
    sort(arr, arr+4);
    cout << arr[0]*10 + arr[1]*10 + arr[2] +arr[3];
}