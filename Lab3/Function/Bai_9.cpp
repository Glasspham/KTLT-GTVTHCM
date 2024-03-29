#include<iostream>
using namespace std;
double A[100], x;
int n;

double F(){
    double result = A[0], tmp = 1;
    for(int i = 1; i <= n; ++i){
        tmp *= x;
        result += tmp * A[i];
    }
    return result;
}

int main(){
    do
    {
        cout << "Nhap vao n: ";
        cin >> n;
        if(n < 0) cout << "Nhap lai!\n";
    } while (n < 0);
    cout << "Nhap vao x: ";
    cin >> x;
    cout << "Nhap vao gia tri cho tung phan tu trong mang A[i]!\n";
    for(int i = 0; i <= n; ++i)
        cin >> A[i];
    cout << "F(x) = " << F() << endl;
    return 0;
}