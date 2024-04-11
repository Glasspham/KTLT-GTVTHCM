#include <iostream>
#include <map>
using namespace std;
void cpd(int *&a, int n){
    a = new int[n];
}

void nhap(int *&a, int n){
    for(int i = 0; i < n; ++i)
        cin >> *(a+i);
}

void findDuplicates(int *a, int n){
    bool f = true;
    for(int i  = 0; i < n; ++i){
        int *cnt = new int(1);
        for(int j = i + 1; j < n; ++j){
            if(*(a + i) == *(a + j) && *(a + i) != -1){
                f = false;
                ++(*cnt);
                *(a + j) = -1;
            }
        }
        if(*cnt > 1)
            cout << "So " << *(a + i) << " xuat hien " << *cnt << " lan" << endl;
    }
    if(f) cout << "Khong co so trung nhau" << endl;
}

int main() {
    int n, *a;
    do{
        cin >> n;
        if(n < 0) cout << "Nhap lai n: ";
    } while (n < 0);
    cpd(a,n); nhap(a,n);
    findDuplicates(a,n);
    delete[] a;
    return 0;
}