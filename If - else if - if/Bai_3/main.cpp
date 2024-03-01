#include <iostream>
using namespace std;

bool XetNamNhuan(int n)
{
    if(n % 4 == 0 && n % 100 || n % 400 == 0)
        return true;
    return false;
}

int month(int m, int y)
{
    switch (m)
    {
        case 1:
        case 3:
        case 5:
        case 7: 
        case 8: 
        case 10:
        case 12: 
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if(XetNamNhuan(y))
                return 29;
            return 28;
    }
}

int main() 
{
    int ngay, thang, nam;
    cout << "Nhap nam: ";
    cin >> nam;
    do
    {
        cout << "Nhap thang: ";
        cin >> thang;
        if(thang < 0 || thang > 12) cout << "Nhap lai \n";
    } while (thang < 0 || thang > 12);
    cout << month(thang, nam) << endl;
    return 0;
}
 