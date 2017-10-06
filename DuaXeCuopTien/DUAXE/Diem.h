#pragma once
#include <iostream>
using namespace std;

class Diem
{
private:
	int x;
	int y;
public:
	Diem();
	Diem(int, int);
	~Diem();
	int LayX();
	int LayY();
	void GanXY(int, int);
	void GanX(int);
	void GanY(int);
};

