// Cho 1 mảng gồm N số nguyên dương. Với mỗi số trong mảng, in ra số các số trong mảng nhỏ hơn nó.

// VD: Mảng gồm 5 số là [5, 4, 3, 2, 1]

// Số đầu tiên là 5; trong mảng có 4 số nhỏ hơn nó -> in ra 4.

// Tương tự -> kết quả là 4, 3, 2, 1, 0

// For example:

// Input	        Result
// 5
// 1 2 3 4 5       0 1 2 3 4

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, count = 0;
    int a[100], b[100]; // khai bao 2 mang a vs b
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i]; // nhap vao cac phan tu mang a
        b[i] = a[i]; // goi mang B = mang A
    }
    sort(b, b+n); // sap xep cac phan tu mang B
    for(int i = 0; i<n; i++){
        for(int j = 0; j< n; j++){ // dung 2 vong lap de so sanh cac phan tu trong mang
            if(b[j] < a[i]){
                count++; // neu phan tu mang A lowns hon phan tu mang B thi count se tang 1 don vi 
            }
        }
        cout << count; // in ra count va reset count ve = 0
        cout << " ";
        count = 0;
    }
}