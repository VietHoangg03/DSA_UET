// Trong giờ ăn trưa, căng tin có N học sinh xếp hàng. Có N suất ăn tương ứng thuộc 2 loại: 0 và 1. Tuy nhiên, mỗi bạn học sinh lại chỉ thích ăn 1 loại suất ăn nhất định. Nếu đến lượt mình mà không có suất ăn ưa thích, học sinh sẽ di chuyển đến cuối hàng và xếp hàng lại từ đầu cho đến khi không còn suất ăn ưa thích nữa (khi đó bạn học sinh đó sẽ không được ăn trưa).
// Viết chương trình nhập vào số nguyên N và hai mảng thể hiện các học sinh và suất ăn, in ra số học sinh không ăn trưa.

// VD: hàng học sinh = [1, 1, 0, 0], suất ăn = [0, 1, 0, 1]

// học sinh đầu tiên thích suất ăn loại 1 -> chuyển xuống cuối hàng (hàng = [1, 0, 0, 1]

// học sinh thứ 2 tương tự (hàng = [0, 0, 1, 1])

// học sinh thứ 3 lấy suất ăn loại 0 (hàng = [0, 1, 1], suất ăn = [1, 0, 1])

// lặp lại đến hết ta thấy mọi ng đều được ăn -> in ra 0.

// For example:

// Input	Result
// 4
// 1 1 0 0
// 0 1 0 1     0
// 2
// 1 0
// 0 1         0

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, a, over = 1;
    queue<int> q1, q2;
    cin >> n; // nhap vao n
    for(int i=0; i< n; i++){
        cin >> a; // nhap vao a
        q1.push(a); // day a vao queue 1
    }
    for (int i=0; i<n; i++){
        cin >> a; // nhap vao a
        q2.push(a); // day a vao queue 2 
    }
    while (over !=0 && !q1.empty()){
        over = 0; 
        for(int i=0; i<n; i++){ // vong lap n
            if(!q1.empty() && !q2.empty()){ // neu q1 va q2 khong trong
                if(q1.front() != q2.front()){ // neu phan tu dau q1 khac phan tu dau q2
                        a = q1.front(); // a = phan tu dau q1
                        q1.pop(); // xoa phan tu dau
                        q1.push(a); // day phan tu dau xuong cuoi
                } else {
                        q1.pop(); // neu phan tu dau q1 va q2 bang nhau thi xoa q1 vs q2
                        q2.pop();
                        over ++; // over len thanh 1 de tiep tuc vong lap  neu khong dung over trong trruog hop
                                // q1 khong bi xoa het thì sẽ chạy liên tục vòng lặp và không đưa ra được size 
                }
            }
        }
    }
    cout << q1.size();
    return 0;
}
