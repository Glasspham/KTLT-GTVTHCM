#include<iostream>
using namespace std;
int main()
{
    int n;
    do
    {
        cout << "Nhap vao mot so nguyen duong: ";
        cin >> n;
        if(n < 0) cout << "Nhap lai!\n";
    } while (n < 0);
    bool f = true;
    if(n <= 1) f = false;
    else
        for(int i = 2; i * i <= n; i++)
            if(n % i == 0)
                f = false;
    if(f) cout << "So vua nhap la so nguyen to!\n";
    else cout << "So vua nhap la khong phai so nguyen to!\n";
}