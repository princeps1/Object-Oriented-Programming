#pragma once
#include "Figura.h"

class Kvadrat :public Figura
{
private:
	int duzinaKv;
public:
	Kvadrat(int x, int y, int duzKv)
		:Figura(x, y)
	{
		if (duzKv > 0)
		{
			duzinaKv = duzKv;
		}
		else throw"NEGATIVNA STRANICA";
	}

	void prikazi(ofstream& f)
	{
		Figura::prikazi(f);
		f << duzinaKv << endl;
	}

	int povrsina()
	{
		return pow(duzinaKv,2);
	}

	int obim()
	{
		return duzinaKv * 4;
	}
};