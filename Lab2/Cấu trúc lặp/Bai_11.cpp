#include<iostream>
using namespace std;
int main()
{
    int cnt = 0;
    for(int i = 33; i <= 255; i++)
    {
        cout << char(i) << "\t";
        cnt ++;
        if(cnt % 10 == 0) cout << endl;
    }
    return 0;
}