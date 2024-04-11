#include<iostream>
using namespace std;

int* Length(char *s){
    int *length = new int(0);
    for(int i = 0; i < 50; ++i){
        if(*(s + i) != '\0')
            *length += 1;
        else break;
    }
    return length;
}

char* MergeTwoString(char *s, char * t, int &k){
    int *length_s= Length(s);
    int *length_t = Length(t);
    char *result = new char[*length_s + *length_t];
    k = 0;
    for(int i = 0; i < *length_s; ++i)
        *(result + k++) = *(s + i);
    for(int i = 0; i < *length_t; ++i)
        *(result + k++) = *(t + i);
    return result;
    delete[] length_s, length_t, result;
}

int main(){
    char *s = new char[50];
    cin.getline(s, 50, '\n');
    char *t = new char[50];
    cin.getline(t, 50, '\n');
    int k;
    char *result = MergeTwoString(s, t, k);
    for(int i = 0; i < k; ++i)
        cout << *(result + i);
    delete[] s, t, result;
    return 0;
}