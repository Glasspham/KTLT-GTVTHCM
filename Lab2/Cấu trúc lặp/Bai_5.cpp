#include<iostream>
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

    #if 0
    for(int i = 2; i * i <= n; i++)
    {
        while(n % i == 0)
        {
            cout << i << ' ';
            n /= i;
        }
    }
    if(n != 1)
        cout << n << endl;
    #endif

    #if 0
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            cout << i;
            int cnt(0);
            while(n % i == 0)
            {
                cnt++;
                n /= i;
            }
            cout << '(' << cnt << ") ";
        }
    }
    if(n != 1)
        cout << n << "(1)" << endl;
    #endif

    #if 0
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            int cnt(0);
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            cout << i << "^" << cnt;
            if(n != 1)
                cout << " * ";
        }
    }
    if(n != 1)
        cout << n << "^1";
    #endif

    #if 0
    for(int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cout << i;
            n /= i;
            if(n != 1)
                cout << "x";
        }
    }
    if(n != 1)
        cout << n << endl;
    #endif

    return 0;
}