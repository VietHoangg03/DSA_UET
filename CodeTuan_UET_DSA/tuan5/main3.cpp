// Viết chương trình giải bài toán tháp Hà Nội với 4 cọc (A, B, C, D) và N đĩa (disk1... diskN).

#include <iostream>

using namespace std;

void move(int disk, char from, char to){
    cout << "Move disk";
    cout << disk;
    cout << " from rod ";
    cout << from;
    cout << " to rod ";
    cout << to;
    cout << "\n";
}

void swap(int n, char from, char to){
 char mid;
 if(from == 'A'){
  if(to == 'B'){
   mid = 'D';
  }else{
   mid = 'B';
  }
 }else if(from == 'B'){
  if(to == 'D'){
   mid = 'A';
  }else{
   mid = 'D';
  }
 }else{
  if(to == 'A'){
   mid = 'B';
  }else{
   mid = 'A';
  }
 }
 if(n == 2){
  if(to == 'D'){
   move(1,from,'C');
   move(2,from,to);
   move(1,'C', to);
  }else{
   move(1,from,'D');
   move(2,from,to);
   move(1,'D', to);
  }
 }else if(n == 3){
  if(mid == 'D'){
   move(1,from,'C');
   move(2,from,mid);
   move(3,from,to);
   move(2,mid,to);
   move(1,'C',to);
  }else{
   move(1,from,mid);
   move(2,from,'C');
   move(3,from,to);
   move(2,'C',to);
   move(1,mid,to);
  }
 }else{
  swap(n-2,from,mid);
  move(n-1,from,'C');
  move(n,from,to);
  move(n-1,'C',to);
  swap(n-2,mid,to);
 }
}

int main(){
    int n;
    cin >> n;
    swap(n,'A','D');
    return 0;
}