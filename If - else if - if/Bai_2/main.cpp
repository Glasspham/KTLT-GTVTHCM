#include<iostream>
using namespace std;
int main()
{
    float toan, ly, hoa;
    do
    {
        cout << "Nhap diem toan: ";
        cin >> toan;
        if(toan < 0) cout << "Nhap lai! \n";
    } while (toan < 0);
    do
    {
        cout << "Nhap diem ly: ";
        cin >> ly;
        if(ly < 0) cout << "Nhap lai! \n";
    } while (ly < 0);
    do
    {
        cout << "Nhap diem hoa: ";
        cin >> hoa;
        if(hoa < 0) cout << "Nhap lai! \n";
    } while (hoa < 0);
    
    float tb = (toan + ly + hoa) / 3;
    if(tb < 5) cout << "Kem \n";
    else if(tb < 7) cout << "Trung binh \n";
    else if(tb < 8) cout << "Kha \n";
    else if(tb < 10) cout << "Gioi \n";
    else cout << "Xuat sac \n";
    return 0;
}