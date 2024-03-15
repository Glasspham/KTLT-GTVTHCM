#include<iostream>
#include<cmath>
using namespace std;

struct point
{
    double x,y;
    double distance(const point& z){
        return sqrt(pow(z.x - x,2) + pow(z.y - y, 2));
    }
};

int orientation(const point& p1, const point& p2, const point& p3) {
    double val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);

    if (val == 0) return 0;     // Các điểm thẳng hàng
    return (val > 0) ? 1 : 2;   // 1: Ngược chiều kim đồng hồ, 2: Theo chiều kim đồng hồ
}

// Hàm kiểm tra đa giác có phải là đa giác lồi hay không
bool isConvexPolygon(const vector<point>& points) {
    int n = points.size();
    if (n < 3) return false;  // Ít nhất phải có 3 điểm để tạo thành một đa giác

    int prevOrientation = ;

    for (int i = 1; i < n; i++) {
        int currentOrientation = orientation(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (currentOrientation != prevOrientation) {
            return false;  // Đa giác không là đa giác lồi
        }
    }

    return true;  // Đa giác là đa giác lồi
}

int main()
{
    point P[10];
    int n;
    do
    {
        cout << "Nhap so luong diem: ";
        cin >> n;
        if(n <= 0 || n > 9) cout << "Nhap lai! chi toi da 9 diem!\n";
    } while (n <= 0 || n > 9);

    for(int i = 0; i < n; i ++)
    {
        cout << "Nhap vao toa do diem thu " << i + 1 << ": ";
        cin >> P[i].x >> P[i].y;
    }

    if(n == 1) cout << "Chi co mot diem nen khong tao ra da giac!\n";
    else if (n == 2) cout << "2 diem nen tao ra mot duong thang co do dai la " <<  P[1].distance(P[2]) << endl;
    else if(n == 3)
    {
        double a = P[0].distance(P[1]), b = P[0].distance(P[2]), c = P[1].distance(P[2]);
        if(a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a)
        {
            cout << "3 diem nay tao len 1 tam giac!\n";
            double p = (a + b + c) / 2;
            double s = sqrt(p * (p - a) * (p - b) * (p - c));
            cout << "Dien tich cua tam giac do: " << s << endl;
            cout << "Chu vi tam cua tam giac do: " << p << endl;
        }
        else
            cout << "3 diem khong tao len tam giac vi 3 diem thang hang!\n";
    }
    else if(n == 4)
    {
        double a = P[0].distance(P[1]), b = P[0].distance(P[2]), c = P[1].distance(P[2]);
    }
}
