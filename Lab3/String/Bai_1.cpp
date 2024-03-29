#include<iostream>
#include <sstream>
using namespace std;

void ReverseString(string s){
    int len = s.length();
    for(int i = 0; i < len / 2; i++)
        swap(s[i], s[len - i - 1]);
    cout << "Chuoi sau khi dao nguoc la: " << s << endl;
}

void CountCharter(string s){
    int len = s.length();
    int count = 0;
    for(int i = 0; i < len; i++)
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
            count++;
    cout << "So ky tu trong chuoi la: " << count << endl;
}

void DelFirst(string &s){
    while (s[0] == ' ')
        s.erase(0, 1);
    cout << "Chuoi sau khi xoa ky tu dau tien la khoang trang!\n" << s << endl;
}

void DelEnd(string &s){
    while (s[s.length() - 1] == ' ')
        s.erase(s.length() - 1, 1);
}

void DelMid(string &s){
    int len = s.length();
    for(int i = 0; i < len; i++)
        if(s[i] == ' ' && s[i + 1] == ' ')
            s.erase(i, 1);
}

void UpperWordFrist(string &s){
    int len = s.length();
    if(s[0] >= 'a' && s[0] <= 'z')
        s[0] -= 32;
    for(int i = 1; i < len; i++)
        if(s[i] == ' ' && s[i + 1] >= 'a' && s[i + 1] <= 'z')
            s[i + 1] -= 32;
}

void ProcessString(string &s){
    #if 0
    DelEnd(s);
    DelMid(s);
    UpperWordFrist(s);
    #endif

    #if 1
    istringstream iss(s);
    string word;
    string res = "";
    while (iss >> word) {
        if(word[0] >= 'a' && word[0] <= 'z')
            word[0] -= 32;
        res += word + " ";
    }
    #endif
    cout << "Chuoi sau khi xu ly la: " << s << endl;

}

void CheckIsString(string &s){
    bool check = true;
    for (int i = 0; i < s.length(); i++)
        if(s[i] < 'A' || s[i] > 'z' || s[i] > 'Z' && s[i] < 'a')
            check = false;
    if(check)
        cout << "Chuoi nay la chuoi!\n";
    else
        cout << "Chuoi nay khong phai la chuoi!\n";
}

void DelIsnotString(string s){
    int i = 0;
    while (i < s.length()){
        if (!(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z'))
            s.erase(i, 1);
        else ++i;
    }
    cout << "Sau khi xoa cac ky tu khong phai la chu cai!\n" << s << endl;
}

void ChangeCharter(string s){
    for(int i = 0; i < s.length(); i++)
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = '*';
    cout << "Chuoi sau khi chuyen doi ky tu!\n" << s << endl;
}

void AddString(string s){
    s += " Hello";
    cout << "Chuoi sau khi them chuoi!\n" << s << endl;
}

int main(){
    string S;
    cout << "Nhap chuoi: ";
    getline(cin, S);
    return 0;
}