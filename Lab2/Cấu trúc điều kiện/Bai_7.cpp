#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    float a, b, c; 
    cout << "Nhap vao 3 so bat ki (cach nhau boi dau cach): ";
    cin >> a >> b >> c;
    #if 0
    cout << "So lon nhat la: " << max({a,b,c}) << endl;
    cout << "So nho nhat la: " << min({a,b,c}) << endl;
    #endif 

    #if 1
    float value_max = a;
    float value_min = a;
    if(b > value_max) value_max = b;
    if(c > value_max) value_max = c;
    if(b < value_min) value_min = b;
    if(c < value_min) value_min = c;
    cout << "So lon nhat la: " << value_max << endl;
    cout << "So nho nhat la: " << value_min << endl;
    #endif
    return 0;
}