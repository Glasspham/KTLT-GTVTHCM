#include<iostream>
using namespace std;
#if 0
int main()
{
    float a[10001];
    int n;
    do
    {
        cout << "Nhap vao so luong sinh vien: ";
        cin >> n;
        if(n < 0) cout << "Nhap lai!\n";
    } while (n < 0);
    cout << "Nhap vao diem trung binh cua so luong sinh vien (cach nhau mot khoang cach): ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    float sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
    cout << "Diem trung binh cua " << n << " sinh vien la: " << sum / n << endl;
    return 0;
}
#endif

#if 1
int main()
{
    int n;
    do
    {
        cout << "Nhap vao so luong sinh vien: ";
        cin >> n;
        if(n < 0) cout << "Nhap lai!\n";
    } while (n < 0); 
    cout << "Nhap vao diem trung binh cua so luong sinh vien (cach nhau mot khoang cach): ";
    int tmp = n;
    float sum = 0, num;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
    }
    cout << "Diem trung binh cua " << tmp << " sinh vien la: " << sum / n << endl;
}
#endif