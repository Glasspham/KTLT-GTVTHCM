#include<iostream>
using namespace std;
int main()
{
    int cnt(0);
    for(int i = 3; i <= 100; i++)
        if(i % 3 == 0 || i % 7 == 0)
            ++cnt;
    cout << cnt << endl;
}