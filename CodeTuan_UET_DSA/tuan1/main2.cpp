// Cho 1 mạng xã hội với N thành viên và M quan hệ. 2 người được coi là "biết" nhau nếu giữa hai người có bạn của bạn của bạn... của bạn chung (VD: nếu A là bạn của B, B là bạn của C, C là bạn của D thì A "biết" cả B, C và D). Viết chương trình xác định xem mọi người có đều "biết" nhau hay không. Nếu có, in ra số quan hệ cần thiết (tính từ quan hệ đầu tiên) để mọi người đều "biết" nhau.

// Input: 

// +) Dòng đầu là 2 số nguyên dương N, M, thể hiện số người và số quan hệ trong mxh.

// +) M dòng sau là M cặp số (x, y) thể hiện các cặp là bạn của nhau.

// Output: 

// +) Nếu mọi người đều biết nhau, in ra số quan hệ cần có.

// +) Nếu không, in ra "UNABLE TO FORM FRIEND GROUP"



// VD: có 5 người 0, 1, 2, 3, 4 và các mối quan hệ lần lượt (0,1), (1, 2), (2, 3), (3,0) và (0, 4). Đồ thị tính theo từng mối quan hệ như sau: 

// B1: 0 -- 1    2     3     4

// B2: 0 -- 1 - - 2    3     4

// B3: 0 -- 1 -- 2 -- 3     4

// B4: 0 -- 1     4

//       |     |

//       3 -- 2

// B5: 4 -- 0 -- 1

//              |      |

//              3 -- 2

// Đến bước thứ 5 mọi người mới đều biết nhau. Vậy đáp án là 5.

// For example:

// Input	Result
// 3 3
// 0 1
// 1 2
// 2 0     2
// 3 1
// 0 1     UNABLE TO FORM FRIEND GROUP

#include <iostream>
using namespace std;

int linked(int n, int m, int b[][2]){
	int a[100][2];
	for (int i = 0; i<m; i++){
		a[i][0] = b[i][0];
		a[i][1] = b[i][1];
	}
	int loopagain = 0, num = 0, clone = -1, loop = 0;
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
    if(num != 1){
    	return 0;
	}else{
		return 1;
	}
}

int main(){
    int n,m, a[100][2];
    cin >> n >> m;
    for (int i = 0; i<m; i++){
        cin >> a[i][0] >> a[i][1];
    }
    if(m < n-1){
    	cout << "UNABLE TO FORM FRIEND GROUP";
	}else{
		for (int k = n-1; k<=m; k++){
			if(linked(n,k,a) == 1){
				cout << k;
				break;
			}else if (k == m){
				cout << "UNABLE TO FORM FRIEND GROUP";
				break;
			}
		}
	}
}