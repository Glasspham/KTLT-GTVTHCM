#include<iostream>
#define MAX 100
using namespace std;

int* Length(char *s){
    int *length = new int(0);
    for(int i = 0; i < MAX; ++i){
        if(*(s + i) != '\0')
            *length += 1;
        else break;
    }
    return length;
}

bool check(char *s){
    int *length = Length(s);
    char *temp = "Lap Trinh";
    int *length_temp = Length(temp);
    if(*length == *length_temp){
        for(int i = 0; i < *length; ++i)
            if(*(s + i) != *(temp + i)){
                delete[] length, length_temp, temp;
                return false;
            }
        delete[] length, length_temp, temp;
        return true;
    }
    delete[] length, length_temp, temp;
    return false;
}

int main(){
    char *s = new char[MAX];
    cin.getline(s, MAX, '\n');
    check(s) ? cout << "Yes" : cout << "No";
    delete[] s;
    return 0;
}