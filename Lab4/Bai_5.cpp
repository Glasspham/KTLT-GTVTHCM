#include<iostream>
using namespace std;

int* Length(char *fullname){
    int *length = new int(0);
    for(int i = 0; i < 50; ++i){
        if(*(fullname + i) != '\0')
            *length += 1;
        else break;
    }
    return length;
}

int *findChar(char *fullname, int &size){
    int *index = new int(-1);
    for(int i = 0; i < size; ++i)
        if(*(fullname + i) == ' ')
            *index = i;
    return index;
}

int main(){
    char *fullname = new char[50];
    cin.getline(fullname, 50, '\n');
    int *length = Length(fullname);
    int *start = findChar(fullname, *length);
    cout << "Ten la: ";
    for(int i = *start + 1; i < *length; ++i)
        cout << *(fullname + i);
    delete[] fullname, length, start;
    return 0;
}