#include<iostream>
#include<math.h>
using namespace std;

struct Points
{
    double x,y;
    double distance(Points D)
    {
        return sqrt(pow(D.x - x,2) + pow(D.y - y,2));
    }
};

int main()
{
    Points A, B, C;
    cout << "Nhap vao toa do A(x,y): ";
    cin >> A.x >> A.y;
    cout << "Nhap vao toa do B(x,y): ";
    cin >> B.x >> B.y;
    cout << "Nhap vao toa do C(x,y): ";
    cin >> C.x >> C.y;
    double lenAB = A.distance(B);
    double lenAC = A.distance(C);
    double lenBC = B.distance(C);
    if(lenAB > 0 && lenAC > 0 && lenBC > 0 && lenAB + lenAC > lenBC && lenAB + lenBC > lenAC && lenAC + lenBC > lenAB)
    {
        float p = (lenAB + lenAC + lenBC) / 2;
        cout << "Chu vi tam giac ABC: " << p << endl;
        cout << "DIen tich tam giac ABC: " << sqrt(p * (p - lenAB) * (p - lenAC) * (p - lenBC));
    }
    else
        cout << "Khong ton tai tam gia ABC!";
    return 0;
}