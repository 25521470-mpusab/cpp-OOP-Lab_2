#include "NgayThangNam.h"
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

// Hàm kiểm tra năm nhuận
/* Đầu vào là 1 số nguyên nhập vào, 
đầu ra là trả về kết quả true nếu là năm nhuận hoặc false nếu không là năm nhuận */
bool laNamNhuan(int nam) {
    if (nam % 400 == 0) return true;
    if (nam % 4 == 0 && nam % 100 != 0) return true;
    return false;
}

// Hàm xác định Số ngày trong tháng và kiểm tra ngày có hợp lệ không
/* Đầu vào là 2 số nguyên chỉ tháng và năm, 
đầu ra là 1 số nguyên chỉ số ngày của tháng đó trong năm */
int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;

        case 4: case 6: case 9: case 11:
            return 30;

        case 2:
            if (laNamNhuan(nam)) return 29;
            return 28;
    }
    return 0;
}

// Hàm kiểm tra ngày tháng năm có hợp lệ không
/* Đầu vào là 3 số nguyên nhập vào biến iNgay,
đầu ra là kiểm tra số nguyên đó có phải là 1 ngày trong thực tế không,
đúng thì chạy tiếp, sai trả về false */
bool NgayThangNam::KiemTraNgayHopLe() {
    // kiểm tra tháng
    if (iThang < 1 || iThang > 12) {
        return false;
    }

    // kiểm tra số ngày trong tháng 
    int soNgay = soNgayTrongThang(iThang, iNam);

    // kiểm tra ngày có hợp lệ không
    if (iNgay < 1 || iNgay > soNgay) {
        return false;
    }

    return true;
}

/* Đầu vào là 3 số nguyên nhập vào, 
đầu ra là lưu 3 giá trị vào ngày tháng năm hiện tại thiếu điều kiện */
void NgayThangNam::Nhap(){
   string input;

    do {
        // Nhập ngày 
        while (true) {
            cout << "Nhap ngay: ";
            cin >> input;
            
            if (laSoNguyenDuong(input)) {
                iNgay = stoi(input); // chuyển chuỗi thành số nguyên dương
                
                if (iNgay < 1 || iNgay > 31) {
                    cout << "Ngay phai tu 1 den 31.\n";
                } else break;
            
            } else {
                cout << "Loi! Khong duoc nhap chu, ky hieu, so am.\n";
            }
        }
    
        // Nhập tháng
        while (true) {
            cout << "Nhap thang: ";
            cin >> input;

            if (laSoNguyenDuong(input)) {
                iThang = stoi(input); //chuyển chuỗi thành số nguyên dương

                if (iThang < 1 || iThang > 12) {
                    cout << "Thang phai tu 1 den 12.\n";
                } else break;

            } else {
                cout << "Loi! Khong duoc nhap chu, ky hieu, so am.\n";
            }
        }

        // Nhập năm
        while (true) {
            cout << "Nhap nam: ";
            cin >> input;

            if (laSoNguyenDuong(input)) {
                iNam = stoi(input); //chuyển chuỗi thành số nguyên dương
                break;
            } else {
                cout << "Loi! Khong duoc nhap chu, ky hieu, so am.\n";
            }
        }

         if (!KiemTraNgayHopLe()) {
            cout << "Ngay khong hop le! Nhap lai.\n";
        }

    } while (!KiemTraNgayHopLe());
}

/* Đầu vào là 3 giá trị chỉ ngày, tháng, năm đủ điều kiện, 
đầu ra là xuất 3 giá trị ngày, tháng, năm đó dưới dạng ngay/thang/nam */
void NgayThangNam::Xuat(){
cout << iNgay << "/" << iThang << "/" << iNam;
}

/* Đầu vào là 3 giá trị chỉ ngày, tháng, năm hiện tại đủ điều kiện, 
đầu ra là 3 giá trị chỉ ngày, tháng, năm tiếp theo đủ điều kiện, 
Hướng giải thuật:
- Tăng ngày lên 1 (nếu là ngày hợp lệ, bình thường)
- Nếu vượt số ngày trong tháng:
    → đặt ngày = 1, tăng tháng
- Nếu tháng > 12:
    → đặt tháng = 1, tăng năm */
void NgayThangNam::XuatNgayThangNamTiepTheo(){
    iNgay++;  

    if (iNgay > soNgayTrongThang(iThang, iNam)) {
        iNgay = 1;
        iThang++;

        if (iThang > 12) {
            iThang = 1;
            iNam++;
        }
    }
}