#include<iostream>
using namespace std;
int main()
{
    string name[10] = {"khong" ,"mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    int n;
    do 
    {
        cout << "Nhap vao mot so nguyen co 2 chu so: ";
        cin >> n;
        if ((-99 <= n && n <= -10) || (10 <= n && n <= 99)) 
            break;
        else 
            cout << "Nhap lai! \n";
    } while (true);
    
    if(n == 0)
        cout << name[0] << " hoac " << name[0] << ' ' << name[0] << endl;
    else if (n > 0)
    {
        int tmp1 = n % 10;
        int tmp2 = n / 10;
        if(tmp1 == 0)
            cout << name[tmp2] << " muoi " << endl;
        else
            cout << name[tmp2] << " muoi " << name[tmp1] << endl;
    }
    else
    {
        n = abs(n);
        int tmp1 = n % 10;
        int tmp2 = n / 10;
        if(tmp1 == 0)
            cout << "am " << name[tmp2] << " muoi " << endl;
        else
            cout << "am " << name[tmp2] << " muoi " << name[tmp1] << endl;
    }
    return 0;
}