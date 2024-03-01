#include<iostream>
using namespace std;
int main()
{
    int choice;
    do
    {
        int km;
        do
        {
            cout << "Nhap so km di duoc: ";
            cin >> km;
            if(km < 0) cout << "Nhap sai! \n";
        } while (km < 0);
        cout << "So tien la: ";
        if(km == 0) cout << 0 << endl;
        if(km == 1)
            cout << 15000 * (1 + 0.1) << endl;
        else
            cout << (15000 + (km - 1) * 12000) * (1 + 0.1) << endl;
        cout << "Ban co muon tinh tiep khong (1:co / 0:khong): ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
