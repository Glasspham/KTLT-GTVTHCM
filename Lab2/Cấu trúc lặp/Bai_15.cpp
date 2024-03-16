#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct point{
    double x,y;
};

// Hàm tính khoảng cách giữa hai điểm
double distance(const point& p1, const point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Hàm kiểm tra hướng của ba điểm
int orientation(const point& p1, const point& p2, const point& p3){
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    if (val == 0) return 0;     // Các điểm thẳng hàng
    return (val > 0) ? 1 : 2;   // 1: Ngược chiều kim đồng hồ, 2: Theo chiều kim đồng hồ
}

// Hàm kiểm tra đa giác có phải là đa giác lồi hay không
bool isConvexPolygon(const vector<point>& points){
    int n = points.size();
    int prevOrientation = orientation(points[0], points[1], points[2]);
    for (int i = 1; i < n; i++){
        int currentOrientation = orientation(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (currentOrientation != prevOrientation) 
            return false;  // Đa giác không là đa giác lồi
    }
    return true;  // Đa giác là đa giác lồi
}

// Hàm tính diện tích của đa giác bằng phương pháp Gauss
double calculateArea(const vector<point>& points){
    int n = points.size();
    double area = 0.0;
    for (int i = 0; i < n; i++){
        int j = (i + 1) % n;
        area += (points[i].x * points[j].y - points[j].x * points[i].y);
    }
    return abs(area) / 2.0;
}

// Hàm tính chu vi của đa giác
double calculatePerimeter(const vector<point>& points){
    int n = points.size();
    double perimeter = 0.0;
    for (int i = 0; i < n; i++){
        int j = (i + 1) % n;
        perimeter += distance(points[i], points[j]);
    }
    return perimeter;
}

int main(){
    int n;
    do{
        cout << "Nhap so luong diem: ";
        cin >> n;
        if(n <= 0 || n > 9) cout << "Nhap lai! chi toi da 9 diem!\n";
    } while (n <= 0 || n > 9);
    vector<point> P(n);
    for(int i = 0; i < n; i ++){
        cout << "Nhap vao toa do diem thu " << i + 1 << ": ";
        cin >> P[i].x >> P[i].y;
    }
    if(n == 1) cout << "Chi co mot diem nen khong tao ra da giac!\n";
    else if (n == 2) cout << "2 diem nen tao ra mot duong thang co do dai la " << distance(P[0],P[1]) << endl;
    else if(n >= 3){    
        if(isConvexPolygon(P)){
            cout << "Day la mot da giac loi!\n";
            cout << "Dien tich cua da giac: " << calculateArea(P) << endl;
            cout << "Chu vi cua da giac: " << calculatePerimeter(P) << endl;
        }
        else cout << "Day khong phai la da giac loi!\n";
    }
    return 0;
}
