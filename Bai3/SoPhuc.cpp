#include "SoPhuc.h"
#include <string>
#include <cmath>
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

/* Đầu vào là 1 số phức nhập vào, 
đầu ra là 1 số phức thiếu điều kiện */
void SoPhuc::Nhap (){
    string input;

    // Nhập phần thực a
    while (true) {
        cout << "Nhap phan thuc a: ";
        cin >> input; 

        if (laSoNguyen(input)) {
            iThuc = stoi(input); // chuyển chuỗi thành số nguyên
            break; 
        } else {
            cout << "Loi! Khong duoc nhap chu hay ky hieu.\n";
        }
    }

    // Nhập phần ảo b
    while (true) {
        cout << "Nhap phan ao b: ";
        cin >> input;

        if (laSoNguyen(input)) {
            iAo = stoi(input); // chuyển chuỗi thành số nguyên
            break;
        } else {
            cout << "Loi! Khong duoc nhap chu hay ky hieu.\n";
        }
    }
}

/* Đầu vào là 1 số phức nhập vào đủ điều kiện, 
đầu ra là xuất số phức đó dưới dạng a + bi */
void SoPhuc::Xuat() {
    // 1. Trường hợp: a = 0, b = 0
    if (iThuc == 0 && iAo == 0) {
        cout << 0;
        return;
    }

    // 2. In phần thực a nếu nó khác 0
    if (iThuc != 0) {
        cout << iThuc;
    }

    // 3. In phần ảo b nếu nó khác 0
    if (iAo != 0) {
        // Chỉnh dấu nối giữa a và b
        if (iAo > 0) {
            // Chỉ in dấu " + " nếu có phần thực đứng trước
            if (iThuc != 0) cout << " + ";
        } else {
            // Nếu có phần thực thì in " - ", nếu không có thì chỉ in "-" 
            if (iThuc != 0) cout << " - ";
            else cout << "-";
        }

        // Lấy giá trị tuyệt đối để in con số
        int tuyetDoiAo = abs(iAo);
        
        // Chỉ in con số nếu nó khác 1, nếu là 1 hoặc -1 thì bỏ hoặc giữ lại dấu
        if (tuyetDoiAo != 1) {
            cout << tuyetDoiAo;
        }
        cout << "i";
    }
}

/* Đầu vào là 2 số phức nhập vào đủ điều kiện, 
đầu ra là số phức tổng của số phức nhập vào */
SoPhuc SoPhuc::TinhTong (SoPhuc a){
    SoPhuc kq;
    kq.iThuc = iThuc + a.iThuc;
    kq.iAo = iAo + a.iAo;
    return kq;
}

/* Đầu vào là 2 số phức nhập vào đủ điều kiện, 
đầu ra là số phức hiệu của 2 số phức nhập vào */
SoPhuc SoPhuc::TinhHieu (SoPhuc a){
    SoPhuc kq;
    kq.iThuc = iThuc - a.iThuc;
    kq.iAo = iAo - a.iAo;
    return kq;
}

/* Đầu vào là 2 số phức nhập vào đủ điều kiện,
đầu ra là số phức tích của 2 số phức nhập vào */
SoPhuc SoPhuc::TinhTich (SoPhuc a){
    SoPhuc kq;
    kq.iThuc = iThuc * a.iThuc - iAo * a.iAo;
    kq.iAo = iThuc * a.iAo + iAo * a.iThuc;
    return kq;
}

/* Đầu vào là 2 số phức nhập vào đủ điều kiện,
đầu ra là số phức thương của 2 số phức nhập vào */
SoPhuc SoPhuc::TinhThuong (SoPhuc a){
    SoPhuc kq;
    int mau = a.iThuc * a.iThuc + a.iAo * a.iAo;

    if (mau == 0) {
        cout << "Loi: Khong the chia cho 0!";
        kq.iThuc = 0; kq.iAo = 0;
        return kq;
    }

    kq.iThuc = (iThuc * a.iThuc + iAo * a.iAo) / mau;
    kq.iAo = (iAo * a.iThuc - iThuc * a.iAo) / mau;

    return kq;

}