#include<iostream>
#include<iomanip>
#include<cstring>
#define MAXID 10 // Số ký tự tối đa của ID
#define MAXNAME 30 // Số ký tự tối đa của tên
using namespace std;

struct NgaySinh{
    int ngay, thang, nam;
};

struct SinhVien{
    char ID[MAXID];
    char ten[MAXNAME];
    NgaySinh bd;
    float diemTb;
};

struct LopHoc{
    SinhVien *sv;
    int size;
};

void createLopHoc(LopHoc &lop, int size){
    lop.sv = new SinhVien[size];
    lop.size = size;
}

void ProcessName(char *s){
    for(int i = 0; i < strlen(s); ++i){
        if(*(s + i) == ' ' && *(s + i + 1) == ' '){
            for(int j = i; j < strlen(s); ++j)
                *(s + j) = *(s + j + 1);
            i -= 1;
        }
    }
    while(*(s) == ' ')
        for(int i = 0; i < strlen(s); ++i)
            *(s + i) = *(s + i + 1);
    while (*(s + strlen(s) - 1) == ' ')
        *(s + strlen(s) - 1) = '\0';
    if(*(s) >= 'a' && *(s) <= 'z')
        *(s) -= 32;
    for(int i = 0; i < strlen(s) - 1; ++i){
        if(*(s + i) == ' ' && *(s + i + 1) >= 'a' && *(s + i + 1) <= 'z')
            *(s + i + 1) -= 32;
        else if(*(s + i) != ' ' && *(s + i + 1) >= 'A' && *(s + i + 1) <= 'Z')
            *(s + i + 1) += 32;
    }
}

bool NamNhuan(int nam){
    return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
}

int NgayTrongThang(int thang, int nam){
    if(thang == 2){
        if(NamNhuan(nam))
            return 29;
        return 28;
    }
    if(thang == 4 || thang == 6 || thang == 9 || thang == 11)
        return 30;
    return 31;
}

void InputBrithDay(NgaySinh &bd){
    do{
        cout << "Nhap nam sinh: ";
        cin >> bd.nam;
        if(bd.nam < 0) 
            cout << "Nam sinh khong hop le. Vui long nhap lai\n";
    }while (bd.nam < 0);
    do{
        cout << "Nhap thang sinh: ";
        cin >> bd.thang;
        if(bd.thang < 1 || bd.thang > 12) 
            cout << "Thang sinh khong hop le. Vui long nhap lai\n";
    }while (bd.thang < 1 || bd.thang > 12);
    do{
        cout << "Nhap ngay sinh: ";
        cin >> bd.ngay;
        if(bd.ngay < 1 || bd.ngay > NgayTrongThang(bd.thang, bd.nam)) 
            cout << "Ngay sinh khong hop le. Vui long nhap lai\n";
    }while (bd.ngay < 1 || bd.ngay > NgayTrongThang(bd.thang, bd.nam));
}

string ProcessBrithDay(NgaySinh bd){
    string s = "";
    if(bd.ngay < 10)
        s += "0";
    s += to_string(bd.ngay) + "/";
    if(bd.thang < 10)
        s += "0";
    s += to_string(bd.thang) + "/" + to_string(bd.nam);
    return s;
}

void inputSV(SinhVien *s){
    cout << "Nhap ID: ";
    cin.ignore();
    cin.getline(s->ID, MAXID, '\n');
    cout << "Nhap ten: ";
    cin.getline(s->ten, MAXNAME);
    ProcessName(s->ten);
    InputBrithDay(s->bd);
    do{
        cout << "Nhap diem TB: ";
        cin >> s->diemTb;
        if(s->diemTb < 0 || s->diemTb > 10) 
            cout << "Diem TB khong hop le. Vui long nhap lai\n";
    }while (s->diemTb < 0 || s->diemTb > 10);
}

void outputSV(SinhVien *s){
    cout << left << setw(MAXID) << "ID" << setw(MAXNAME) << "Ten" << setw(15) << "Ngay sinh" << setw(10) << "Diem TB" << endl;
    cout << left << setw(MAXID) << s->ID << setw(MAXNAME) << s->ten << setw(15) << ProcessBrithDay(s->bd) << setw(10) << fixed << setprecision(2) << s->diemTb << endl;
}

void inputLopHoc(LopHoc &lop){
    for(int i = 0; i < lop.size; i++){
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        inputSV(lop.sv + i);
    }
}

void outputLopHoc(LopHoc lop){
    for(int i = 0; i < lop.size; i++){
        cout << "Thong tin sinh vien thu " << i + 1 << endl;
        outputSV(lop.sv + i);
    }
}

float diemTBLop(LopHoc lop){
    float sum = 0;
    for(int i = 0; i < lop.size; i++)
        sum += (lop.sv + i)->diemTb;
    return sum / lop.size;
}

void diemTBMax(LopHoc lop){
    float max = (lop.sv)->diemTb;
    for(int i = 0; i < lop.size; i++)
        if((lop.sv + i)->diemTb > max)
            max = (lop.sv + i)->diemTb;
    for(int i = 0; i < lop.size; i++)
        if((lop.sv + i)->diemTb == max)
            outputSV(lop.sv + i);
}

void diemTBMin(LopHoc lop){
    float min = (lop.sv)->diemTb;
    for(int i = 0; i < lop.size; i++)
        if((lop.sv + i)->diemTb < min)
            min = (lop.sv + i)->diemTb;
    for(int i = 0; i < lop.size; i++)
        if((lop.sv + i)->diemTb == min)
            outputSV(lop.sv + i);
}

void timSVID(LopHoc lop, char *ID){
    bool find = false;
    for(int i = 0; i < lop.size; i++)
        if(strcmp((lop.sv + i)->ID, ID) == 0){
            outputSV(lop.sv + i);
            find = true;
        }
    if(!find) cout << "Khong tim thay sinh vien co ID " << ID << endl;
}

void sortByTotalScore(SinhVien *sv, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (sv[j].diemTb < sv[j + 1].diemTb) {
                // Hoán đổi thông tin của hai sinh viên
                SinhVien temp = sv[j];
                sv[j] = sv[j + 1];
                sv[j + 1] = temp;
            }
        }
    }
}

void Menu(){
    cout << "==============================MENU============================\n";
    cout << "1. Nhap thong tin sinh vien lop hoc\n";
    cout << "2. Hien thi tat ca sinh vien\n";
    cout << "3. Tinh diem trung binh cua lop hoc\n";
    cout << "4. Hien thi sinh vien co tong diem cao nhat\n";
    cout << "5. Hien thi sinh vien co tong diem thap nhat\n";
    cout << "6. Tim sinh vien boi ID\n";
    cout << "7. Sap xep cac ban ghi boi tong diem thi cua sinh vien\n";
    cout << "Nhap lua chon: ";
}

int main(){
    LopHoc lop;
    int size, choice;
    do{
        Menu();
        cin >> choice;
        cout << "--------------------------------------------------------------\n";
        switch (choice){
        case 1:
            cout << "Nhap so sinh vien: ";
            cin >> size;
            createLopHoc(lop, size);
            inputLopHoc(lop);
            break;
        case 2:
            cout << "Danh sach sinh vien la: \n";
            outputLopHoc(lop);
            break;
        case 3:
            cout << "Diem trung binh cua lop hoc la: " << fixed << setprecision(2) << diemTBLop(lop) << endl;
            break;
        case 4:
            cout << "Sinh vien co diem cao nhat la: \n";
            diemTBMax(lop);
            break;
        case 5:
            cout << "Sinh vien co diem thap nhat la: \n";
            diemTBMin(lop);
            break;
        case 6:
            char ID[MAXID];
            cout << "Nhap ID can tim: ";
            cin.ignore();
            cin.getline(ID, MAXID);
            timSVID(lop, ID);
            break;
        case 7:
            cout << "Sap xep sinh vien theo diem trung binh giam dan: \n";
            sortByTotalScore(lop.sv, lop.size);
            outputLopHoc(lop);
            break;
        default:
            cout << "Ket thuc chuong trinh\n";
            delete[] lop.sv;
            break;
        }
    } while (choice >= 1 && choice <= 7);
    return 0;
}
