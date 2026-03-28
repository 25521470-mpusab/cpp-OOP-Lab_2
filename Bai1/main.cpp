#include <iostream>
#include "NgayThangNam.h"
using namespace std;

int main() {
    NgayThangNam a;

    cout << "Nhap ngay thang nam: \n";
    a.Nhap();

    cout << "\nNgay hien tai: ";
    a.Xuat();

    a.XuatNgayThangNamTiepTheo();

    cout << "\nNgay tiep theo: ";
    a.Xuat();

    return 0;
}