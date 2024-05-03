#ifdef _MSC_VER
#pragma warning (disable: 4996) 
#endif
//#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<fstream>
#include<cstring>
#define MAX 100
using namespace std;

struct NHANVIEN{
	char ma[10];
	char hoten[50];
	int songaycong;
	float luongcb;
	float tongluong;
};

void nhap_1_nhan_vien(NHANVIEN &nv){
	cin.ignore();
	cout << "Nhap ma:";
	cin.getline(nv.ma, 10);
	cout << "Nhap ho ten:";
	cin.getline(nv.hoten, 50);
	cout << "Nhap so ngay cong: ";
	cin >> nv.songaycong;
	cout << "Nhap luong co ban: ";
	cin >> nv.luongcb;
	nv.tongluong = nv.songaycong*nv.luongcb;
}

void ghi_DS_ra_file(fstream &f, int n){
	NHANVIEN nv;
	f.open("DSNV07.txt", ios::app | ios::binary);
	for (int i = 1; i <= n; i++){
		nhap_1_nhan_vien(nv);
		// reinterpret_cast<char*>(&nv): Ép kiểu con trỏ của biến nv sang kiểu char*, 
		// vì phương thức write yêu cầu một con trỏ kiểu char*.
		f.write(reinterpret_cast<char*>(&nv), sizeof(nv));
	}
	f.close();
}

void doc_ds_nhan_vien_tu_file(fstream &f, NHANVIEN a[], int &n){
	n = 0;
	f.open("DSNV07.txt", ios::in | ios::binary);
	// reinterpret_cast<char*>(&a[n]): Ép kiểu con trỏ của phần tử thứ n của mảng a[] sang kiểu char*, 
	// vì phương thức read yêu cầu một con trỏ kiểu char*.
	while (f.read(reinterpret_cast<char*>(&a[n]), sizeof(a[n])))
		n++;
	f.close();
}

void xuat_1_nhan_vien(NHANVIEN nv){
	cout << nv.ma << " " << nv.hoten << " " << nv.songaycong << " "
		<< nv.luongcb << " " << nv.tongluong << endl;
}

void xuat_danh_sach(NHANVIEN a[], int n){
	for (int i = 0; i < n; i++)
		xuat_1_nhan_vien(a[i]);
}

int tim_nhan_vien_theo_ma(NHANVIEN a[], int n, char mat[]){
	for (int i = 0; i < n; i++)
		if (strcmp(a[i].ma, mat) == 0)
			return i;
	return -1;
}

void xuat_thong_tin_nhan_vien_can_tim(NHANVIEN a[], int n){
	cin.ignore();
	char mat[10];
	cout << "Moi nhap ma nhan vien can tim: ";
	cin.getline(mat, 10);
	int vitri = tim_nhan_vien_theo_ma(a, n, mat);
	if (vitri == -1)
		cout << "Khong co nhan vien can tim" << endl;
	else
		xuat_1_nhan_vien(a[vitri]);
}

void hoanvi(NHANVIEN &x, NHANVIEN &y){
	NHANVIEN t;
	t = x; x = y; y = t;
}

void sap_xep_nhan_vien_theo_tong_luong(NHANVIEN a[], int n){
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].tongluong > a[j].tongluong)
				hoanvi(a[i], a[j]);
}

void ghi_DS_tong_luong_tang_dan_ra_file(fstream &f, NHANVIEN a[], int n){
	f.open("DSNV_tongluong_tang07.txt", ios::app | ios::binary);
	for (int i = 0; i < n; i++)
		f.write(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
	f.close();
}

int blank_end(char *fullname){
	int l = strlen(fullname);
	for (int i = l - 1; i >= 0; i--)
	if (fullname[i] == ' ')
		return i;
	return -1;
}

char* get_name(char *fullname){
	char* temp;
	temp = new char[20];
	int i = blank_end(fullname);
	if (i != -1)
		strcpy(temp, fullname + i + 1);
	return temp;
}

void tim_ten(NHANVIEN a[], int n){
	cin.ignore();
	char name[20];
	cout << "Nhap ten can tim: ";
	cin.getline(name, 20);
	bool flag = false;
	for (int i = 0; i < n; i++){
		char* temp_name = new char[20];
		strcpy(temp_name, get_name(a[i].hoten));
		// stricmp: so sánh chuỗi không phân biệt hoa thường
		if (stricmp(temp_name, name) == 0){
			xuat_1_nhan_vien(a[i]);
			flag = true;
		}
	}
	if (flag == false)
		cout << "\nKhong co ten can tim";
}

void xoa_nhan_vien_theo_ma(fstream &f, NHANVIEN a[], int &n, char mat[]){
	int vitri = tim_nhan_vien_theo_ma(a, n, mat);
	if (vitri == -1) cout << "Khong co nhan vien can xoa" << endl;
	else{
		for (int i = vitri; i < n - 1; i++)
			a[i] = a[i + 1];
		n--;
		f.open("DSNV07.txt", ios::out | ios::binary);
		for (int i = 0; i < n; i++)
			f.write(reinterpret_cast<char*>(&a[i]), sizeof(a[i]));
		f.close();
	}
}

void them_nha_vien_theo_ma(fstream &f, NHANVIEN a[], int &n, NHANVIEN nv){
	a[n] = nv;
	n++;
	f.open("DSNV07.txt", ios::app | ios::binary);
	f.write(reinterpret_cast<char*>(&nv), sizeof(nv));
	f.close();
}

int main(){
	fstream f;
	int n;
	NHANVIEN a[MAX];
	cout << "Nhap so nhan vien: ";
	cin >> n;
	ghi_DS_ra_file(f, n);
	doc_ds_nhan_vien_tu_file(f, a, n);
	int chon;
	do{
		cout << "\n1. Xuat danh sach nhan vien";
		cout << "\n2. Xuat thong tin nhan vien can tim";
		cout << "\n3. Tim ten nhan vien";
		cout << "\n4. Sap xep nhan vien theo tong luong tang dan";
		cout << "\n5. Xoa nhan vien theo ma";
		cout << "\n6. Them nhan vien theo ma";
		cout << "\n0. Thoat";
		cout << "\nMoi chon: ";
		cin >> chon;
		if(chon == 0) break;
		if(chon < 0 || chon > 6) cout << "Nhap sai, moi nhap lai: ";
		switch (chon){
		case 1:
			xuat_danh_sach(a, n);
			break;
		case 2:
			xuat_thong_tin_nhan_vien_can_tim(a, n);
			break;
		case 3:
			tim_ten(a, n);
			break;
		case 4:
			sap_xep_nhan_vien_theo_tong_luong(a, n);
			ghi_DS_tong_luong_tang_dan_ra_file(f, a, n);
			break;
		case 5:
			char mat[10];
			cout << "Nhap ma nhan vien can xoa: ";
			cin.ignore();
			cin.getline(mat, 10);
			xoa_nhan_vien_theo_ma(f, a, n, mat);
			break;
		case 6:
			NHANVIEN nv;
			nhap_1_nhan_vien(nv);
			them_nha_vien_theo_ma(f, a, n, nv);
			break;
		}
	} while (chon != 0);
	return 0;
}