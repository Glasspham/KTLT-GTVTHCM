#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct point{
    double x,y;
};

struct segment{
    point p1, p2;
};

struct line{
    double a, b, c;
};

struct Parabola{
    double a, b, c;
    void Vertex(){
        cout << a << "x^2";
        if(b < 0) cout << "-" << -1*b << "x";
        else cout << "+" << b << "x";
        if(c < 0) cout << "-" << -1*c << endl;
        else cout << "+" << c << endl;
        double x = -b / (2 * a);
        double y = c - b * b / (4 * a);
        cout << "Vertex: (" << x << ", " << y << ")" << endl;
    }
};

struct Vector{
    point source, target;
};

struct Triangle{
    point A, B, C;
};

struct Rectangle{
    point topleft, topright, bottomleft, bottomright;
};

struct Circle{
    point center;
    double radius;
    void PerimeterAndArea(){
        cout << "Diameter: " << 2 * radius << endl;
        cout << "Perimeter: " << 2 * M_PI * radius << endl;
    }
};

struct ConvexPolygon{
    vector<point> vertices;
};

point Input(){
    point p;
    cout << "Enter point(x,y): "; 
    cin >> p.x >> p.y;
    return p; 
}

double Distance(point A, point B){
    return sqrt((A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y));
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
bool isConvexPolygon(const ConvexPolygon& points){
    int n = points.vertices.size();
    int prevOrientation = orientation(points.vertices[0], points.vertices[1], points.vertices[2]);
    for (int i = 1; i < n; i++){
        int currentOrientation = orientation(points.vertices[i], points.vertices[(i + 1) % n], points.vertices[(i + 2) % n]);
        if (currentOrientation != prevOrientation || currentOrientation == 0) 
            return false;  // Đa giác không là đa giác lồi
    }
    return true;  // Đa giác là đa giác lồi
}

bool isConvexRectangle(Rectangle rect){
    double a = Distance(rect.topleft, rect.topright);
    double b = Distance(rect.topleft, rect.bottomleft);
    double c = Distance(rect.bottomleft, rect.bottomright);
    double d = Distance(rect.topright, rect.bottomright);
    if(a != c || b != d) return false;
    return true;
}

double distancePointToLine(line l, point p){
    return abs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

string triangleType(Triangle tri){
    if(areCollinear(tri.A, tri.B, tri.C)) return "Not a Triangle";
    double a = Distance(tri.B, tri.C);
    double b = Distance(tri.A, tri.C);
    double c = Distance(tri.A, tri.B);
    if (a == b && b == c) return "Equilateral Triangle";
    if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b){
        if(a == b || b == c || c == a) return "Isosceles Right Triangle";
        return "Right Triangle";
    }
    if (a == b || b == c || c == a) return "Isosceles Triangle";
    return "Regular Rriangle";
}

double angleBetweenVectors(Vector v1, Vector v2){
    double dotProduct = (v1.target.x - v1.source.x) * (v2.target.x - v2.source.x) + (v1.target.y - v1.source.y) * (v2.target.y - v2.source.y);
    double magnitude1 = Distance(v1.source, v1.target);
    double magnitude2 = Distance(v2.source, v2.target);
    return acos(dotProduct / (magnitude1 * magnitude2));
}

double areaOfTriangle(Triangle tri){
    double a = Distance(tri.B, tri.C);
    double b = Distance(tri.A, tri.C);
    double c = Distance(tri.A, tri.B);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double perimeterOfTriangle(Triangle tri){
    double a = Distance(tri.B, tri.C);
    double b = Distance(tri.A, tri.C);
    double c = Distance(tri.A, tri.B);
    return a + b + c;
}

double areaOfRectangle(Rectangle rect){
    double a = Distance(rect.topleft, rect.topright);
    double b = Distance(rect.topleft, rect.bottomleft);
    return a * b;
}

double perimeterOfRectangle(Rectangle rect){
    double a = Distance(rect.topleft, rect.topright);
    double b = Distance(rect.topleft, rect.bottomleft);
    return 2 * (a + b);
}

double areaOfConvexPolygon(ConvexPolygon poly){
    double area = 0;
    int n = poly.vertices.size();
    for (int i = 0; i < n; i++){
        area += poly.vertices[i].x * poly.vertices[(i + 1) % n].y - poly.vertices[i].y * poly.vertices[(i + 1) % n].x;
    }
    return 0.5 * abs(area);
}

double perimeterOfConvexPolygon(ConvexPolygon poly){
    double perimeter = 0;
    int n = poly.vertices.size();
    for (int i = 0; i < n; i++)
        perimeter += Distance(poly.vertices[i], poly.vertices[(i + 1) % n]);
    return perimeter;
}

int main() {
    int choice;
    do
    {
        cout << "Segment(1)\nLine(2)\nParabola(3)\nVector(4)\nTriangle(5)\nRectangle(6)\nCircle(7)\nConvex Polygon(8)\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 0) break;
        else if(choice == 1){
            segment s;
            cout << "Enter the first point of the segment(x,y): ";
            cin >> s.p1.x >> s.p1.y;
            cout << "Enter the second point of the segment(x,y): ";
            cin >> s.p2.x >> s.p2.y;
            cout << "Length of the segment: " << Distance(s.p1, s.p2) << endl;
        }
        else if(choice == 2){
            line l;
            cout << "Enter the coefficients of the line(ax+by+c=0): ";
            cin >> l.a >> l.b >> l.c;
            cout << "Enter the point(x,y): ";
            point p = Input();
            cout << "Distance from the point to the line: " << distancePointToLine(l, p) << endl;
        }
        else if(choice == 3){
            Parabola P;
            cout << "Enter the coefficients of the parabola(ax^2+bx+c=0): ";
            cin >> P.a >> P.b >> P.c;
            P.Vertex();
        }
        else if(choice == 4){
            Vector v1, v2;
            cout << "Enter the source of the first vector(x,y): ";
            cin >> v1.source.x >> v1.source.y;
            cout << "Enter the target of the first vector(x,y): ";
            cin >> v1.target.x >> v1.target.y;
            cout << "Enter the source of the second vector(x,y): ";
            cin >> v2.source.x >> v2.source.y;
            cout << "Enter the target of the second vector(x,y): ";
            cin >> v2.target.x >> v2.target.y;
            cout << "Angle between two vectors: " << angleBetweenVectors(v1, v2) << endl;
        }
        else if(choice == 5){
            Triangle tri;
            cout << "Enter the first point of the triangle(x,y): ";
            cin >> tri.A.x >> tri.A.y;
            cout << "Enter the second point of the triangle(x,y): ";
            cin >> tri.B.x >> tri.B.y;
            cout << "Enter the third point of the triangle(x,y): ";
            cin >> tri.C.x >> tri.C.y;
            if(areCollinear(tri.A, tri.B, tri.C)) cout << "Not a triangle" << endl;
            else{
                cout << "Type of the triangle: " << triangleType(tri) << endl;
                cout << "Area of the triangle: " << areaOfTriangle(tri) << endl;
                cout << "Perimeter of the triangle: " << perimeterOfTriangle(tri) << endl;
            }
        }
        else if(choice == 6){
            Rectangle rect;
            cout << "Enter the top left point of the rectangle(x,y):\n";
            cin >> rect.topleft.x >> rect.topleft.y;
            cout << "Enter the top right point of the rectangle(x,y):\n";
            cin >> rect.topright.x >> rect.topright.y;
            cout << "Enter the bottom left point of the rectangle(x,y):\n";
            cin >> rect.bottomleft.x >> rect.bottomleft.y;
            cout << "Enter the bottom right point of the rectangle(x,y):\n";
            cin >> rect.bottomright.x >> rect.bottomright.y;
            if(isConvexRectangle(rect)){
                cout << "Area of the rectangle: " << areaOfRectangle(rect) << endl;
                cout << "Perimeter of the rectangle: " << perimeterOfRectangle(rect) << endl;
            }
            else cout << "Not a rectangle" << endl;
        }
        else if(choice == 7){
            Circle c;
            cout << "Enter the center of the circle: ";
            cin >> c.center.x >> c.center.y;
            cout << "Enter the radius of the circle: ";
            cin >> c.radius;
            c.PerimeterAndArea();
        }
        else if(choice == 8){
            ConvexPolygon poly;
            int n;
            cout << "Enter the number of vertices: ";
            cin >> n;
            for(int i = 0; i < n; i++){
                cout << "Enter the vertex " << i + 1 << ": ";
                point p = Input();
                poly.vertices.push_back(p);
            }
            if(isConvexPolygon(poly)){
                cout << "Area of the convex polygon: " << areaOfConvexPolygon(poly) << endl;
                cout << "Perimeter of the convex polygon: " << perimeterOfConvexPolygon(poly) << endl;
            }
            else cout << "Not a convex polygon" << endl;
        }
        else cout << "Invalid choice" << endl;
        cout << "You want to continue(1/0): ";
        cin >> choice;
    } while (choice != 0);
    return 0;
}