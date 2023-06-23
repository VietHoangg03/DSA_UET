// Cài đặt thuật toán union find để xác định xem đồ thị có chu trình không.

// Input:

// +) Dòng đầu tiên là hai số nguyên dương N, M. N là số đỉnh, M là số cạnh đồ thị.

// +) M dòng tiếp theo là M cặp số nguyên không âm (x, y) (0<= x y < N) .

// Output: Nếu đồ thị có chu trình, in ra "YES", ngược lại in ra "NO".
// Input	Result
// 3 3
// 0 1
// 1 2
// 2 0     YES
// 3 2
// 0 1
// 1 2     NO

#include <iostream>
using namespace std;
int main(){
    int n,m, a[100][2], loopagain = 0, num = 0, clone = -1, loop = 0;
    cin >> n >> m;
    for (int i = 0; i<m; i++){
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 0; i<n; i++){
    	for (int j = 0; j<m; j++){
    		if(a[j][0] == i || a[j][1] == i){
    			loop++;
    			break;
			}
		}
		if(loop == 0){
			num++;
		}
		loop = 0;
	}
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            if(a[j][0] == i && a[j][1] != i){
                loopagain++;
                clone = a[j][1];
                for(int k = 0; k<m; k++){
                    if(a[k][0] == clone){
                        a[k][0] = i;
                    }
                    if(a[k][1] == clone){
                        a[k][1] = i;
                    }
                }
                break;
            }
            else if(a[j][1] == i && a[j][0] != i){
            	loopagain++;
                clone = a[j][0];
                for(int k = 0; k<m; k++){
                    if(a[k][0] == clone){
                        a[k][0] = i;
                    }
                    if(a[k][1] == clone){
                        a[k][1] = i;
                    }
                }
                break;
			}
            else if (a[j][0] == i){
            	loop++;
			}
        }
        if(loopagain != 0){
            i--;
        }else if (loop != 0){
            num++;
        }
        loopagain = 0;
        loop = 0;
    }
    if(num + m == n){
        cout << "NO";
    }else{
        cout << "YES";
    }
}