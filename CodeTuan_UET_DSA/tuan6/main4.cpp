// Viết chương trình cài đặt thuật toán tô màu đồ thị: cho đồ thị N đỉnh (đánh số từ 0 -> N - 1) và M cạnh, tìm cách tô màu sử dụng ít màu nhất sao cho 2 đỉnh trên 1 cạnh không có màu giống nhau.

// Input: Dòng đầu là 2 số nguyên N, M. M dòng tiếp theo là N cặp số (x, y) biểu thị các cạnh.

// Output: N dòng chứa các cặp số (v, u), với v là đỉnh (theo thứ tự từ 0 -> N - 1) và u là màu tương ứng của đỉnh đó (u nằm trong khoảng 0 -> N - 1, tương ứng với tối đa N màu).

// For example:

// Input	Result
// 5 3     0 0
// 0 1     1 1 
// 1 2     2 0
// 3 4     3 0
//         4 1

#include <iostream>

using namespace std;

int n,m, a[100][2], count = 0, b[100];


void adjust(int k){
	int wrong = 1;
	while (wrong != 0){
		wrong = 0;
		for(int i = 0; i<m;i++){
			if(a[i][0] == k){
				int x = a[i][1];
				if(b[k] == b[x] && k>x){
					b[k]++;
					wrong++;
				}
			}
			if(a[i][1] == k){
				int x = a[i][0];
				if(b[k] == b[x] && k>x){
					b[k]++;
					wrong++;
				}
			}
		}
	}
}
void number (int k){
	if(b[k] == -1){
		b[k] = 0;	
	}
	adjust(k);
	for(int i = 0; i<m; i++){
		if(a[i][0] == k && k<a[i][1]){
			number(a[i][1]);
		}else if(a[i][1] == k && k<a[i][0]){
			number(a[i][0]);
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i<m; i++){
		cin >> a[i][0] >> a[i][1];
		b[i] = -1;
	}
	for(int i = 0; i<n; i++){
		number(i);
	}
	for(int i = 0; i<n; i++){
		cout << i;
		cout << " ";
		cout << b[i];
		cout << "\n";
	}
}
