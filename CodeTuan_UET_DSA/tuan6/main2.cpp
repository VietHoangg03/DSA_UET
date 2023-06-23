// Viết chương trình thực hiện thuật toán BFS từ 1 đỉnh x của đồ thị có hướng đánh số từ 0 -> N - 1 (input và output tương tự bài 1)

// For example:

// Input	Result
// 4
// 0 1
// 1 2
// 2 3
// 3 0
// 1       1 2 3 0

#include <bits/stdc++.h>

using namespace std;

queue<int> s;
int out[100];

int find(int a, int count){
    int x = 0;
    for(int i =0; i< count; i++){
        if(out[i] == a){
            x++;
        }
    }
    if(x == 0){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    int n, m, a[100][2], count = 1;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    cin >> m;
    out[0] = m;
    for(int i=0; i<n; i++){
        if(a[i][0] == m){
            s.push(a[i][1]);
        }
    }
    while (!s.empty()){
        int k;
        if(find(s.front(),count) == 0){
            k=s.front();
            s.pop();
            out[count] = k;
            count ++;
            for(int i=0; i<n; i++){
                if(a[i][0]==k && find(a[i][1], count) == 0){
                    s.push(a[i][1]);
                }
            }
        }else{
            s.pop();
        }
    }
    for(int i=0; i<count; i++){
        cout << out[i];
        cout << " ";
    }
}