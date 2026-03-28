#include <iostream>
#include "SoPhuc.h"
using namespace std;

int main() {
     SoPhuc a, b;

    cout << "Nhap so phuc A:\n";
    a.Nhap();

    cout << "Nhap so phuc B:\n";
    b.Nhap();

    cout << "\nSo phuc A: ";
    a.Xuat();

    cout << "\nSo phuc B: ";
    b.Xuat();

// Tính toán
    SoPhuc tong = a.TinhTong(b);
    SoPhuc hieu = a.TinhHieu(b);
    SoPhuc tich = a.TinhTich(b);
    SoPhuc thuong = a.TinhThuong(b);

    cout << "\n\nTong: ";
    tong.Xuat();

    cout << "\nHieu: ";
    hieu.Xuat();

    cout << "\nTich: ";
    tich.Xuat();

    cout << "\nThuong: ";
    thuong.Xuat();

    return 0;
}