#include<iostream>
using namespace std;
int main()
{
int choice;
    do
    {
        float toan, ly, hoa;
        int HesoToan, HesoLy, HesoHoa;
        do
        {
            cout << "Nhap diem thi & he so mon toan: ";
            cin >> toan >> HesoToan;
            if(toan < 0 || HesoToan < 0)
                cout << "Nhap lai!";
        } while (toan < 0 || HesoToan < 0);
        do
        {
            cout << "Nhap diem thi & he so mon ly: ";
            cin >> ly >> HesoLy;
            if(ly < 0 || HesoLy < 0)
                cout << "Nhap lai!";
        } while (ly < 0 || HesoLy < 0);
        do
        {
            cout << "Nhap diem thi & he so mon hoa: ";
            cin >> hoa >> HesoHoa;
            if(hoa < 0 || HesoHoa < 0)
                cout << "Nhap lai!";
        } while (hoa < 0 || HesoHoa < 0);
        cout << "Diem trung binh cong: " << (toan * HesoToan + ly * HesoLy + hoa * HesoHoa) / (HesoToan + HesoLy + HesoHoa) << endl;
        cout << "Ban co muon tinh tiep khong (1:co / 0:khong): ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}
