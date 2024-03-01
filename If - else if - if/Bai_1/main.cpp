#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    cout << max({a,b,c,d}) << endl;

    int value = a;
    if(b > value) value = b;
    if(c > value) value = c;
    if(d > value) value = d;
    cout << value << endl;
}