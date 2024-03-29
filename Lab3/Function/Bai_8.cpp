#include<iostream>
using namespace std;

int GCD(int a, int b){
    if(b == 0) return a;
    return GCD(b, a % b);
}

int LCM(int a, int b){
    return a * b / GCD(a,b);
}

int main(){
    int a, b, c;
    do
    {
        cout << "Nhap vao 3 so a b c (>0): ";
        if(a < 0 || b < 0 || c < 0) cout << "Nhap lai!\n";
    } while (a < 0 || b < 0 || c < 0);
    cout << "Tong USCLN(a,b) + BSCNN(a,c) la: " << GCD(a,b) + LCM(a,c);
}