#include<iostream>
using namespace std;
int main()
{
    char s1, s2;
    cout << "Nhap vao 2 K, B, O (Keo, Bua, Bao): ";
    cin >> s1 >> s2;
    if (s1 == s2)
        cout << "Hoa nhau! \n";
    else if((s1 == 'K' && s2 == 'O') || (s1 == 'B' && s2 == 'K') || (s1 == 'O' && s2 == 'B'))
        cout << "Nguoi choi 1 thang! \n";
    else    cout << "Nguoi choi 2 thang! \n";
    return 0;
}
