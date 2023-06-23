// Cho 1 xâu s. Ta định nghĩa "độ sâu trong ngoặc" của s dựa vào số dấu ngoặc đơn trong xâu s như sau:

// - nếu xâu s rỗng -> độ sâu = 0

// - nếu xâu s chứa N cặp dấu ngoặc lồng nhau -> độ sâu = N (VD: xâu "(((1)))" có độ sâu là 3, nhưng xâu "(1)(1)" có độ sâu là 1

// Nhập vào 1 xâu s. In ra độ sâu ngoặc của s.

// For example:

// Input	Result
// acsndkn. 0
// (abc).   1


#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(){
    stack<char> s;
    string str;
    int l, depth = 0, current = 0;
    getline(cin, str);
    l = str.length();
    for(int i = 0; i<l; i++){
    	if(str[i] == '('){
    		current++;
    		if(current > depth){
    			depth = current;
			}
    		s.push(str[i]);
		}
		else if (str[i] == ')'){
			if(!s.empty()){
				current--;
				s.pop();
			}
		}
	}
	cout << depth;
    return 0;
}