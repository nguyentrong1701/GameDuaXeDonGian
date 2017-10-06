#pragma once
#include "Xe.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "NguoiChoi.h"


class TroChoi
{
private:
	char duongDua[24][24];
	NguoiChoi nguoiChoi;
	NguoiChoi danhSach[10];
	Xe xeNguoiChoi;
	int xTien;
	int yTien;
	void MoveCursorToRoot();
	void MoveCursor(int, int);
public:
	TroChoi();
	~TroChoi();
	void ThietLapDuongDua();
	void XuatDuongDua();
	void NhapNguoiChoi();
	int XungDot(Xe);
	void XuLySauDungDo();
	void LayDanhSach(char*);
	void GhiDanhSach(char*);
	void ThayTheNguoiChoi();
	void XuatBangThongTin();
	template<class T>
	void Xuat(int, char*, T);
	void TaoTien();
	bool KiemTraAnTien();
	void XuLy();
	void CanhGiua(int, char*);
	void XuatSauTroChoi();
	void ChoiTroChoi();	
};

