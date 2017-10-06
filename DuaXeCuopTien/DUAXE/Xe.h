#pragma once
#include <iostream>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include "Diem.h"

using namespace std;

class Xe
{
private:
	char banhXe;
	char thanXeTrai;
	char thanXePhai;
	char tamXe;
	char xe[3][3];
	Diem tam;
	void MoveCursor(int, int);
public:
	Xe();
	Xe(char, char, char, char, Diem);
	~Xe();
	void ThietLapXe();
	void XuatXe();
	void NhapXe();
	void DichTrai();
	void DichPhai();
	void DichLen();
	void DichXuong();
	void XoaXe();
	int LayXTam();
	int LayYTam();
	void GanTam(int, int);
};

