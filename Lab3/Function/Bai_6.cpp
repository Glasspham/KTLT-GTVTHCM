#include<iostream>
#define ll long long
const int MOD = 1e9 + 7;
using namespace std;

void multiplication(ll a[2][2], ll b[2][2])
{
    ll res[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < 2; k++)
                res[i][j]  += a[i][k] * b[k][j] % MOD;
        }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = res[i][j];
}

ll Pow(ll n)
{
    ll res[2][2] = {{1, 0}, {0, 1}};
    ll a[2][2] = {{1, 1}, {1, 0}};
    while (n)
    {
        if(n % 2 == 1)
            multiplication(res, a);
        multiplication(a, a);
        n /= 2;
    }
    return res[0][1];
}

ll SumFiboEven(int m, int n){
    ll sum = 0;
    for(int i = m; i <= n; i++)
        if(Pow(i) % 2 == 0) 
            sum += Pow(i);
    return sum;
}

int main()
{
    int M, N; 
    do
    {
        cout << "Nhap vao doan [M, N] can xet: ";
        cin >> M >> N;
        if(N < 0 || M < 0 || M > N) cout << "Nhap lai!\n";
    } while (N < 0 || M < 0 || M > N);
    cout << "Tong cac so chan trong day Fibonacci tu F(" << M << ") den F(" << N << ") la: " << SumFiboEven(M, N);
}