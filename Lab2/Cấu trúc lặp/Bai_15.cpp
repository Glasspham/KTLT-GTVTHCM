#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

struct point{
    float x, y;
    float lengthSegment(point p){
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

struct line{
    float a, b, c;
};

// Nhập tọa độ điểm
point input(){
    point p;
    cout << "Enter point (x,y): ";
    cin >> p.x >> p.y;
    return p;
}

// Hàm tính khoảng cách từ điểm đến đường thẳng
float distanceFromPointToLine(point p, line l){
    return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(pow(l.a, 2) + pow(l.b, 2));
}

// Hàm tính góc giữa hai vector
float angleBetweenVectors(const vector<point>& points){
    if(points.size() != 4) return -1;
    point source1 = points[0], target1 = points[1], source2 = points[2], target2 = points[3];
    float dotProduct = (target1.x - source1.x) * (target2.x - source2.x) + (target1.y - source1.y) * (target2.y - source2.y);
    float magnitude1 = target1.lengthSegment(source1);
    float magnitude2 = target2.lengthSegment(source2);
    return acos(dotProduct / (magnitude1 * magnitude2));
}

// Hàm kiểm tra xem 3 điểm có tạo thành tam giác không
string triangleType(const vector<point>& points){
    point a = points[0], b = points[1], c = points[2];
    float ab = a.lengthSegment(b), bc = b.lengthSegment(c), ca = c.lengthSegment(a);
    if(ab == bc && bc == ca) return "Equilateral triangle";
    if(ab == bc || bc == ca || ca == ab){
        if(pow(ab, 2) + pow(bc, 2) == pow(ca, 2) || pow(bc, 2) + pow(ca, 2) == pow(ab, 2) || pow(ca, 2) + pow(ab, 2) == pow(bc, 2))
            return " Isosceles right triangle";
        return "Isosceles triangle";
    }
    if(pow(ab, 2) + pow(bc, 2) == pow(ca, 2) || pow(bc, 2) + pow(ca, 2) == pow(ab, 2) || pow(ca, 2) + pow(ab, 2) == pow(bc, 2))
        return "Right-angled triangle";
    return "Regular triangle";
}

// Hàm kiểm tra xem ba điểm có thẳng hàng không
bool areCollinear(const point& p1, const point& p2, const point& p3) {
    return (p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) == 0;
}

// Hàm kiểm tra hướng của ba điểm
int orientation(const point& p1, const point& p2, const point& p3){
    // Kiểm tra xem ba điểm có thẳng hàng không
    if(areCollinear(p1, p2, p3)) return 0;  // Trả về 0 nếu ba điểm thẳng hàng
    // Tính giá trị của biểu thức để xác định hướng của ba điểm
    int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
    return (val > 0) ? 1 : 2;   // 1: Ngược chiều kim đồng hồ, 2: Theo chiều kim đồng hồ
}

// Hàm kiểm tra đa giác có phải là đa giác lồi hay không
bool isConvexPolygon(const vector<point>& points){
    int n = points.size();
    int prevOrientation = orientation(points[0], points[1], points[2]);
    for (int i = 1; i < n; i++){
        int currentOrientation = orientation(points[i], points[(i + 1) % n], points[(i + 2) % n]);
        if (currentOrientation != prevOrientation || currentOrientation == 0) 
            return false;  // Đa giác không là đa giác lồi
    }
    return true;  // Đa giác là đa giác lồi
}

// Hàm tính diện tích của đa giác bằng phương pháp Gauss
float calculateArea(const vector<point>& points){
    int n = points.size();
    float area = 0.0;
    for (int i = 0; i < n; i++){
        int j = (i + 1) % n;
        area += (points[i].x * points[j].y - points[j].x * points[i].y);
    }
    return abs(area) / 2.0;
}

// Hàm tính chu vi của đa giác
float calculatePerimeter(const vector<point>& points){
    int n = points.size();
    float perimeter = 0.0;
    for (int i = 0; i < n; i++){
        int j = (i + 1) % n;
        point temp = points[i];
        perimeter += temp.lengthSegment(points[j]);
    }
    return perimeter;
}

int main(){
    int n; 
    cout << "Enter number of points: "; cin >> n;
    vector<point> P(n);
    for(int i = 0; i < n; i++){
        cout << "Point " << i + 1 << endl;
        P[i] = input();
    }
    if(n == 3 && isConvexPolygon(P)){
        cout << "Triangle type: " << triangleType(P) << endl;
    }
    else{
        cout << "Not a triangle\n";
    }
}
