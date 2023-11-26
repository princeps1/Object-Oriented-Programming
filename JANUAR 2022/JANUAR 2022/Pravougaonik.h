#pragma once
#include "Figura.h"

class Pravougaonik :public Figura
{
private:
	int duzina;
	int sirina;
public:
	Pravougaonik(int x, int y, int duz, int sir)
		:Figura(x, y)
	{
		if (duz > 0 && sir > 0)
		{
			duzina = duz;
			sirina = sir;
		}
		else throw"NEGATIVNA STRANICA";
	}

	void prikazi(ofstream& f)
	{
		Figura::prikazi(f);
		f << duzina << " " << sirina << endl;
	}

	int povrsina()
	{
		return duzina * sirina;
	}

	int obim()
	{
		return (duzina+sirina) * 2;
	}
};