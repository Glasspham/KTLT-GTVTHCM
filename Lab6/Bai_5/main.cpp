#include<iostream>
#include<fstream>
using namespace std;

int main(){
    fstream file("Document.txt",ios::in);
    string longest_string;
    string current_string;
    while (getline(file, current_string)) 
        if (current_string.length() > longest_string.length()) 
            longest_string = current_string;
    file.close();     
    cout << "Xau dai nhat trong file: " << longest_string << endl;
    cout << "Do dai: " << longest_string.length() << " ky tu." << endl;
    return 0;
}