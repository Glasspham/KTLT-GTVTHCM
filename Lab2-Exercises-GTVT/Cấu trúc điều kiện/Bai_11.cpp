#include<iostream>
using namespace std;
#define ll long long
inline ll GCD(ll a, ll b){ll tmp; while(b){tmp = b; b = a % b; a = tmp;} return a;}
#if 1
struct ps
{
    ll ts, ms;
};

int main()
{
    ps A, B;
    do
    {
        cout << "Nhap vao phan thu 1 (tu voi mau cach nhau dau cach): ";
        cin >> A.ts >> A.ms;
        if(A.ms == 0) cout << "Nhap lai!\n";
    } while (A.ms == 0);
    ll a = GCD(A.ts,A.ms);
    A.ts /= a, A.ms/= a;
    do
    {
        cout << "Nhap vao phan thu 2 (tu voi mau cach nhau dau cach): ";
        cin >> B.ts >> B.ms;
        if(B.ms == 0) cout << "Nhap lai!\n";
    } while (B.ms == 0);
    ll b = GCD(B.ts,B.ms);
    B.ts /= b, B.ms/= b;

    cout << "P1: " << A.ts << '/' << A.ms << endl;
    cout << "P2: " << B.ts << '/' << B.ms << endl;

    ll tstong = A.ts * B.ms + B.ts * A.ms;
    ll mstong = A.ms * B.ms;
    ll tong = GCD(tstong, mstong);
    tstong /= tong, mstong /= tong;
    cout << "Tong 2 phan so: " << tstong << '/' << mstong << endl;

    ll tshieu = A.ts * B.ms - B.ts * A.ms;
    ll mshieu = A.ms * B.ms;
    ll hieu = GCD(tshieu, mshieu);
    tshieu /= hieu, mshieu /= hieu;
    cout << "Hieu 2 phan so: " << tshieu << '/' << mshieu << endl;

    ll tstich = A.ts * B.ts;
    ll mstich = A.ms * B.ms;
    ll tich = GCD(tstich, mstich);
    tstich /= tich, mstich /= tich;
    cout << "Tich 2 phan so: " << tstich << '/' << mstich << endl;

    ll tsthuong = A.ts * B.ms;
    ll msthuong = A.ms * B.ts;
    ll thuong = GCD(tsthuong, msthuong);
    tsthuong /= thuong, msthuong /= thuong;
    cout << "Thuong 2 phan so: " << tsthuong << '/' << msthuong << endl;
    
    return 0;
}
#endif

#if 1
int main() {
    ll A_ts, A_ms, B_ts, B_ms;
    
    do {
        cout << "Nhap vao phan thu 1 (tu voi mau cach nhau dau cach): ";
        cin >> A_ts >> A_ms;
        if (A_ms == 0) cout << "Nhap lai!\n";
    } while (A_ms == 0);
    
    ll a = GCD(A_ts, A_ms);
    A_ts /= a, A_ms /= a;
    
    do {
        cout << "Nhap vao phan thu 2 (tu voi mau cach nhau dau cach): ";
        cin >> B_ts >> B_ms;
        if (B_ms == 0) cout << "Nhap lai!\n";
    } while (B_ms == 0);
    
    ll b = GCD(B_ts, B_ms);
    B_ts /= b, B_ms /= b;

    cout << "P1: " << A_ts << '/' << A_ms << endl;
    cout << "P2: " << B_ts << '/' << B_ms << endl;

    ll tstong = A_ts * B_ms + B_ts * A_ms;
    ll mstong = A_ms * B_ms;
    ll tong = GCD(tstong, mstong);
    tstong /= tong, mstong /= tong;
    cout << "Tong 2 phan so: " << tstong << '/' << mstong << endl;

    ll tshieu = A_ts * B_ms - B_ts * A_ms;
    ll mshieu = A_ms * B_ms;
    ll hieu = GCD(tshieu, mshieu);
    tshieu /= hieu, mshieu /= hieu;
    cout << "Hieu 2 phan so: " << tshieu << '/' << mshieu << endl;

    ll tstich = A_ts * B_ts;
    ll mstich = A_ms * B_ms;
    ll tich = GCD(tstich, mstich);
    tstich /= tich, mstich /= tich;
    cout << "Tich 2 phan so: " << tstich << '/' << mstich << endl;

    ll tsthuong = A_ts * B_ms;
    ll msthuong = A_ms * B_ts;
    ll thuong = GCD(tsthuong, msthuong);
    tsthuong /= thuong, msthuong /= thuong;
    cout << "Thuong 2 phan so: " << tsthuong << '/' << msthuong << endl;

    return 0;
}
#endif