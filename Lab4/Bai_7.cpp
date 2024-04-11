#include<iostream>
using namespace std;

void cpd(int *&a, int n){
    a = new int[n];
}

void nhap(int *&a, int n){
    for(int i = 0; i < n; ++i)
        cin >> *(a+i);
}

void Sort(int *&a, int n){
    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            if(*(a + i) > *(a + j)){
                int tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
}

int* Merge(int *a, int n, int *b, int m, int &k){
    int i = 0, j = 0, *c = new int[n + m];
    k = 0;
    Sort(a,n); Sort(b,m);
    while (i < n && j < m){
        if(*(a + i) == *(b + j))
            ++i, ++j;
        if(*(a + i) < *(b + j))
            *(c + k++) = *(a + i++);
        if(*(a + i) > *(b + j)) 
            *(c + k++) = *(b + j++);
    }
    while (i < n)
        *(c + k++) = *(a + i++);
    while (j < m)
        *(c + k++) = *(b + j++);
    int *d = new int[k];
    for(int i = 0; i < k; ++i)
        *(d + i) = *(c + i);
    delete[] c;
    return d;
}

int main(){
    int n, *a; cin >> n;
    cpd(a,n); nhap(a,n);
    int m, *b; cin >> m;
    cpd(b,m); nhap(b,m);
    int k;
    int *c = Merge(a,n,b,m, k);
    cout << "Day sau khi gop lay phan tu khac nhau giua 2 mang: ";
    for(int i = 0; i < k; ++i)
        cout << *(c + i) << ' ';
    delete[] a, b, c;
    return 0;
}