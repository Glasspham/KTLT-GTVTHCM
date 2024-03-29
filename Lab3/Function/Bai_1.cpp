#include<iostream>
using namespace std;

void LatNguocSo(int n){
    if(n == 0) return;
    cout << n % 10;
    LatNguocSo(n / 10);
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "So " << n << " lat nguoc la: ";
    LatNguocSo(n);
    return 0;
}