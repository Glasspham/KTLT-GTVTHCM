#include<iostream>
using namespace std;
#define pi 3.14
int main()
{
    int choice;
    do
    {
        double r;
        do
        {
            cout << "Nhap vao ban kinh hinh tron: ";
            cin >> r;
            if(r < 0) cout << "Nhap sai!";
        } while (r < 0);
        cout << "Chu vi hinh tron: " << 2 * r * pi << "\n";
        cout << "Dien tich hinh tron: " << r * r * pi << "\n";
        cout << "Ban co muon tinh tiep khong (1:co / 0:khong): ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
