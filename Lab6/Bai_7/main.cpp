#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream file("input.txt", ios::in);
    int m,n;
    file >> m >> n;
    int arr[m][n];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            file >> arr[i][j];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
    return 0;
}