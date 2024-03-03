#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    float a, b;
    cout << "Nhap vao 2 so bat ki: ";
    cin >> a >> b;
    cout << max(a, b);
    if(a < b) cout << b << endl;
    else cout << a << endl;
    return 0;
}