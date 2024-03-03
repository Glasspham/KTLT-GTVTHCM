#include<iostream>
#include<map>
using namespace std;
int main()
{
    int a[9] = {500, 200, 100, 50 , 20, 10, 5, 2, 1};
    int n;
    do
    {
        cout << "Nhap vao so tien can doi: ";
        cin >> n;
        if(n < 0) cout << "Nhap lai!\n";
    } while (n < 0);
    cout << "Tu " << n << " quy doi  thanh\n";
    int i = 0;
    map<int,int> mp;
    while (n)
    {
        while (n >= a[i])
        {
            n -= a[i];
            mp[a[i]]++;
        }
        ++i;
    } 
    for(pair<int,int> it : mp)
        if(it.second != 0)
            cout << it.first << " ngan dong x " << it.second << endl;
    return 0;
}