#include<iostream>
using namespace std;
int main()
{
    int time_begin, time_end;
    do
    {
        cout << "Nhap vao thoi gian bat dau hat (time >= 8): ";
        cin >> time_begin;
        if(time_begin < 8) cout << "Nhap lai! \n";
    } while (time_begin < 8);
    do
    {
        cout << "Nhap vao thoi gian bat dau hat (time <= 24): ";
        cin >> time_end;
        if(time_end > 24) cout << "Nhap lai! \n";
    } while (time_end > 24);
    int time = time_end - time_begin; 
    int tien;
    if (time <= 3)
        tien = time * 30000;
    else
        tien = 30000 * 3 + (((time - 3) * 30000 * 70) / 100);
    
    if(time_begin >= 8 && time_end <= 17)
        tien = (tien * 90) / 100;
    cout << tien << " dong! \n";
    return 0;
}