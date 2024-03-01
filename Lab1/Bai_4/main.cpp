#include<iostream>
using namespace std;
int main()
{
    int choice;
    do
    {
        int quantity, price;
        do
        {
            cout << "Nhap so luong va gia tien: ";
            cin >> quantity >> price;
        } while (quantity < 0 || price < 0);
        cout << "Tien: " << quantity * price << endl;
        cout << "Thue gia tri gia tang: " << quantity * price * 10 / 100 << endl;
        cout << "Ban co muon tinh tiep khong (1:co / 0:khong): ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
