#include<iostream>
using namespace std;

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a % b);
}

int main(){
    int a, b, c;
    do
    {
        cout << "Nhap vao 3 so a b c (>0): ";
        if(a < 0 || b < 0 || c < 0) cout << "Nhap lai!\n";
    } while (a < 0 || b < 0 || c < 0);
    cout << "Tong USCLN(a,b) + USCLN(b,c) + USCLN(a,c) la: " << GCD(a,b) + GCD(b,c) + GCD(a,c);
}