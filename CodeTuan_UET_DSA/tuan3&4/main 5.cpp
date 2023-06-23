// Cho mảng gồm N số nguyên. Viết chương trình in ra bình phương các phần tử trong mảng theo thứ tự tăng dần.

// For example:

// Input	        Result
// 5
// 1 -2 3 -4 5     1 4 9 16 25 

#include <bits/stdc++.h>

using namespace std;

int main(){
    long int n, a[100];
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> a[i];
        a[i] = a[i] * a[i];
    }
    sort(a, a+ n);
    for(int i=0; i < n; i++){
        cout << a[i];
        cout << " ";
    }
    return 0;
}