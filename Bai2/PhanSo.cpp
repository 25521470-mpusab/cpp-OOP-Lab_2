#include "PhanSo.h"
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

// hàm kiểm tra chuỗi có phải số nguyên không
/* Đầu vào là Một chuỗi ký tự (string s),
đầu ra là return về
        + true: Nếu chuỗi chỉ chứa các chữ số (có thể có dấu trừ '-' ở đầu).
        + false: Nếu chuỗi rỗng hoặc chứa chữ cái, ký hiệu đặc biệt. */
bool laSoNguyen(string s) {
    if (s.empty()) return false;
    int i = 0;
    if (s[0] == '-') {
        if (s.length() == 1) return false; 
        i = 1;
    }
    for (; i < (int)s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') return false;
    }
    return true;
}

/* Đầu vào là 1 phân số nhập vào, 
đầu ra là phân số nhập vào thiếu điều kiện */
void PhanSo::Nhap() {
    string s;

    // Nhập tử 
    while (true) {
        cout << "Nhap tu so: ";
        cin >> s;

        if (laSoNguyen(s)) {
            iTu = stoi(s); //chuyển chuỗi thành số nguyên
            break;
        } else {
            cout << "Loi! Khong duoc nhap chu hoac ky hieu.\n";
        }
    }

    // Nhập mẫu
    while (true) {
        cout << "Nhap mau so (khac 0): ";
        cin >> s;

        if (!laSoNguyen(s)) {
            cout << "Loi! Khong duoc nhap chu hoac ky hieu.\n";
        }
        else {
            iMau = stoi(s); //chuyển chuỗi thành số nguyên

            if (iMau == 0) {
                cout << "Mau so phai khac 0!\n";
            } else {
                break;
            }
        }
    }
}

/* Đầu vào là 1 phân số đủ điều kiện, đã rút gọn, đã tính toán
đầu ra là phân số dưới dạng a/b */    
void PhanSo::Xuat(){
    if (iTu == 0) {
        cout << 0;
    } else if (iMau == 1) {
        cout << iTu;
    } else {
        cout << iTu << "/" << iMau;
    }
}

// Hàm tìm UCLN 
/* Đầu vào là 2 số nguyên a và b,
đầu ra là UCLN của a và b */
int UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);

    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

/* Đầu vào là 1 phân số đủ điều kiện, 
đầu ra là phân số nhập vào đã rút gọn
Hướng giải thuật: Quy đồng 2 phân số */    
void PhanSo::RutGon(){
int ucln = UCLN(abs(iTu), abs(iMau));

    iTu /= ucln;
    iMau /= ucln;

// đưa dấu lên tử
    if (iMau < 0) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

/* Đầu vào là 2 phân số nhập vào đủ điều kiện, đã rút gọn, 
đầu ra là phân số tổng của 2 phân số nhập vào */    
PhanSo PhanSo::TinhTong(PhanSo a){
    PhanSo kq;

    kq.iTu = iTu * a.iMau + a.iTu * iMau;
    kq.iMau = iMau * a.iMau;

    kq.RutGon();
    return kq;
}

/* Đầu vào là 2 phân số nhập vào đủ điều kiện, đã rút gọn, 
đầu ra là phân số hiệu của 2 phân số nhập vào */    
PhanSo PhanSo::TinhHieu(PhanSo a){
    PhanSo kq;

    kq.iTu = iTu * a.iMau - a.iTu * iMau;
    kq.iMau = iMau * a.iMau;

    kq.RutGon();
    return kq;
}

/* Đầu vào là 2 phân số nhập vào đủ điều kiện, đã rút gọn, 
đầu ra là phân số tích của 2 phân số nhập vào */    
PhanSo PhanSo::TinhTich(PhanSo a){
    PhanSo kq;

    kq.iTu = iTu * a.iTu;
    kq.iMau = iMau * a.iMau;

    kq.RutGon();
    return kq;
}

/* Đầu vào là 2 phân số nhập vào đủ điều kiện, đã rút gọn, 
đầu ra là phân số thương của 2 phân số nhập vào  */    
PhanSo PhanSo::TinhThuong(PhanSo a){
    PhanSo kq;

    if (a.iTu == 0) {
        cout << "Loi: Khong the chia cho phan so bang 0!\n";
        kq.iTu = 0; kq.iMau = 1; 
        return kq;
    }

    kq.iTu = iTu * a.iMau;
    kq.iMau = iMau * a.iTu;

    kq.RutGon();
    return kq;
}

 /* Đầu vào là 2 phân số nhập vào đủ điều kiện, đã rút gọn, 
đầu ra là nhập vào lớn hơn 
Hướng giải thuật: trả về 1 nếu >; -1 nếu <; 0 nếu = */   
int PhanSo::SoSanh(PhanSo a){
    int trai = iTu * a.iMau;
    int phai = a.iTu * iMau;

    if (trai > phai) return 1;
    if (trai < phai) return -1;
    return 0;
}