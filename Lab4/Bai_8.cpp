#include<iostream>
using namespace std;

int* Length(char *S){
    int *length = new int(0);
    for(int i = 0; i < 50; ++i){
        if(*(S + i) != '\0')
            *length += 1;
        else break;
    }
    return length;
}

void Standardize_the_string(char *&S, int &size){
    for(int i = 0; i < size; ++i){
        if(*(S + i) == ' ' && *(S + i + 1) == ' '){
            for(int j = i; j < size; ++j)
                *(S + j) = *(S + j + 1);
            size -= 1;
            i -= 1;
        }
    }
    while(*(S) == ' ')
        for(int i = 0; i < size; ++i)
            *(S + i) = *(S + i + 1);
    while (*(S + size - 1) == ' ')
        size -= 1;
    if(*(S) >= 'a' && *(S) <= 'z')
        *(S) -= 32;
    for(int i = 0; i < size - 1; ++i){
        if(*(S + i) == ' ' && *(S + i + 1) >= 'a' && *(S + i + 1) <= 'z')
            *(S + i + 1) -= 32;
        else if(*(S + i) != ' ' && *(S + i + 1) >= 'A' && *(S + i + 1) <= 'Z')
            *(S + i + 1) += 32;
    }
    int *temp = new int[size];
    for(int i = 0; i < size; ++i)
        *(temp + i) = *(S + i);
    delete[] S;
    S = new char[size];
    for(int i = 0; i < size; ++i)
        *(S + i) = *(temp + i);
    delete[] temp;
}

int main(){
    char *S = new char[50];
    cin.getline(S, 50, '\n');
    int *length = Length(S);
    cout << "Standardize the string: ";
    Standardize_the_string(S, *length);
    for(int i = 0; i < *length; ++i)
        cout << *(S + i);
    delete[] S;
    return 0;
}