// Viết chương trình thực hiện thuật toán topological sort cho đồ thị gồm N đỉnh và M cạnh, các đỉnh đánh số từ 0 đến N - 1

// For example:

// Input	Result
// 3 3
// 1 2
// 2 0
// 0 1     0 1 2

#include <iostream>
#include <stack>

using namespace std;

stack<int> s;
int a[100][2];
int over[100];
int count = 0, n,m;

void find(int k){
	int done = 0;
	for(int i = 0; i<count; i++){
		if(over[i] == k){
			done++;
			break;
		}
	}
	if(done == 0){
		over[count] = k;
		count++;
		for(int i = m-1; i>=0; i--){
			if(a[i][0] == k){
				find(a[i][1]);
			}
			if(i == 0){
				s.push(k);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i<m; i++){
		cin >> a[i][0] >> a[i][1];
	}
	for(int i = 0; i<n; i++){
		find(i);
	}
	while(!s.empty()){
		cout << s.top();
		cout << " ";
		s.pop();
	}
}
