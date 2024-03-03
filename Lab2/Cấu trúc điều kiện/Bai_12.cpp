#include<iostream>
using namespace std;
int main()
{
    char c;
    cout << "Nhap vao mot ki tu bat ki: ";
    cin >> c;
    if(c >= 'a' && c <= 'z') cout << "La ki tu thuong!\n";
    else if(c >= 'A' && c <= 'Z') cout << "La ki tu in hoa!\n";
    else if(c >= '0' && c <= '9') cout << "La ki tu so\n";
    else cout << "La cac ki tu con lai!\n";
    return 0;
}