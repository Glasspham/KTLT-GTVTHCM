#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;

void Input(int a[][MAX], int &n, int &m) {
    cout << "Nhap vao m va n: ";
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];
}

void Output(int a[][MAX], int n, int m) {
    cout << "--------------------\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void QuantityNegative(int a[][MAX], int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (a[i][j] < 0) count++;
    cout << "So luong so am trong mang la: " << count << endl;
}

void ElementMax(int a[][MAX], int n, int m) {
    int max = a[0][0];
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            if (a[i][j] > max) max = a[i][j];
    cout << "Phan tu lon nhat trong mang la: " << max << endl;
}

void SumRow(int a[][MAX], int n, int m) {
    int MaxsumRow = -9999999;
    for (int i = 0; i < n; i++) {
        int sumRow = 0;
        for (int j = 0; j < m; j++) 
            sumRow += a[i][j];
        if(sumRow > MaxsumRow) MaxsumRow = sumRow;
    }
}

void SortRowIncrease(int a[][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {
                if (a[i][j] > a[i][k]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
    }
    Output(a, n, m);
}

void SortDecrease(int a[][MAX], int n, int m) {
    int temp[n * m];
    int k = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            temp[k++] = a[i][j];

    sort(temp, temp + n * m, std::greater<int>());

    k = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            a[i][j] = temp[k++];
    
    Output(a, n, m);
}

int main() {
    int a[MAX][MAX], n, m;
    return 0;
}