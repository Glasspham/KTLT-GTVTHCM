#include<iostream>
#define MAX 100
using namespace std;

void Input(int a[], int &n){
    cout << "Nhap vao chieu dai mang: "; cin >> n;
    cout << "Nhap vao gia tri cua so phan tu do!\n";
    for(int i = 0; i < n; ++i)
        cin >> a[i];
}

void Output(int a[], int n){
    cout << "--------------------\n";
    for(int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << endl;
}

void Merge(int a[],int n, int b[], int m){
    int i = 0, j = 0;
    int ArrayMerge[MAX], len = 0;
    while (i < n && j < m){
        if(a[i] < b[j])
            ArrayMerge[len++] = a[i++];
        else
            ArrayMerge[len++] = b[j++];
    }
    while (i < n)
        ArrayMerge[len++] = a[i++];
    while (j < m)
        ArrayMerge[len++] = a[j++];
    cout << "Mang sau khi tron lai!\n";
    Output(ArrayMerge,len);
}

int main(){
    int a[MAX], b[MAX], n, m;
    return 0;
}