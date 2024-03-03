#include<iostream>
#define ll long long
using namespace std;
int main()
{
    int n; 
    do
    {
        cout << "Nhap vao mot so nguyen duong: ";
        cin >> n;
        if(n < 0) cout << "Nhap lai!\n";
    } while (n < 0);
    cout << "S(n) = 1 + 2 +...+ n = " << 1ll * (n * (1 + n) / 2) << endl;
    cout << "S(n) = 1 + 3 +...+ (2n+1) = " << 1ll * (n * n) << endl;
    cout << "S(n) = n! = ";
    int result = 1;
    for(int i = 2; i <= n; i++) result *= i;
    cout << result << endl;
    cout << "S(n) = 1/(2*3) + 1/(3*4) +...+(1/(n*(n+1))) = " << 1.0 / 2 - 1.0 / (n + 1)<< endl;
    return 0;
}