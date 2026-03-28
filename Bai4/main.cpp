#include <iostream>
#include "GioPhutGiay.h"
using namespace std;

int main() {
    GioPhutGiay t;

    cout << "Nhap thoi gian:\n";
    t.Nhap();

    cout << "\nThoi gian hiện tại: ";
    t.Xuat();

    t.TinhCongThemMotGiay();

    cout << "\nThoi gian sau khi cong 1 giay: ";
    t.Xuat();

    return 0;
}