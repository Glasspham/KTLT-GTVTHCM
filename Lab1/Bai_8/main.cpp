#include<iostream>
using namespace std;
int main()
{
    double km;
    cin >> km;
    if(km < 2)
        cout << km * 15000 * (1 + 0.1);
    else
        cout << (15000 + (km - 1) * 12000) * (1 + 0.1);
}