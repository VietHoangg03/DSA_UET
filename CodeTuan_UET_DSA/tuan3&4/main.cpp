// 1 câu bị tráo các từ, sau đó gắn vào cuối mỗi từ 1 số chỉ vị trí gốc của từ đó trong câu. Viết chương trình sắp xếp lại câu gốc và in ra.

// For example:

// Input	        Result
// world2 hello1
//                 hello world


#include <bits/stdc++.h>

using namespace std;

int main(){
    stack<char> s; // khai bao stack s voi kieu du lieu char
    int n = -1; // khai bao bien n= -1
    string str; // khai bao chuoi sting
    getline(cin, str); // nhap vao chuoi
    int l = str.length(); // tinh do dai chuoi
    for(int i=0; i< 10; i++){
        char a = (char)(i + '0'); // dat bien a lap lai tu 0 den 10 vi khai bao xau ky tu nen phai "khai bao kieu char a"
        for(int j = 0; j <l ; j++){ // vong lap duyet tung ky tu trong xau ky tu
            if(str[j] == a){ // neu duyet dinh ky tu so bang voi a sau do lui J 1 don vi
                n = j - 1;
                str[j] = ' ';// biến số đó thành khoảng trống
                while(n>=0 && str[n] != ' '){ // với n >= 0 và str[n] khác khoảng trống thì đẩy ký tự đó vào stack
                    s.push(str[n]);
                    str[n] = ' ';// xoá bỏ xâu vừa sắp xếp ra khỏi chuỗi nhập vào
                    n--;// n trừ đi 1 đơn vị 
                } 
                while (!s.empty()){ // khi đã đẩy ký tự đó vào stack thì stack không trống
                    cout << s.top(); // lấy giá trị top stack ra và sau đó xoá đi
                    s.pop();
                } // tiếp tục vòng lặp cho đến khi i = 10 và sắp xếp đủ
                cout << " ";
            }
        }
    }
}