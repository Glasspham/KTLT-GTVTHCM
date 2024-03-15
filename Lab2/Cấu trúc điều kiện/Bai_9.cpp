#include<iostream>
using namespace std;

int mian()
{
    double dtb;
    int n;
    do
    {
        cout << "So luong sinh vien: "; cin >> n;
        if(n < 0) cout << "Nhap lai so luong sinh vien!\n";
    } while (n < 0);
    
    for(int i = 0; i < n; i++)
    {
        do
        {
            cout << "Nhap diem trung binh sinh vien thu " << i << ": "; cin >> dtb;
            if(dtb < 0 || dtb > 10) cout << "Nhap lai diem trung binh!\n";
        } while (dtb < 0 || dtb > 10);
        if(dtb < 5) cout << "Kem!\n";
        else if(dtb < 7) cout << "Trung binh!\n";
        else if(dtb < 8) cout << "Kha!\n";
        else if(dtb < 10) cout << "Gioi!\n";
        else cout << "Xuat sac!\n";
    }
    return 0;
}