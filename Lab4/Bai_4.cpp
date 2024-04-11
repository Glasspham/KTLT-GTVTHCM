#include <iostream>
using namespace std;
void cpd(int *&a, int n){
    a = new int[n];
}

void nhap(int *&a, int n){
    for(int i = 0; i < n; ++i)
        cin >> *(a+i);
}

void findLongestIncreasingSubarray(int *a, int n){
    int countLength = 1, maxLength = 1, *currentPtr = &a[0], *maxPtr = &a[0];
    for (int i = 1; i < n; ++i){
        if (*(a + i) > *(a + i - 1)) 
            countLength++;
        else{
            countLength = 1;
            currentPtr = &a[i];
        }
        if (countLength > maxLength){
            maxLength = countLength;
            maxPtr = currentPtr;
        }
    }
    cout << "Day con tang dai nhat la: " << endl;
    for (int i = 0; i < maxLength; ++i)
        cout << *(maxPtr + i) << " ";
    cout << endl;
}

int main() {
     int n, *a;
    do{
        cin >> n;
        if(n < 0) cout << "Nhap lai n: ";
    } while (n < 0);
    cpd(a,n); nhap(a,n);
    findLongestIncreasingSubarray(a,n);
    delete[] a;
    return 0;
}
