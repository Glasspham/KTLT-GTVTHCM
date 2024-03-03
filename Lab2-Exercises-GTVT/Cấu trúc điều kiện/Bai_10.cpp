#include<iostream>
using namespace std;
int main()
{
    float a, b;
    do
    {
        cout << "Nhap vao he so a&b cua pt (ax+b>0): ";
        cin >> a >> b;
        if(a == 0) cout << b << " > 0\nBat phuong trinh khong ton tai!\nNhap lai! \n";
    } while (a == 0);
    if(a > 0) cout << "Nghiem x > " << -b/a << endl;
    else cout << "Nghiem x < " << -b/a << endl;
    return 0;
}