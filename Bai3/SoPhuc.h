#ifndef SOPHUC_H
#define SOPHUC_H

class SoPhuc {
    private:
    int iThuc, iAo;

    public:
    void Nhap ();
    void Xuat ();

    SoPhuc TinhTong (SoPhuc a);
    SoPhuc TinhHieu (SoPhuc a);
    SoPhuc TinhTich (SoPhuc a);
    SoPhuc TinhThuong (SoPhuc a);
};

#endif