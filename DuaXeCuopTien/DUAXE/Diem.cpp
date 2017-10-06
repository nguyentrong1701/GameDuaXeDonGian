#include "Diem.h"


Diem::Diem()
{
	x=y=0;
}

Diem::Diem(int a, int b)
{
	x=a;
	y=b;
}

Diem::~Diem()
{
}

int Diem::LayX()
{
	return x;
}

int Diem::LayY()
{
	return y;
}

void Diem::GanXY(int x0, int y0)
{
	x=x0;
	y=y0;
}

void Diem::GanX(int x0)
{
	x=x0;
}

void Diem::GanY(int y0)
{
	y=y0;
}
