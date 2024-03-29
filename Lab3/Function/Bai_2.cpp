#include<iostream>
using namespace std;

int LengthNumber(int n){
    if(n == 0) return 0;
    return 1 + LengthNumber(n / 10);
}

int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "So " << n << " co " << LengthNumber(n) << " chu so";
    return 0;
}