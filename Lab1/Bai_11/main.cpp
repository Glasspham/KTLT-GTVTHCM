#include<iostream>
#include<math.h>
using namespace std;
#if 1
struct point
{
    double x, y, z;
};

int main()
{
    point A;
    cout << "Nhap toa do diem A(x,y,z): ";
    cin >> A.x >> A.y >> A.z;

    double a, b, c, d;
    cout << "Nhap cac he so mp(P): ";
    cin >> a >> b >> c >> d;
    cout << "Khoang cach tu A den mp (P): " << abs(a * A.x + b * A.y + c * A.z + d) / sqrt(pow(a,2) + pow(b,2) + pow(c,2)) << endl;
}
#endif

#if 1
int main()
{
    double Ax, Ay, Az;
    cout << "Nhap toa do diem A(x,y,z): ";
    cin >> Ax >> Ay >> Az;
    double a, b, c, d;
    cout << "Nhap cac he so mp(P): ";
    cin >> a >> b >> c >> d;
    cout << "Khoang cach tu A den mp (P): " << abs(a * Ax + b * Ay + c * Az + d) / sqrt(pow(a,2) + pow(b,2) + pow(c,2)) << endl;
    return 0;
}
#endif
