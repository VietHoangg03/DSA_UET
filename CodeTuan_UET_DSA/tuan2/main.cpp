// Cài đặt cấu trúc Queue sử dụng 2 Stack. 

// Input: 

// +) Dòng đầu là 1 số nguyên dương Q, thể hiện số toán tử thực hiện.

// +) Q toán tử tiếp theo được thực hiện như sau:

// - nhập vào 1 số i (i = 1, 2 hoặc 3).

// - nếu i = 1, nhập thêm 1 số x, thực hiện đưa x vào queue.

// - nếu i = 2, thực hiện dequeue

// - nếu i = 3, in ra phần tử trước queue.

// Output: các phần tử trước queue tương ứng sau Q toán tử

// For example:

// Input	Result
// 3
// 1 2
// 1 3
// 3       2





#include <iostream>
#include <stack>

using namespace std;


int main(){
        int Q;
        cin >> Q;
        
        stack<int> stack1, stack2;
        
        for (int i=0; i<Q; i++) {
            int op;
            cin >> op;
            
            if(op == 1){
                int x;
                cin >> x;
                stack1.push(x);
            } else if (op == 2){
                if (stack2.empty()){
                    while (!stack1.empty()) {
                        stack2.push(stack1.top());
                        stack1.pop();
                    }
                }
                if(!stack2.empty()){
                    stack2.pop();
                }

            } else if (op = 3){
                if(stack2.empty()){
                    while(!stack1.empty()){
                        stack2.push(stack1.top());
                        stack1.pop();
                    }
                }
                if (!stack2.empty()){
                    cout << stack2.top() << endl;
                }
            }
        }
        return 0;
    }
