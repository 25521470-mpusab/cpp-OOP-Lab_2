#include "GioPhutGiay.h"
#include <string>
#include <iostream>
using namespace std;

// hàm kiểm tra chuỗi có phải số nguyên dương không
/* Đầu vào là Một chuỗi ký tự (string s),
đầu ra là return về
        + true: Nếu chuỗi chỉ chứa các chữ số nguyên dương.
        + false: Nếu chuỗi rỗng hoặc chứa chữ cái, ký hiệu đặc biệt. */
bool laSoNguyenDuong(string s) {
    if (s.length() == 0) return false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return false;
        }
    }
    return true;
}

/* Đầu vào là 3 số nguyên nhập vào, 
đầu ra là lưu 3 giá trị vào giờ phút giây thiếu điều kiện */
void GioPhutGiay::Nhap() {
    string input;

    // Nhập giờ
    while (true) {
        cout << "Nhap gio: ";
        cin >> input;

        if (!laSoNguyenDuong(input)) {
            cout << "Loi! Khong duoc nhap chu, ky hieu.\n";
        }
        else {
            iGio = stoi(input); //chuyển chuỗi thành số nguyên dương

            if (iGio < 0 || iGio > 23) {
                cout << "Gio phai tu 0 den 23.\n";
            } else break;
        }
    }

    // Nhập phút
    while (true) {
        cout << "Nhap phut: ";
        cin >> input;

        if (!laSoNguyenDuong(input)) {
            cout << "Loi! Khong duoc nhap chu, ky hieu.\n";
        }
        else {
            iPhut = stoi(input); //chuyển chuỗi thành số nguyên dương

            if (iPhut < 0 || iPhut > 59) {
                cout << "Phut phai tu 0 den 59.\n";
            } else break;
        }
    }

    // Nhập giây
    while (true) {
        cout << "Nhap giay: ";
        cin >> input;

        if (!laSoNguyenDuong(input)) {
            cout << "Loi! Khong duoc nhap chu, ky hieu.\n";
        }
        else {
            iGiay = stoi(input); //chuyển chuỗi thành số nguyên dương

            if (iGiay < 0 || iGiay > 59) {
                cout << "Giay phai tu 0 den 59.\n";
            } else break;
        }
    }
}

/* Đầu vào là 3 giá trị chỉ giờ, phút, giây đủ điều kiện, 
đầu ra là xuất 3 giá trị giờ, phút, giây đó dưới dạng giờ:phút:giây */
void GioPhutGiay::Xuat(){
    if (iGio < 10) cout << "0";
    cout << iGio << ":";
    if (iPhut < 10) cout << "0";
    cout << iPhut << ":";
    if (iGiay < 10) cout << "0";
    cout << iGiay;
}

/* Đầu vào là 3 giá trị chỉ giờ, phút, giây hiện tại đủ điều kiện, 
đầu ra là 3 giá trị chỉ giờ, phút, giây tiếp theo đủ điều kiện, 
Hướng giải thuật:
- Tăng 1 giây
- Nếu giây = 60 → reset, tăng phút
- Nếu phút = 60 → reset, tăng giờ
- Nếu giờ = 24 → reset về 0*/
void GioPhutGiay::TinhCongThemMotGiay(){
    iGiay++;

    if (iGiay == 60) {
        iGiay = 0;
        iPhut++;

        if (iPhut == 60) {
            iPhut = 0;
            iGio++;

            if (iGio == 24) {
                iGio = 0;
            }
        }
    }
}
