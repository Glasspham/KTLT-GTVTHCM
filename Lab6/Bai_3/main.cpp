#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    fstream file("1.txt", ios::out);
    for(int i : a) file << i << ' ';
    file.close();

    sort(a.begin(), a.end());
    file.open("2.txt", ios::out);
    for(int i : a) file << i << ' ';
    file.close();

    remove("1.txt");
    rename("2.txt", "sort.txt");

    file.open("sort.txt", ios::app);
    file << "2015";
    file.close();
    return 0;
}