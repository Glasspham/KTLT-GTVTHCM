#include<iostream>
#include<string.h>
using namespace std;

struct FullName{
    char name[50];
};

void InputListName(FullName listName[], int &n){
    cout << "Nhap so luong ho va ten: ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "Nhap ho va ten thu " << i + 1 << ": ";
        cin.getline(listName[i].name, 50);
    }
}

void OutputListName(FullName listName[], int n){
    for(int i = 0; i < n; i++)
        cout << listName[i].name << endl;
}

void Input(char s[], int &n){
    cout << "Nhap chuoi: ";
    cin.getline(s, 50);
    n = strlen(s);
}

void Output(char s[], int n){
    for(int i = 0; i < n; i++)
        cout << s[i];
    cout << endl;
}

void detachedFirstName(char s[], int n){
    char firtName[50];
    int len = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == ' ')
            break;
        firtName[len++] = s[i];
    }
    cout << "Ho la: ";
    Output(firtName, len);
}

void detachedLastName(char s[], int n){
    char lastName[50];
    int len = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == ' ')
            break;
        lastName[len++] = s[i];
    }
    cout << "Ten la: ";
    for(int i = len - 1; i >= 0; i--)
        cout << lastName[i];
}

void SortFullName(char s[], int n){
    for(int i = 0; i < n - 1; ++i)
        for(int j = i + 1; j < n; ++j)
            if(toupper(s[i]) > toupper(s[j]))
                swap(s[i], s[j]);
    cout << "Ho va ten sau khi sap xep la: ";
    Output(s, n);
}

void FindFirstNameList(FullName listName[], int n){
    char firstName[50];
    cout << "Nhap ho can tim: ";
    cin.getline(firstName, 50);
    int len = strlen(firstName);
    for(int i = 0; i < n; i++){
        int j = 0;
        for(j = 0; j < len; j++)
            if(listName[i].name[j] != firstName[j])
                break;
        if(j == len)
            cout << listName[i].name << endl;
    }
}

void FindMaxLastNameList(FullName listName[], int n){
    int LenmaxName = 0; 
    for(int i = 0; i < n; ++i){
        int cntCharterName = 0;
        int len = strlen(listName[i].name);
        for(int j = len - 1; j >= 0; --j){
            if(listName[i].name[j] == ' ')
                break;
            ++cntCharterName;
        }
        if(cntCharterName > LenmaxName)
            LenmaxName = cntCharterName;
    }

    cout << "Nhung nguoi co ten dai nhat la: ";
    for(int i = 0; i < n; ++i){
        int cntCharterName = 0;
        int len = strlen(listName[i].name);
        for(int j = len - 1; j >= 0; --j){
            if(listName[i].name[j] == ' ')
                break;
            ++cntCharterName;
        }
        if(cntCharterName == LenmaxName)
            cout << listName[i].name << endl;
    }
}

int main(){
    char s[50];
    int n;
    Input(s, n);
    SortFullName(s, n);
    FullName listName[20];
    int n;
    return 0;
}