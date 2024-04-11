#include <iostream>
using namespace std;
void cpd(int *&a, int n){
    a = new int[n];
}

void nhap(int *&a, int n){
    for(int i = 0; i < n; ++i)
        cin >> *(a+i);
}

void getElement(int *a, int n, int x){
    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            if(*(a + i) > *(a + j)){
                int tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
    int i = 0, *sum = new int(0);
    while(*sum + *(a + i) < x && i < n){
        cout << *(a + i) << " ";
        *sum += *(a + i++);
    }
}

int main() {
    int n, *a, x;
    do{
        cin >> n >> x;
        if(n < 0) cout << "Nhap lai n: ";
    } while (n < 0);
    cpd(a,n); nhap(a,n);
    getElement(a,n,x);
    delete[] a;
    return 0;
}