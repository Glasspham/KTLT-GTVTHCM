#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

// Hàm tính khoảng cách giữa hai điểm
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Hàm kiểm tra hướng của ba điểm
int orientation(const Point& p1, const Point& p2, const Point& p3) {
    double val = (p2.y - p1.y) * (p3.x - p2.x) -
                 (p2.x - p1.x) * (p3.y - p2.y);

    if (val == 0) return 0;     // Các điểm thẳng hàng
    return (val > 0) ? 1 : 2;   // 1: Ngược chiều kim đồng hồ, 2: Theo chiều kim đồng hồ
}

// Hàm kiểm tra đa giác có phải là đa giác lồi hay không
bool isConvexPolygon(const vector<Point>& points) {
    int n = points.size();
    if (n < 3) return false;  // Ít nhất phải có 3 điểm để tạo thành một đa giác

    int prevOrientation = orientation(points[0], points[1], points[2]);

    for (int i = 1; i < n; i++) {
        int currentOrientation = orientation(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (currentOrientation != prevOrientation) {
            return false;  // Đa giác không là đa giác lồi
        }
    }

    return true;  // Đa giác là đa giác lồi
}

// Hàm tính diện tích của đa giác bằng phương pháp Gauss
double calculateArea(const vector<Point>& points) {
    int n = points.size();
    double area = 0.0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (points[i].x * points[j].y - points[j].x * points[i].y);
    }

    return abs(area) / 2.0;
}

// Hàm tính chu vi của đa giác
double calculatePerimeter(const vector<Point>& points) {
    int n = points.size();
    double perimeter = 0.0;

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        perimeter += distance(points[i], points[j]);
    }

    return perimeter;
}

int main() {
    int n;
    cout << "Nhap so diem n: ";
    cin >> n;

    if (n < 3 || n > 10) {
        cout << "So diem nhap vao khong hop le." << endl;
        return 1;
    }

    vector<Point> points(n);
    cout << "Nhap toa do cho " << n << " diem:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Diem " << i + 1 << ": ";
        cin >> points[i].x >> points[i].y;
    }

    if (isConvexPolygon(points)) {
        cout << "Day la mot da giac loi." << endl;
        cout << "Dien tich cua da giac: " << calculateArea(points) << endl;
        cout << "Chu vi cua da giac: " << calculatePerimeter(points) << endl;
    } else {
        cout << "Day khong phai la mot da giac loi." << endl;
    }

    return 0;
}