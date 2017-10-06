#include "TroChoi.h"


TroChoi::TroChoi()
{
	ThietLapDuongDua();
	xeNguoiChoi=Xe();
	TaoTien();
	LayDanhSach("File.txt");
}

TroChoi::~TroChoi()
{
}

void TroChoi::MoveCursorToRoot()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void TroChoi::ThietLapDuongDua()
{
	for(int i=0; i<24; i++)
	{
		for(int j=0; j<24; j++)
		{
			duongDua[i][j]=' ';
		}
		duongDua[i][0]=duongDua[i][23]='|';
	}
}

void TroChoi::XuatDuongDua()
{
	MoveCursorToRoot();
	for(int i=0; i<24; i++)
	{
		for(int j=0; j<24; j++)
		{
			cout<<duongDua[i][j];
		}
		cout<<endl;
	}
}

void TroChoi::NhapNguoiChoi()
{
	cout<<"Ten cua ban: ";
	nguoiChoi.NhapTen();
	cout<<"Thiet ke xe cua rieng ban!"<<endl;
	xeNguoiChoi.NhapXe();
	xeNguoiChoi.GanTam(12, 22);
}

void TroChoi::ChoiTroChoi()
{
	Xe xeMay1('"', '(', ')', '#', Diem(12, 0)), xeMay2(':', '(', ')', '@', Diem(7, 12));
	int k=20, l=10;
	int dem=0;
	while(1)
	{
		XuatBangThongTin();
		if(k==20)
		{
			srand(time(NULL)%10+time(NULL)%20);
			xeMay1.GanTam(rand()%20+2, 1);
			k=0;
		}
		else
		{
			k++;
		}
		if(l==20)
		{
			srand(time(NULL)%10+time(NULL)%20);
			xeMay2.GanTam(rand()%20+2, 1);
			l=0;
		}
		else
		{	
			l++;
		}

		this->XuatDuongDua();
		xeMay1.DichXuong();
		xeMay1.XuatXe();
		xeMay2.DichXuong();
		xeMay2.XuatXe();
		xeNguoiChoi.XuatXe();
		if(XungDot(xeMay1))
		{
			duongDua[xTien][yTien]=' ';
			XuLySauDungDo();
			break;
		}
		if(XungDot(xeMay2))
		{
			duongDua[xTien][yTien]=' ';
			XuLySauDungDo();
			break;
		}
		if(GetAsyncKeyState(VK_LEFT))
		{
			if(xeNguoiChoi.LayXTam()>2)
				xeNguoiChoi.DichTrai();
		}
		if(GetAsyncKeyState(VK_RIGHT))
		{
			if(xeNguoiChoi.LayXTam()<21)
				xeNguoiChoi.DichPhai();
		}
		if(GetAsyncKeyState(VK_UP))
		{
			if(xeNguoiChoi.LayYTam()>1)
				xeNguoiChoi.DichLen();
		}
		if(GetAsyncKeyState(VK_DOWN))
		{
			if(xeNguoiChoi.LayYTam()<22)
				xeNguoiChoi.DichXuong();
		}
		if(KiemTraAnTien()==true)
		{
			XuLy();
		}
		int capdo=nguoiChoi.LayCapDo();
		capdo==8?Sleep(10):Sleep(100-capdo*10);		//Dieu chinh toc do theo moi cap do
		dem++;
		switch(capdo)
		{
		case 1:
			if(dem==100)
			{
				nguoiChoi.TangCapDo();
				dem=0;
			}
			break;
		case 2:
			if(dem==150)
			{
				nguoiChoi.TangCapDo();
				dem=0;
			}
			break;
		case 3:
			if(dem==200)
			{
				nguoiChoi.TangCapDo();
				dem=0;
			}
			break;
		case 4:
			if(dem==300)
			{
				nguoiChoi.TangCapDo();
				dem=0;
			}
			break;
		case 5:
			if(dem==400)
			{
				nguoiChoi.TangCapDo();
				dem=0;
			}
			break;
		case 6:
			if(dem==600)
			{
				nguoiChoi.TangCapDo();
				dem=0;
			}
			break;
		case 7:
			if(dem==800)
			{
				nguoiChoi.TangCapDo();
				dem=0;
			}
			break;
		case 8:
			if(dem==1200)
			{
				nguoiChoi.TangCapDo();
				dem=0;
			}
			break;
		default:;
		}
		this->MoveCursorToRoot();
	}
}

int TroChoi::XungDot(Xe a)
{
	int x=xeNguoiChoi.LayXTam();
	int y=xeNguoiChoi.LayYTam();
	int xa=a.LayXTam();
	int ya=a.LayYTam();
	if(abs(y-ya)==1)
	{
		if(abs(x-xa)==1)
			return true;
	}
	else if(abs(x-xa)<3&&abs(y-ya)<3)
		return true;
	return false;
}

void TroChoi::XuLySauDungDo()
{
	this->MoveCursorToRoot();
	for(int j=0; j<24; j++)
	{
		for(int k=0; k<24; k++)
		{
			cout<<"$";
			Sleep(3);
		}
		cout<<endl;
	}
	this->XuatDuongDua();
	int k=1;
	do
	{
		this->MoveCursor(7, 12);
		if(k==1)
		{
			cout<<"GAME OVER!";
			this->MoveCursor(8, 13);
			cout<<"(Space!)";
			k=-k;
		}
		else
		{
			cout<<"          ";
			this->MoveCursor(8, 13);
			cout<<"        ";
			k=-k;
		}
		Sleep(200);
	} while(!GetAsyncKeyState(VK_SPACE));
	ThayTheNguoiChoi();
	GhiDanhSach("File.txt");
}

void TroChoi::MoveCursor(int x0, int y0)
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = x0;
	Position.Y = y0;
	SetConsoleCursorPosition(hOut, Position);
}

void TroChoi::LayDanhSach(char* filename)
{
	int i;
	string s;
	fstream f(filename,ios::in);
	for(int j=0; j<10; j++)
	{
		f>>s;
		danhSach[j].GanTen(s);
		f>>i;
		danhSach[j].GanCapDo(i);
		f>>i;
		danhSach[j].GanTien(i);
	}
	f.close();
}
void TroChoi::GhiDanhSach(char* filename)
{
	fstream f(filename, ios::out);
	f.close();
	for(int i=0; i<10; i++)
		danhSach[i].GhiVaoFile(filename);
}
void TroChoi::ThayTheNguoiChoi()
{
	if(nguoiChoi.LayTien()<=danhSach[9].LayTien())
		return;
	int i=0;
	while(nguoiChoi.LayTien()<danhSach[i].LayTien())
	{
		i++;
	}
	for(int j=9; j>i; j--)
		danhSach[j]=danhSach[j-1];
	danhSach[i]=nguoiChoi;
}
template<class T>
void TroChoi::Xuat(int y, char* s, T t)
{
	int x=24+(56-strlen(s))/2;
	this->MoveCursor(x, y);
	cout<<s<<t;
}
void TroChoi::XuatBangThongTin()
{
	Xuat(1, "DO AN THUC HANH HUONG DOI TUONG", "");
	Xuat(3, "NHOM 01", "");
	Xuat(5, "TRO CHOI DUA XE CUOP TIEN", "");
	Xuat(10, "Nguoi choi: ", nguoiChoi.LayTen());
	Xuat(15, "Cap do: ", nguoiChoi.LayCapDo());
	Xuat(20, "Tien cuop duoc: ",  nguoiChoi.LayTien());
	cout<<"$";
}

void TroChoi::TaoTien()
{
	srand(time(NULL));
	xTien=rand()%15+5;
	yTien=rand()%16+5;
	duongDua[xTien][yTien]='$';
}
	
bool TroChoi::KiemTraAnTien()
{
	int y=xeNguoiChoi.LayXTam();
	int x=xeNguoiChoi.LayYTam();
	if(abs(x-xTien)<2&&abs(y-yTien)<2)
	{
		if(yTien==y&&abs(x-xTien)==1)
			return false;
		else
			return true;
	}
	return false;
}

void TroChoi::XuLy()
{
	duongDua[xTien][yTien]=' ';
	TaoTien();
	nguoiChoi.TangTien();
}

void TroChoi::XuatSauTroChoi()
{
	int k=1;
	do
	{
		this->MoveCursor(0, 0);
		cout<<"Tien cua "<<nguoiChoi.LayTen()<<" co duoc: "<<nguoiChoi.LayTien()<<endl;
	cout<<"Tien cao nhat: "<<danhSach[0].LayTien()<<endl;
		if(k==1)
		{
			this->MoveCursor(7, 2);
			cout<<"(Space!)";
			k=-k;
		}
		else
		{
			this->MoveCursor(7, 2);
			cout<<"        ";
			k=-k;
		}
		Sleep(200);
	} while(!GetAsyncKeyState(VK_SPACE));
	system("cls");
	cout<<"DANH SACH 10 NGUOI CAO TIEN NHAT!"<<endl;
	for(int i=0; i<10; i++)
	{
		cout<<i+1<<"."<<endl;
		danhSach[i].Xuat();
	}
}

void TroChoi::CanhGiua(int a, char* s)
{
	this->MoveCursor((80-strlen(s))/2, a);
	cout<<s;
}