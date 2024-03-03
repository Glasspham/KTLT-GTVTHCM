#include<iostream>
using namespace std;
int main()
{
    int n;
    do
    {
        cout << "Nhap mot so bat ki: ";
        cin >> n;
        if(n < 0) cout << "Nhap lai so > 0! \n";
    } while (n < 0);
    if(n % 2 == 0) cout << "so chan";
    else cout << "so le";
    return 0;
}