#include<iostream>
using namespace std;
void convertAndDisplay(long long int n, int base){
    string result = " ";
    while (n > 0)
    {
        int digit = n % base;
        char digitChar;
        if(digit < 10)
            digitChar = digit + '0';
        else 
            digitChar = digit - 10 + 'A';
        n /= base;
    }
    cout << "Base " << base << ": " << result << endl;
}

int main(){
    long long int num;
    int base;
    do
    {
        cout << "Nhap vao mot so nguyen bat ki: ";
        cin >> num;
        if(num < 0) cout << "Nhap lai!\n";
    } while (num < 0);
    cout << "Nhap co so: ";
    cin >> base;
    convertAndDisplay(num, base);
    return 0;
}