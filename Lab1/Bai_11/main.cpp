#include<iostream>
#include<math.h>
using namespace std;

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