#include "Xe.h"


Xe::Xe()
{
	banhXe='*';
	thanXeTrai=thanXePhai='o';
	tamXe='X';
	ThietLapXe();
	tam.GanXY(12, 22);
}

Xe::Xe(char a, char b , char c, char d, Diem e)
{
	banhXe=a;
	thanXeTrai=b;
	thanXePhai=c;
	tamXe=d;
	tam=e;
	ThietLapXe();
}

Xe::~Xe()
{
}

void Xe::ThietLapXe()
{
	xe[0][0]=xe[0][2]=xe[2][0]=xe[2][2]=banhXe;
	xe[1][0]=thanXeTrai;
	xe[1][2]=thanXePhai;
	xe[1][1]=tamXe;
	xe[0][1]=xe[2][1]=' ';
}
void Xe::XuatXe()
{
	for(int i=0; i<3; i++)
	{
		MoveCursor(tam.LayX()-1, tam.LayY()-1+i);
		for(int j=0; j<3; j++)
			cout<<xe[i][j];
		cout<<endl;
	}
}

void Xe::NhapXe()
{
	cout<<"Banh xe: ";
	cin>>banhXe;
	cout<<"Cua xe trai: ";
	cin>>thanXeTrai;
	cout<<"Cua xe phai: ";
	cin>>thanXePhai;
	cout<<"Than xe: ";
	cin>>tamXe;
	ThietLapXe();
	tam.GanXY(17, 10);
}

void Xe::DichTrai()
{
	int a=tam.LayX()-1;
	tam.GanX(a);
}

void Xe::DichPhai()
{
	int a=tam.LayX()+1;
	tam.GanX(a);
}

void Xe::DichLen()
{
	int a=tam.LayY()-1;
	tam.GanY(a);
}

void Xe::DichXuong()
{
	int a=tam.LayY()+1;
	tam.GanY(a);
}

void Xe::MoveCursor(int x0, int y0)
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = x0;
	Position.Y = y0;
	SetConsoleCursorPosition(hOut, Position);
}

void Xe::XoaXe()
{
	for(int i=0; i<3; i++)
	{
		MoveCursor(tam.LayX()-1, tam.LayY()-1+i);
		cout<<"   ";
		cout<<endl;
	}
}

int Xe::LayXTam()
{
	return tam.LayX();
}

int Xe::LayYTam()
{
	return tam.LayY();
}

void Xe::GanTam(int x0, int y0)
{
	tam.GanXY(x0, y0);
}
