#include<iostream>
#include<fstream>
using namespace std;

bool SNT(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return false;
    return true;
}

int main(){
    ofstream ofile("SNT.txt");
    int i = 0, cnt = 0;
    while(cnt < 50){
        if(SNT(i)){
            ofile << i << " ";
            ++cnt;
            if(cnt % 10 == 0) ofile << endl;
        }
        ++i;
    }
}