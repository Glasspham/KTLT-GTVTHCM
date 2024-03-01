#include<iostream>
#include<math.h>
using namespace std;
#if 1
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
#endif

#if 1
int main()
{
    int choice;
    do
    {
        double Ax, Ay, Bx, By;
        cout << "Nhap vao toa do A(x,y): ";
        cin >> Ax >> Ay;
        cout << "Nhap vao toa do B(x,y): ";
        cin >> Bx >> By;
        cout << "Do dai doan thang AB: " << sqrt(pow(Bx - Ax,2) + pow(By - Ay,2)) << endl;
        cout << "Ban co muon tinh tiep khong (1:co / 0:khong): ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
#endif
