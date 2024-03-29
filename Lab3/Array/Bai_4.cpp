#include<iostream>
#include<map>
#define MAX 10
using namespace std;

bool IsPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

void Input(int a[MAX][MAX], int &n){
    cout << "Nhap vao n: "; cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
}

void Outpu(int a[MAX][MAX], int n){
    cout << "--------------------\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void SumMainDiagonal(int a[MAX][MAX], int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i][i];
    cout << "Tong cac phan tu tren duong cheo chinh la: " << sum << endl;
}

void MaxElementMainDiagonal(int a[MAX][MAX], int n){
    int max = a[0][0];
    for(int i = 0; i < n; i++)
        if(a[i][i] > max) max = a[i][i];
    cout << "Phan tu lon nhat tren duong cheo chinh la: " << max << endl;
}

void ElemenNagativeSecondaryDiagonal(int a[MAX][MAX], int n){
    int count = 0;
    for(int i = 0; i < n; i++)
        if(a[i][n - i - 1] < 0) count++;
    cout << "So luong phan tu am tren duong cheo phu la: " << count << endl;
}

void CountIsPrime(int a[MAX][MAX], int n){
    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(IsPrime(a[i][i])) count++;
    cout << "So luong so nguyen to tren duong cheo chinh la: " << count << endl;
}

void CountElement(int a[MAX][MAX], int n){
    map<int, int> mp;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            mp[a[i][j]]++;
    int elementmax, cnt = -99999;
    for(auto it : mp){
        if(it.second > cnt){
            cnt = it.second;
            elementmax = it.first;
        }
    }
    cout << "So xuat hien nhieu nhat la: " << elementmax << " voi " << cnt << " lan xuat hien\n";
}

void RowCountMaxEvenNumber(int a[MAX][MAX], int n){
    int cntMax = -999999, index;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++)
            if(a[i][j] % 2 == 0)
                cnt++;
        if(cnt > cntMax){
            cntMax = cnt;
            index = i;
        }
    }
    cout << "Dong co so chan nhieu nhat: " << index << endl;
}

void RowCountMaxPrimeNumber(int a[MAX][MAX], int n){
    int cntMax = -999999, index;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++)
            if(IsPrime(a[i][j]))
                cnt++;
        if(cnt > cntMax){
            cntMax = cnt;
            index = i;
        }
    }
    cout << "Dong co so nguyen to nhieu nhat: " << index << endl;
}

void SumBorder(int a[][MAX], int n){
    int sum = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(i == 0 || j == 0 || i == n - 1 || j == n - 1)
                sum += a[i][j];
    cout << "Tong cac phan tu tren bien la: " << sum << endl;
}

int main(){
    int a[MAX][MAX], n;
    return 0;
}