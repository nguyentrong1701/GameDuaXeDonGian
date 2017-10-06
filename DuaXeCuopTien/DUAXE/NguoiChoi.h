#pragma once
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class NguoiChoi
{
private:
	string ten;
	int capDo;
	int tien;
public:
	NguoiChoi();
	NguoiChoi(string, int, int);
	~NguoiChoi();
	void NhapTen();
	void Xuat();
	void TangCapDo();
	void TangTien();
	string LayTen();
	int LayCapDo();
	int LayTien();
	void GanTen(string);
	void GanCapDo(int);
	void GanTien(int);
	void LayTuFile(char*);
	void GhiVaoFile(char*);
};

