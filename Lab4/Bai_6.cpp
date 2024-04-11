#include<iostream>
using namespace std;

void cpd(int *&a, int n){
    a = new int[n];
}

void nhap(int *&a, int n){
    for(int i = 0; i < n; ++i)
        cin >> *(a+i);
}

int* merge(int *a, int n, int *b, int m){
    int i = 0, j = 0, *c = new int[n + m], k = 0;
    while (i < n && j < m){
        if(*(a + i) < *(b + j))
            *(c + k++) = *(a + i++);
        else *(c + k++) = *(b + j++);
    }
    while(i < n)
        *(c + k++) = *(a + i++);
    while(j < m)
        *(c + k++) = *(b + j++);
    return c;
}

int main(){
    int n, m, *a, *b; 
    do{
        cin >> n;
        if(n < 0) cout << "Nhap lai n: ";
    } while (n < 0);
    cpd(a,n); nhap(a,n);
    do{
        cin >> m;
        if(m < 0) cout << "Nhap lai m: ";
    } while (m < 0);
    cpd(b,m); nhap(b,m);
    int *c = merge(a, n, b, m);
    cout << "Day sau khi gop: ";
    for(int i = 0; i < n + m; ++i)
        cout << *(c + i) << ' ';
    delete[] a, b, c;
    return 0;
}