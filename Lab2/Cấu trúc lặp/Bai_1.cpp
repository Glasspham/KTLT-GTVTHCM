#include<iostream>
using namespace std;
int main()
{
    int n; 
    do
    {
        cout << "Nhap vao mot so nguyen duong: ";
        cin >> n;
        if(n < 0) cout << "Nhap lai! \n";
    } while (n < 0);
    long long gt = 1;
    if(n % 2 == 0)
        for(int i = 2; i <= n; i += 2)
            gt *= i;
    else
        for (int i = 1; i <= n; i += 2)
            gt *= i;
    cout << gt << endl;
}