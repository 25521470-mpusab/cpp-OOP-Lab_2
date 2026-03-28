#ifndef NGAYTHANGNAM_H
#define NGAYTHANGNAM_H

class NgayThangNam {
private:
   int iNgay, iThang, iNam;

   public:
   bool KiemTraNgayHopLe(); //là 1 ngày có thật: true, không phải: false
   void Nhap();
   void Xuat();

   void XuatNgayThangNamTiepTheo();
};

#endif