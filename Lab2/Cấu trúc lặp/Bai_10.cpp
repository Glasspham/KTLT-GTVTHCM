#include<iostream>
using namespace std;
#if 0
int main()
{
    int a, b;
    do
    {
        cout << "Nhap vao 2 so nguyen duong bat ki: ";
        cin >> a >> b;
        if(a < 0 || b < 0) cout << "Nhap lai!\n";
    } while (a < 0 || b < 0);
    int a1 = a, b1 = b;
    cout << "UCLN(" << a << ',' << b << ") = ";
    while (b)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    cout << a << endl;
    cout << "BCNN(" << a1 << ',' << b1 << ") = " << (a1 * b1) / a << endl;
}
#endif

#if 0
int GCD(int a, int b)
{
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

int main()
{
    int a, b;
    do
    {
        cout << "Nhap vao 2 so nguyen duong bat ki: ";
        cin >> a >> b;
        if(a < 0 || b < 0) cout << "Nhap lai!\n";
    } while (a < 0 || b < 0);
    cout << "GCD(" << a << ',' << b << ") = " << GCD(a,b) << endl;
    cout << "LCM(" << a << ',' << b << ") = " << LCM(a,b) << endl;
}
#endif