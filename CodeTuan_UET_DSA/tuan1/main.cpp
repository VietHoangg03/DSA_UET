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
    cout << num;
}