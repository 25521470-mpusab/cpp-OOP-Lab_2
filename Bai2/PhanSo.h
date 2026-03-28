#ifndef PHANSO_H
#define PHANSO_H

class PhanSo {
private:
    int iTu, iMau;

public:
    void Nhap();
    void Xuat();
    void RutGon();

    PhanSo TinhTong(PhanSo a);
    PhanSo TinhHieu(PhanSo a);
    PhanSo TinhTich(PhanSo a);
    PhanSo TinhThuong(PhanSo a);

    int SoSanh(PhanSo a); //  trả về 1 nếu >; -1 nếu <; 0 nếu =
};

#endif