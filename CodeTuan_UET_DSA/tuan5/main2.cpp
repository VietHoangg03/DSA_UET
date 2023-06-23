// Viết chương trình sử dụng đệ quy cài đặt thuật toán bubble sort

// For example:

// Input	    Result
// 5
// 3 1 2 5 4   1 2 3 4 5

#include <bits/stdc++.h>

using namespace std;

void bubblesort(int a[], int n){
    for(int i = 0; i < n-1; i++){
        if(a[i] > a[i+1]){
            int s= a[i];
            a[i] = a[i+1];
            a[i+1]=s;
        }
    }
    n--;
    if(n == 0){
        return;
    } 
    return bubblesort(a, n);
}

int main(){
    int n, a[100];
    cin >> n;
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    bubblesort(a,n);
    for(int i = 0; i< n; i++){
        cout << a[i];
        cout << " ";
    }
}