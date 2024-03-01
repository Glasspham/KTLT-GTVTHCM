#include<iostream>
using namespace std;
int main()
{
    int choice;
    do
    {
        int a, b, c;
        cout << "Nhap gia a b c: ";
        cin >> a >> b >> c;
        cout << "Tong a b c: " << a + b + c << endl;
        cout << "Tich a b c: " << a * b * c << endl;
        cout << "Ban co muon tinh tiep khong (1:co / 0:khong): ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
