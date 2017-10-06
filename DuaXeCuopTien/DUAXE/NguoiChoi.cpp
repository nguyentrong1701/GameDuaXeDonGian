#include "NguoiChoi.h"


NguoiChoi::NguoiChoi()
{
	ten="NoName";
	capDo=1;
	tien=0;
}


NguoiChoi::~NguoiChoi()
{
}

NguoiChoi::NguoiChoi(string a, int b, int c)
{
	ten=a;
	capDo=b;
	tien=c;
}

void NguoiChoi::NhapTen()
{
	int k=0;
	char temp[20];
	while(1)
	{
		gets(temp);
		for(int i=0; i<strlen(temp); i++)
		{
			if(temp[i]==' ')
			{
				k=1;
				break;
			}
		}
		if(k==1)
		{
			cout<<"Ten nhap phai khong co khoang trang!"<<endl;
			k=0;
			continue;
		}
		break;
	}
	ten=temp;
}

void NguoiChoi::Xuat()
{
	cout<<"\tTen:\t"<<ten<<endl;
	cout<<"\tCap do:\t"<<capDo<<endl;
	cout<<"\tTien:\t"<<tien<<endl;
}
string NguoiChoi::LayTen()
{
	return ten;
}
void NguoiChoi::TangCapDo()
{
	capDo++;
}

void NguoiChoi::TangTien()
{
	tien++;
}

int NguoiChoi::LayCapDo()
{
	return capDo;
}

int NguoiChoi::LayTien()
{
	return tien;
}

void NguoiChoi::GanTen(string s)
{
	ten=s;
}

void NguoiChoi::GanCapDo(int a)
{
	capDo=a;
}

void NguoiChoi::GanTien(int a)
{
	tien=a;
}
void NguoiChoi::LayTuFile(char* filename)
{
	fstream f(filename, ios::in);
	f>>ten;
	f>>capDo;
	f>>tien;
	f.close();
}

void NguoiChoi::GhiVaoFile(char* filename)
{
	fstream f(filename, ios::app);
	f<<ten<<endl;
	f<<capDo<<endl;
	f<<tien<<endl;
}