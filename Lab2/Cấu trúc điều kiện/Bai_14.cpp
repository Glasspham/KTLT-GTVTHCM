#include<iostream>
using namespace std;
int main(){
    int maso;
    cout << "Nhap vao ma so cua nhan vien (1-4): ";
    cin >> maso;
    int luong = 0;
    a:
        switch (maso){
        case 1:
            double luongQuanLy;
            cout << "Nhap vao luong quan ly: ";
            cin >> luongQuanLy;
            luong = luongQuanLy;
            break;
        case 2:
            double luongCoBan, gioLamViec;
            cout << "Nhap vao luong nhan vien: ";
            cin >> luongCoBan;
            cout << "Nhap vao so gio lam viec: ";
            cin >> gioLamViec;
            if(gioLamViec <= 40)
                luong = luongCoBan * gioLamViec;
            else
                luong = 40 * luongCoBan + (gioLamViec - 40) * luongCoBan * 1.5;
            break;
        case 3:
            double doanhSo;
            cout << "Nhap vao doanh so ban duoc: ";
            cin >> doanhSo;
            luong = 500000 + doanhSo * 0.07;
            break;
        case 4:
            int soLuong;
            double giaSanPham;
            cout << "Nhap vao so luong san pham da lam duoc: ";
            cin >> soLuong;
            cout << "Nhap vao gia tien cua mot san pham do: ";
            cin >> giaSanPham;
            luong = soLuong * giaSanPham;
            break;
        default:
            cout << "Nhap sai ma so!\nMoi lam lai!";
            cout << "\nNhap vao ma so cua nhan vien (1-4): ";
            cin >> maso;
            goto a;
        }
        cout << "Luong cua nhan vien trong tuan la: " << luong << " dong." << endl;
        return 0;
}
