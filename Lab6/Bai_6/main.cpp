#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;

struct sv{
	string ten;
	string ngay_sinh;
	string gioi_tinh;
	float diem_cac_mon;

};

vector<sv> ds_sv;

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

void xu_Ly_NgaySinh(string &s){
	if(s[0] <= '9' && s[0] >= '0' && s[1] == '/')
		s = "0" + s;
	if(s[3] <= '9' && s[3] >= '0' && s[4] == '/')
		s = s.substr(0, 3) + "0" + s.substr(3, s.length() - 3);
}

sv Nhap1SV(sv a){
	cin.ignore();
	cout << "Nhap ho va ten: ";
	getline(cin, a.ten);
	xu_Ly_Ten(a.ten);
	cout << "Nhap ngay sinh(1/1/2000): ";
	cin >> a.ngay_sinh;
	xu_Ly_NgaySinh(a.ngay_sinh);
	cout << "Nhap gioi tinh: ";
	cin >> a.gioi_tinh;
	cout << "Nhap diem cac mon: ";
	cin >> a.diem_cac_mon;
	return a;
}

void NhapDS(){
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for(int i = 0; i < n; i++){
		sv a;
		cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
		ds_sv.push_back(Nhap1SV(a));
	}
}

void ghiSinhVien(fstream &file){
    file.open("QLSV.txt", ios::out | ios::trunc);
    if (file.is_open()){ 
        for(int i = 0; i < ds_sv.size(); i++)
            file << ds_sv[i].ten << "," << ds_sv[i].ngay_sinh << "," << ds_sv[i].gioi_tinh << "," << fixed << setprecision(1) << ds_sv[i].diem_cac_mon << endl;
        cout << "Thong tin sinh vien da duoc ghi vao File !" << endl;
        file.close();
    } else 
        cout << "Khong the mo file de ghi." << endl;
}

void docDS(fstream &file){
	ds_sv.clear();
	file.open("QLSV.txt", ios::in);
	string line;
	while(getline(file, line)){
		sv a;
		int pos = line.find(",");
		a.ten = line.substr(0, pos);
		line.erase(0, pos + 1);
		pos = line.find(",");
		a.ngay_sinh = line.substr(0, pos);
		line.erase(0, pos + 1);
		pos = line.find(",");
		a.gioi_tinh = line.substr(0, pos);
		line.erase(0, pos + 1);
		a.diem_cac_mon = stof(line);
		ds_sv.push_back(a);
	}
	file.close();
	cout << "Da doc thong tin sinh vien tu File !" << endl;
}

void xuatDS(){
	cout << "Danh sach sinh vien: " << endl;
	cout << left << setw(25) << "Ho va ten" << setw(15) << "Ngay sinh" << setw(10) << "Gioi tinh" << setw(10) << "Diem cac mon" << endl;
	for(int i = 0; i < ds_sv.size(); i++)
		cout << left << setw(25) << ds_sv[i].ten << setw(15) << ds_sv[i].ngay_sinh << setw(10) << ds_sv[i].gioi_tinh << fixed << setprecision(2) << setw(10) << ds_sv[i].diem_cac_mon << endl;
}

int blank_end(string fullname){
	int l = fullname.length();
	for (int i = l - 1; i >= 0; i--)
	if (fullname[i] == ' ')
		return i;
	return -1;
}

void xoaSinhVien(){
	string ten;
	cout << "Nhap ten sinh vien can xoa: ";
	cin.ignore();
	getline(cin, ten);
	xu_Ly_Ten(ten);
	bool found = false;
	for(int i = 0; i < ds_sv.size(); i++){
		int pos = blank_end(ds_sv[i].ten);
		string temp = ds_sv[i].ten.substr(pos + 1, ds_sv[i].ten.length() - pos - 1);
		if(temp == ten){
			ds_sv.erase(ds_sv.begin() + i);
			cout << "Da xoa sinh vien co ten " << ten << " khoi danh sach." << endl;
			found = true;
			break;
		}
	}
	if(!found)
		cout << "Khong tim thay sinh vien co ten " << ten << " trong danh sach." << endl;

}

void suaSinhVien(){
	string ten;
	cout << "Nhap ten sinh vien can sua: ";
	cin >> ten;
	xu_Ly_Ten(ten);
	bool found = false;
	for(int i = 0; i < ds_sv.size(); i++){
		int pos = blank_end(ds_sv[i].ten);
		string temp = ds_sv[i].ten.substr(pos + 1, ds_sv[i].ten.length() - pos - 1);
		if(temp == ten){
			cout << "Nhap thong tin moi cho sinh vien!" << endl;
			sv a;
			ds_sv[i] = Nhap1SV(a);
			found = true;
			break;
		}
	}
	if(!found)
		cout << "Khong tim thay sinh vien co ten " << ten << " trong danh sach." << endl;
	
}

int main(){
	fstream file;
	int choice;
	do{
		cout << "1. Nhap danh sach sinh vien." << endl;
		cout << "2. Ghi danh sach sinh vien vao file." << endl;
		cout << "3. Doc danh sach sinh vien tu file." << endl;
		cout << "4. Xuat danh sach sinh vien." << endl;
		cout << "5. Xoa sinh vien." << endl;
		cout << "6. Sua sinh vien." << endl;
		cout << "7. Thoat." << endl;
		cout << "Lua chon cua ban: ";
		cin >> choice;
		switch(choice){
			case 1:
				NhapDS();
				break;
			case 2:
				ghiSinhVien(file);
				break;
			case 3:
				docDS(file);
				break;
			case 4:
				xuatDS();
				break;
			case 5:
				xoaSinhVien();
				ghiSinhVien(file);
				break;
			case 6:
				suaSinhVien();
				ghiSinhVien(file);
				break;
			case 7:
				break;
			default:
				cout << "Lua chon khong hop le. Vui long chon lai." << endl;
		}
	}while(choice != 7);
	return 0;
}