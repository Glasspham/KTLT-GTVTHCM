#include<iostream>
#include<cmath>
#include<algorithm>
#define MAX 100
using namespace std;

bool IsPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0)
            return false;
    return true;
}

bool IsPerfectSquare(int n){
    if(sqrt(n) * sqrt(n) == n)
        return true;
    return false;
}

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

void CheckEven(int a[], int n){
    bool check = true;
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 != 0){
            cout << "Khong phai mang so chan!\n";
            check = false;
            break;
        }
    }
    if(check) cout << "Mang toan so chan!\n";
}

void PrintIsPrime(int a[], int n){
    cout << "Cac so nguyen to trong mang la: ";
    for(int i = 0; i < n; ++i)
        if(IsPrime(a[i]))
            cout << a[i] << ' ';
    cout << endl;
}

void CheckArrayIsSort(int a[], int n){
    bool checkIncrease = true, checkdecrease = true;
    for(int i = 0; i < n - 1; ++i)
        if(a[i] > a[i + 1])
            checkIncrease = false;
        
    for(int i = 0; i < n - 1; ++i)
        if(a[i] < a[i + 1])
            checkdecrease = false;
           
    if(checkIncrease) cout << "Mang duoc sap xep va sap xep tang dan!\n";
    else if(checkdecrease) cout << "Mang duoc sap xep va sap xep giam dan!\n";
    else cout << "Mang khong duoc sap xep!\n";
}

void DeleteElement(int a[], int &n, int pos){
    for(int i = pos; i < n - 1; ++i)
        a[i] = a[i + 1];
    --n;
}

void CheckLoopNumber(int a[], int n){
    bool check = false;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(a[i] == a[j]){
                check = true;
                DeleteElement(a,n,j);
                --j;
            }   
        }
    }
    if(check){
        cout << "Mang co phan tu trung nhau!\nVa mang da duoc xoa phan tu trung nhau!\n";
        Output(a,n);
    }
    else cout << "Mang khong co phan tu trung nhau!\n";
}

void QuantumEvenAndOdd(int a[], int n){
    int cntEven = 0, cntOdd = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 == 0) cntEven += 1;
        else cntOdd += 1;
    }
    if(cntEven > cntOdd) cout << "So luong so chan nhieu hon so le!\n";
    else if(cntEven < cntOdd) cout << "So luong so le nhieu hon so chan!\n";
    else cout << "So luong so chan bang so luong so le!\n";
}

void AddElement(int a[], int &n){
    if(n == MAX){
        cout << "Mang da day khong the them phan tu!\n";
        return;
    }
    int value, pos;
    cout << "Nhap vao gia tri can them: "; cin >> value;
    do
    {
        cout << "Nhap vao vi tri can them: "; cin >> pos;
        if(pos < 0 || pos > n)
            cout << "Vi tri khong hop le! Vui long nhap lai!\n";
    } while (pos < 0 || pos > n);
    for(int i = n; i > pos; --i)
        a[i] = a[i - 1];
    a[pos] = value;
    ++n;
}

void firstPrimeNumberWhoseFrontNumberIsPerfectSquare(int a[], int n){
    for(int i = 1; i < n; ++i){
        if(IsPrime(a[i]) && IsPerfectSquare(a[i - 1])){
                cout << "So nguyen to dau tien ma phia truoc no la so chinh phuong la: " << a[i] << endl;
                break;
        }
    }
}        

void separateIsnotPrimeNumber(int a[], int &n){
    int b[MAX], cnt = 0;
    cout << "Cac so khong phai la so nguyen to la: ";
    for(int i = 0; i < n; ++i){
        if(!IsPrime(a[i])){
            b[cnt] = a[i];
            ++cnt;
            DeleteElement(a,n,i);
            --i;
        }  
    }
    cout << "Mang ban dau sau khi xoa cac so khong phai la so nguyen to!\n";
    Output(a,n);
    cout << "Mang cac so khong phai la so nguyen to!\n";
    Output(b,cnt);
}

void FirstIncrease_ThenDecrease(int a[], int n){
    sort(a, a + n / 2);
    sort(a + n / 2, a + n, greater<int>());
    cout << "Mang sau khi sap xep tang dan truoc va giam dan sau!\n";
    Output(a,n);
}

void SortDecrease(int a[], int n){
    sort(a, a + n, greater<int>());
    cout << "Mang sau khi sap xep giam dan!\n";
    Output(a,n);
}

void AddElementDecrease(int a[], int &n){
    sort(a, a + n, greater<int>());
    int x; cout << "Nhap vao gia tri can them: "; cin >> x;
    int pos;
    for(int i = 0; i < n; ++i)
        if(a[i] > x){
            pos = i;
            break;
        }
    for(int i = n; i > pos; -- i)
        a[i] = a[i - 1];
    a[pos] = x;
    ++n;
}

void CheckSymmetry(int a[], int n){
    bool check = true;
    for(int i = 0; i < n / 2; ++i)
        if(a[i] != a[n - i - 1]){
            check = false;
            break;
        }
    if(check) cout << "Mang doi xung!\n";
    else cout << "Mang khong doi xung!\n";
}

int main(){
    int a[MAX], n;
    return 0;
}