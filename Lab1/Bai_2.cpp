#include<iostream>
using namespace std;
int main()
{
    int choice;
    do
    {
        double a, b;
        do
        {
            cout << "Nhap do dai 2 canh cua hinh chu nhat: ";
            cin >> a >> b;
            if(a < 0 || b < 0)
                cout << "Nhap sai! \n";
        } while (a < 0 || b < 0);
        cout << "Chu vi hinh hinh chu nhat: " << 2 * (a + b) << endl;
        cout << "Dien tich hinh hinh chu nhat: " << a * b << endl;
        cout << "Ban co muon tinh tiep khong (1:co / 0:khong): ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
