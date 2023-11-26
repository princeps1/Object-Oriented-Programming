#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
#include <fstream>

using namespace std;

class Figura
{
protected:
	int X;
	int Y;
public:
	Figura(int x, int y)
	{
		X = x;
		Y = y;
	}

	virtual void prikazi(ofstream& f)
	{
		f << X << " " << Y << " ";
	}

	virtual int povrsina() = 0;
	virtual int obim() = 0;
};