#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int choice;
    do
    {
        double a;
        do
        {
            cout << "Chieu dai 1 canh hinh vuong: ";
            cin >> a;
            if(a < 0) cout << "Nhap sai! \n";
        } while (a < 0);
        cout << "Chu vi hinh vuong: " << 2 * a << endl;
        cout << "Dien tich hinh vuong: " << a * a << endl;
        cout << "Do dai duong cheo hinh vuong: " << sqrt(2) * a << endl;
        cout << "Ban co muon tinh tiep khong (1:co / 0:khong): ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
