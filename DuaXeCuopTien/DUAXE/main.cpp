#include "TroChoi.h"

void main()
{
	TroChoi a;
	a.CanhGiua(0, "DO AN THUC HANH HUONG DOI TUONG");
	cout<<endl;
	a.CanhGiua(1, "NHOM 01");
	cout<<endl;
	a.CanhGiua(2, "_o0o_");
	cout<<endl;
	cout<<"Nhap thong tin de bat dau choi!"<<endl;
	a.NhapNguoiChoi();
	system("cls");
	a.ChoiTroChoi();
	system("cls");
	a.XuatSauTroChoi();
}