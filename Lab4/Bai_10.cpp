#include<iostream>
using namespace std;

void cpd(int *&a, int n){
    a = new int[n];
}

void nhap(int *&a, int n){
    for(int i = 0; i < n; ++i){
        cin >> *(a+i);
        if(*(a+i) < 0){
            cout << "Nhap lai!\n";
            --i;
        }
    }
}

void Find3ValueMax(int *a, int n){
    int max1 = a[0], max2 = a[0], max3 = a[0];
    for(int i = 1; i < n; ++i){
        if(*(a + i) > max1){
            max3 = max2;
            max2 = max1;
            max1 = *(a + i);
        }
        else if(*(a + i) > max2){
            max3 = max2;
            max2 = *(a + i);
        }
        else if(*(a + i) > max3)
            max3 = *(a + i);
    }
    cout << "3 gia tri cong lai lon nhat: " << max1 << " " << max2 << " " << max3;
}

int main(){
    int n, *a;
    do{
        cin >> n;
        if(n < 0) cout << "Nhap lai n: ";
    } while (n < 0);
    cpd(a, n); nhap(a, n);
    Find3ValueMax(a, n);
}