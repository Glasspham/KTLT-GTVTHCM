#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float a,b,c;
    cout << "Nhap vao 3 he so cua phuong trinh (ax^2 + bx + c = 0): ";
    cin >> a >> b >> c;
    if(a == 0)
        cout << "la phuong trinh bac nhat va co nghiem la: " << -c/b;
    else
    {
        float delta = b * b - 4 * a * c;
        if(delta > 0)
        {
            float x1 = (-b + sqrt(delta)) / (2 * a);
            float x2 = (-b - sqrt(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem: \nx1 = " << x1 << "\nx2 = " << x2 << endl; 
        }
        else if(delta == 0)
        {
            float x = -b / (2 * a);
            cout << "Phuong trinh co nghiem kep: \nx1 = x2 = " << x << endl;
        }
        else
        {
            float xt = -b / (2 * a);
            float xa = sqrt(abs(delta)) / (2 * a);
            cout << "Phuong trinh co 2 nghiem ao: \nx1 = " << xt;
            if(xa < 0) cout << xa << 'i' << endl;
            else cout << "+" << xa << 'i' << endl;
            cout << "x2 = " << xt;
            if(xa > 0) cout << -1 * xa << 'i' << endl;
            else cout << "+" << -1 * xa << 'i' << endl;
        }
    }
    return 0;
}