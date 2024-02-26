#include<iostream>
using namespace std;
int main()
{
    int quantity, price;
    cout << "Nhap so luong va gia tien: ";
    cin >> quantity >> price;
    cout << "Tien: " << quantity * price << endl;
    cout << "Thue gia tri gia tang: " << quantity * price * 10 / 100 << endl;
}