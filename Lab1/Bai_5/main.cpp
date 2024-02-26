#include<iostream>
using namespace std;
int main()
{
    double toan, ly, hoa;
    int HesoToan, HesoLy, HesoHoa;
    cout << "Nhap diem & he so mon toan: ";
    cin >> toan >> HesoToan;
    cout << "Nhap diem & he so mon ly: ";
    cin >> ly >> HesoLy;
    cout << "Nhap diem & he so mon hoa: ";
    cin >> hoa >> HesoHoa;
    cout << "Diem trung binh cong: " << (toan * HesoToan + ly * HesoLy + hoa * HesoHoa) / (HesoToan + HesoLy + HesoHoa) << endl;
}