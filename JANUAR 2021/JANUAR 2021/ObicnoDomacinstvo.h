#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class ObicnoDomacinstvo
{
protected:
	int id;
	float povrsina;
	float utrosenaEn;
public:
	ObicnoDomacinstvo(int id, float p, float utr)
	{
		this->id = id;
		povrsina = p;
		utrosenaEn = utr;
	}

	int getId()
	{
		return id;
	}

	float prosecnaPotrosnja()
	{
		return (float)utrosenaEn / povrsina;
	}

	virtual float svotaNovca()
	{
		return (float)utrosenaEn * 10;
	}

	virtual void prikazi()
	{
		cout << id << " " << povrsina << " " << utrosenaEn << endl;
	}
};