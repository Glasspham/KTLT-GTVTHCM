#include<iostream>
using namespace std;

int Tohop(int n, int k){
    if(n == k || k == 0) return 1;
    return Tohop(n - 1, k - 1) + Tohop(n - 1, k);
}

int main(){
    int n, k;
    cout << "Nhap vao to hop chap k cua n(n >= k)\n";
    do
    {
        cout << "Nhap n: ";
        cin >> n;
        if(n < 0) cout << "Nhap lai!\n";
    } while (n < 0);
    
    do
    {
        cout << "Nhap k: ";
        cin >> k;
        if(k < 0 || k > n) cout << "Nhap lai!\n";
    } while (k < 0 || k > n);
    
    cout << "C(" << k << "," << n << ") = " << Tohop(n, k);
    return 0;
}