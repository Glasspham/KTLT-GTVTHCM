#include <iostream>
using namespace std;
void cpd(int *&a, int n){
    a = new int[n];
}

void nhap(int *&a, int n){
    for(int i = 0; i < n; ++i)
        cin >> *(a+i);
}

int* Sum(int *a, int n){
    int *sum = new int(0);
    for(int i = 0; i < n; ++i)
        if(*(a + i) % 3 == 0)
            *sum += *(a + i);
    return sum;        
}

int main() {
    int n, *a; 
    do{
        cin >> n;
        if(n < 0) cout << "Nhap lai n: ";
    } while (n < 0);
    cpd(a,n); nhap(a,n);
    cout << *Sum(a,n) << endl;
    delete[] a;
    return 0;
}