// Cho mảng A gồm N phần tử và mảng B rỗng. Mỗi phần tử trong mảng A có thể có các dạng sau:

// - 1 số nguyên dương bất kỳ, thực hiện toán tử chèn số vào mảng B.

// - Chữ cái "C" thực hiện toán tử xóa phần tử cuối của mảng B.

// - Chữ cái "D" thực hiện phép nhân 2 với phần tử cuối mảng B, sau đó chèn kết quả vào cuối mảng B.

// - Ký tự "+" thực hiện phép cộng 2 phần tử cuối mảng B, sau đó chèn kết quả vào cuối mảng B.

// Sau khi thực hiện hết các toán tử, tính tổng các phần tử trong mảng B và in ra kết quả.

// Input:

// - Dòng đầu nhập số nguyên N.

// - N ký tự tiếp theo là N phần tử của mảng A

// Output: tổng các phần tử trong mảng B.

// For example:

// Input	  Result
// 2
// 1 C.        0
// 5
// 5 2 C D +   30



#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    stack<int> s;
    string str;
    int n, l, sign = 0, sum = 0, negative = 0;
    cin >> n;
    getchar();
    getline(cin, str);
    l = str.length();
    for(int i=0; i< l; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            if(sign ==0){
                int a = str[i] - '0';
                s.push(a);
                sign ++;
            } else {
                int a = str[i] - '0';
                int b = s.top();
                b = b*10 +a;
                s.pop();
                s.push(b);
            }
        } else if (str[i] == '-'){
            negative = 1;
        } else {
            sign = 0;
            if (negative == 1){
                int a = -s.top();
                s.pop();
                s.push(a);
            } 
            negative = 0;
            if (str[i] == 'C'){
                s.pop();
            } else if(str[i] == 'D'){
                int a = s.top() * 2;
                s.push(a);
            } else if(str[i] == '+'){
                int a = s.top();
                s.pop();
                int b = s.top();
                b = b+a;
                s.push(a);
                s.push(b);
            }
        }
    }
    while (!s.empty()){
        int a = s.top();
        sum += a;
        s.pop();
    }
    cout << sum;
    return 0;
}