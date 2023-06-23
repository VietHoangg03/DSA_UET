// Cài đặt Stack sử dụng Queue. 

// Input: 

// - Dòng đầu là 1 số nguyên dương Q, thể hiện số toán tử thực hiện.

// - Q toán tử sau thực hiện như sau:

// +) Nhập 1 số nguyên dương i (i = 1, 2, 3)

// +) Nếu i = 1, nhập 1 số nguyên x, sau đó đẩy x vào stack.

// +) Nếu i = 2, xóa đuôi stack.

// +) Nếu i = 3, in ra phần tử cuối stack.

// For example:

// Input	Result
// 3
// 1 2
// 1 4
// 3.      4


#include <bits/stdc++.h>

using namespace std;

struct Stack{
    queue<int> q1, q2;
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop() {
        q1.pop();
    }
    void print(){
        if(q1.empty()){
            cout << -1;
            cout << "\n";
        } else {
            cout << q1.front();
            cout << "\n";
        }
    }
};

int main(){
    Stack s;
    int a,i, num;
    cin >> a;
    for(int j=0; j<a;j++) {
        cin >> i;
        if(i == 1) {
            cin >> num;
            s.push(num);
        } else if (i == 2){
            s.pop();
        } else {
            s.print();
        }
    }
}