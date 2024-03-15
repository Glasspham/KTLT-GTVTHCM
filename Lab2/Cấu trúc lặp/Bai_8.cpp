#include<iostream>
using namespace std;
#if 0
int main()
{
    int n = 10;
    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cout << i << " x " << j << " = " << i * j << endl;
}
#endif

#if 0
int main()
{
    int n = 10;
    for (int i = 1; i <= n - 1; i++) 
    {
        for(int j = 1; j <= n; j++) 
        {
            cout << i << " x " << j << " = " << i * j;
            if(j != n)
            {
                if(i * j >= 10) cout << " |  ";
                else cout << "  |  ";
            }
        }
        cout << endl;
    }
    return 0;
}
#endif

#if 0
int main()
{
    for(int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " x " << j << " = " << i * j;
            if(i * j < 10)
                cout << "   " ;
            else cout << "  ";
        }
        cout << endl;
    }
}
#endif
