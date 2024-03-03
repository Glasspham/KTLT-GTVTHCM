#include<iostream>
using namespace std;
int LCB = 650000;
int main()
{
    int TNCT;
    do
    {
        cout << "Nhap vao so thang (tham nien cong tac): ";
        cin >> TNCT;
        if(TNCT < 0) cout << "Nhap lai! \n";
    } while (TNCT < 0);
    int tien;
    if(TNCT < 12)
        tien = LCB * 1.92;
    else if(TNCT < 36)
        tien = LCB * 2.34;
    else if(TNCT < 60)
        tien = LCB * 3;
    else tien = LCB * 4.5;
    cout << tien << " dong! \n";
    return 0;
}