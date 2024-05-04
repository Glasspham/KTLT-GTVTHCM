#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    fstream file("input.txt",ios::in);
    vector<pair<string, float>> student_data;
    string temp;
    while (getline(file,temp)){
        stringstream ss(temp);
        string temp, fulle_name;
        float score;
        while (ss >> temp){
            if(isdigit(temp[0])){
                score = stof(temp);
                break;
            }
            fulle_name += temp + " ";
        }
        student_data.push_back({fulle_name, score});
    }
    file.close();
    file.open("output.txt", ios::out);
    for(auto i : student_data)
        if(i.second >= 7.0) 
            file << i.first << i.second << endl;
    file.close();
    return 0;
}