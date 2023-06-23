// Viet truong tirnh su dung de quy xem 1 so nguyen bat ky co phai la doi xung khong
// So doi xung la so ma viet xuoi hay nguonc deu nhu nhau
// Co In ra YESS Khong thi in ra NO 

#include <bits/stdc++.h>

using namespace std;

int sym (int n){
    if(n < 10){
        return 1;
    } else {
        int a = 1;
        while( a < n/10){
            a*=10; // nhan a den khi co don vi bang vs so nhap vao
        }
        int b = n /a; // kiem tra so dau vs cuoi
        int c = n%10;
        if(b!=c){
            return 0;
        } else {
            return sym((n-a*b-c)/10);
        }
    }
}

int main(){
    int n;
    cin >> n;
    if(sym(n) == 0){
        cout  << "no";
    }else {
        cout << "yes";
    }
}