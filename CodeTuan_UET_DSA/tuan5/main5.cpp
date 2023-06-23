// Viết chương trình sử dụng đệ quy đổi 1 số nguyên dương sang số nhị phân tương ứng

// For example:

// Input	Result
// 10      1010
// 7       111


#include <bits/stdc++.h>

using namespace std;

long int bine(int n, long int b){
    int a = 0, b1 = 1, a1 = 1;
    while( a1 <= n/2){
        a1 *= 2;
        a++;
    }
    for(int i=0; i< a; i++){
        b1 *= 10;
    }
    b += b1;
    int m = n -a1;
    if(m == 0){
        return b;
    } else{
        return bine(m,b);
    }
}

int main(){
     int n;
     cin >> n;
     long int m = bine(n,0);
     cout << m;
     return 0;
}