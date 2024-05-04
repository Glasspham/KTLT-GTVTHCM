#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream file("SN.txt", ios::out);
    int cnt = 0;
    for(int i = 1; i <= 100; ++i){
        if(i < 10)
            file << ' ' << i << ' ';
        else
            file << i << ' ';
        ++cnt;
        if(cnt % 10 == 0 && i < 100) file << endl;
    }
    return 0;
}