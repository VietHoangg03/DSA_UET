// VIết chương trình cài đặt thuật toán DFS của đồ thị có hướng,  N đỉnh đánh số từ 0 đến N - 1.

// Input: Dòng đầu là 1 số nguyên N chỉ N đỉnh (cũng là N cạnh của đồ thị).

// N dòng sau là các cặp (V, E) tương ứng với các cạnh từ V -> E.

// Dòng cuối là 1 số nguyên X chỉ đỉnh bắt đầu DFS.

// Output: Thứ tự các đỉnh trong đồ thị khi thực hiện DFS từ X.

// For example:

// Input	Result
// 4
// 0 1
// 1 2
// 2 3
// 3 0
// 1       1 2 3 0
// 3
// 2 1
// 1 0
// 0 1
// 2       2 1 0

#include <bits/stdc++.h>

using namespace std;

stack<int> s; // tao stack kieu int s;
int out[100]; // tao cuoi out 

int find(int a, int count){ // ham find kiem tra xem dinh a da được duyệt hay chưa
    int x = 0;
    for(int i = 0; i< count; i++){
        if(out[i] == a){ // được a[i][1] = với biến out trong i thì trả về 1 nghĩa là đã được duyệt 
            x++;
        }
    }
    if(x == 0) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n,m, a[100][2], count=1; // khai báo biến n la số đỉnh của đồ thị, m là đỉnh bắt đầu DFS, a[100][2] mảng 2 chiều a để lưu trữ cạnh đồ thị
    cin >> n; // count là số đỉnh đã được duyệt
    for(int i=0; i<n; i++){
        cin >> a[i][0] >> a[i][1]; 
    }
    cin >> m; 
    out[0] = m; // gán giá trị đầu vào cho biến out
    for(int i=0; i<n; i++){
        if(a[i][0] == m){
            s.push(a[i][1]); // tìm các đỉnh kề với m và đẩy vào stack
        }
    }
    while(!s.empty()){ // neu stack khong trong
        int k;
        if(find(s.top(), count) == 0){ // kiem tra xem đỉnh stack đã được duyệt hay chưa
            k = s.top(); // lay gia tri dinh do gán cho k
            s.pop(); // xoá bỏ phần tử trên cùng 
            out[count] = k; // gán giá trị k vào vị trí count
            count ++; // tang count len 1 don vi
            for(int i = n-1; i>=0; i--){ 
                if(a[i][0] == k && find(a[i][1],count) == 0){   // duyệt mảng a từ cuối lên đầu và đẩy các đỉnh kề với k vào stack s
                    s.push(a[i][1]); // chỉ đẩy đỉnh chưa được duyệt vì find  trả về 0
                }
            }
        } else { // nếu đỉnh stack đã được duyệt thì xoá khỏi stack
            s.pop();
        }
    }
    for (int i = 0; i< count; i++){
        cout << out[i]; // in ra ket qua 
        cout << " ";
    }
}