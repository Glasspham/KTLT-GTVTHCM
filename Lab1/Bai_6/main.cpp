#include<iostream>
#include<math.h>
using namespace std;
struct point
{
    double x, y;
};

int main()
{
    point A, B;
    cout << "Nhap vao toa do A(x,y): ";
    cin >> A.x >> A.y;
    cout << "Nhap vao toa do B(x,y): ";
    cin >> B.x >> B.y;
    cout << "Do dai doan thang AB: " << sqrt(pow(B.x - A.x,2) + pow(B.y - A.y,2)) << endl;
}