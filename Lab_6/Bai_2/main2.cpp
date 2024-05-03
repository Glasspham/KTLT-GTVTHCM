#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<sstream>
#include<iomanip>
#define MAX 100
using namespace std;

struct NhanVien{
    string ma;
    string hoTen;
    int soNgayCong;
    int luongCB;
    int tongLuong;
};

vector<NhanVien> dsNhanVien;

void printHeader(){
    cout << left << setw(11) << "Ma NV" << setw(26) << "Ho va ten" << setw(12) << "So ngay" << setw(16) 
    << "Luong CB" << setw(16) << "Tong luong" << endl;
}

void print(){
    cout << "======================================================" << endl;
}

void xu_Ly_Ten(string &s){
    while (s[0] == ' ') s.erase(0, 1);
    while (s[s.length() - 1] == ' ') s.erase(s.length() - 1, 1);
    for (int i = 0; i < s.length(); i++){
        if (s[i] == ' ' && s[i + 1] == ' '){
            s.erase(i, 1);
            i--;
        }
    }
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] -= 32;
}

// 1. Nhap danh sach nhan vien
void nhap_1_nhan_vien(NhanVien &nv){
    cin.ignore();
    cout << "Nhap ma: ";
    getline(cin, nv.ma);
    cout << "Nhap ho ten: ";
    string temp;
    getline(cin, temp);
    xu_Ly_Ten(temp);
    nv.hoTen = temp;
    cout << "Nhap so ngay cong: ";
    cin >> nv.soNgayCong;
    cout << "Nhap luong co ban: ";
    cin >> nv.luongCB;
    nv.tongLuong = nv.soNgayCong * nv.luongCB;
}

void nhap_ds_nhan_vien(){
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++){
        NhanVien nv;
        cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
        nhap_1_nhan_vien(nv);
        dsNhanVien.push_back(nv);
    }
}

// 2. Ghi danh sach ra file
void ghi_ds_ra_file(string tenFile){
    ofstream f(tenFile);
    for (int i = 0; i < dsNhanVien.size(); i++)
        f << dsNhanVien[i].ma << ' ' << dsNhanVien[i].hoTen << ' ' << dsNhanVien[i].soNgayCong << ' ' << dsNhanVien[i].luongCB << ' ' << dsNhanVien[i].tongLuong << endl;
    f.close();
    cout << "Da ghi ra file " << tenFile << endl;
}

// 3. Doc danh sach tu file va in ra man hinh
void doc_ds_tu_file(string tenFile){
    dsNhanVien.clear();
    ifstream f(tenFile);
    string line;
    while (getline(f, line)){
        stringstream ss(line);
        NhanVien nv;
        ss >> nv.ma;
        string temp;
        while(ss >> temp){
            if(isdigit(temp[0])) // Kiem tra xem temp[0] co phai la so nguyen khong
                break;
            if(nv.hoTen.empty())
                nv.hoTen = temp;
            else
                nv.hoTen += " " + temp;
        }
        // Đọc các trường còn lại
        nv.soNgayCong = stoi(temp);
        ss >> nv.luongCB >> nv.tongLuong;
        dsNhanVien.push_back(nv);
    }
    f.close();
}

void xuat_1_nhan_vien(NhanVien nv){
    cout << left << setw(11) << nv.ma << setw(26) << nv.hoTen << setw(12) << nv.soNgayCong << setw(16) 
    << nv.luongCB << setw(16) << nv.tongLuong << endl;
}

void xuat_ds_nhan_vien(){
    printHeader();
    for (int i = 0; i < dsNhanVien.size(); i++)
        xuat_1_nhan_vien(dsNhanVien[i]);
}

// 4. Tim nhan vien theo ma
void tim_nhan_vien_theo_ma(){
    string ma;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> ma;
    for (int i = 0; i < dsNhanVien.size(); i++){
        if (dsNhanVien[i].ma == ma){
            printHeader();
            xuat_1_nhan_vien(dsNhanVien[i]);
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma " << ma << endl;
}

// 5. Sap xep danh sach theo tong luong
void hoan_vi(NhanVien &a, NhanVien &b){
    NhanVien temp = a;
    a = b;
    b = temp;
}

void sap_xep_ds_theo_tong_luong(){
    for (int i = 0; i < dsNhanVien.size() - 1; i++){
        for (int j = i + 1; j < dsNhanVien.size(); j++){
            if (dsNhanVien[i].tongLuong < dsNhanVien[j].tongLuong){
                hoan_vi(dsNhanVien[i], dsNhanVien[j]);
            }
        }
    }
    ghi_ds_ra_file("DSNV_SX.txt");
    cout << "Da sap xep va ghi ra file DSNV_SX.txt" << endl;
}

// 6. Tim nhan vien theo ten
int blank_end(string s){
    for (int i = s.length() - 1; i >= 0; i--)
        if (s[i] == ' ') return i;
    return -1;
}

void tim_nhan_vien_theo_ten(){
    string ten;
    cout << "Nhap ten nhan vien can tim: ";
    cin.ignore();
    getline(cin, ten);
    xu_Ly_Ten(ten);
    for (int i = 0; i < dsNhanVien.size(); i++){
        int index = blank_end(dsNhanVien[i].hoTen);
        string tenNhanVien = dsNhanVien[i].hoTen.substr(index + 1);
        if (tenNhanVien == ten){
            printHeader();
            xuat_1_nhan_vien(dsNhanVien[i]);
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ten " << ten << endl;
}

// 7. Xoa nhan vien theo ma
void xoa_nhan_vien_theo_ma(){
    string ma;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> ma;
    for (int i = 0; i < dsNhanVien.size(); i++){
        if (dsNhanVien[i].ma == ma){
            dsNhanVien.erase(dsNhanVien.begin() + i);
            ghi_ds_ra_file("DSNV_XOA.txt");
            cout << "Da xoa nhan vien co ma " << ma << " va da ghi lai vao file DSNV_XOA.txt" << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma " << ma << endl;
}

// 8. Them nhan vien
void them_nhan_vien_theo_ma(){
    NhanVien nv;
    nhap_1_nhan_vien(nv);
    dsNhanVien.push_back(nv);
    ghi_ds_ra_file("DSNV_THEM.txt");
}

int main(){
    int chon;
    string tenFile = "DSNV.txt";
    do {
        cout << "=====================    MENU    =====================" << endl;
        cout << "1. Nhap danh sach nhan vien\n";
        cout << "2. Ghi danh sach ra file\n";
        cout << "3. Doc danh sach tu file va in ra man hinh\n";
        cout << "4. Tim nhan vien theo ma\n";
        cout << "5. Sap xep danh sach theo tong luong va ghi ra file\n";
        cout << "6. Tim nhan vien theo ten\n";
        cout << "7. Xoa nhan vien theo ma\n";
        cout << "8. Them nhan vien\n";
        cout << "0. Thoat\n";
        do{
            cout << "------------------------------------------------------\n";
            cout << "Chon chuc nang: ";
            cin >> chon;
            if(chon < 0 || chon > 8)
                cout << "Nhap sai, moi nhap lai: ";
        } while (chon < 0 || chon > 8);
        print();
        switch(chon){
            case 1:
                nhap_ds_nhan_vien();
                break;
            case 2:
                ghi_ds_ra_file(tenFile);
                break;
            case 3:
                doc_ds_tu_file(tenFile);
                xuat_ds_nhan_vien();
                break;
            case 4:
                tim_nhan_vien_theo_ma();
                break;
            case 5:
                sap_xep_ds_theo_tong_luong();
                break;
            case 6:
                tim_nhan_vien_theo_ten();
                break;
            case 7:
                xoa_nhan_vien_theo_ma();
                break;
            case 8:
                them_nhan_vien_theo_ma();
                break;
        }
    } while (chon != 0);
    return 0;
}