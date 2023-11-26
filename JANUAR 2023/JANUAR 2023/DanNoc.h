#pragma once
#include "Dan.h"

class DanNoc :public Dan
{
private:
	int osnovnaCenaNocne;//OSNOVNA CENA NOCNE KARTE
	int brNVazenja;//BROJ NOCI ZA KOJE VAZI
public:
	DanNoc(int id, int rBr, int brD, int osnovna, int p, int osnovnaN, int brN)
		:Dan(id, rBr, brD, osnovna, p)
	{
		osnovnaCenaNocne = osnovnaN;
		if (brN == brD || brN - 1 == brD)
		{
			brNVazenja = brN;
		}
		else 
			throw"Broj izmedju noci i dana je veci od dozvoljenog!";
	}

	float zbirniPopust()
	{
		return (float)(popust + brNVazenja) * 0.02;
	}

	float cena()
	{
		return (float)osnovnaCenaNocne + zbirniPopust();
	}

	void setBrDVazenja(int zadatiBrD)
	{
		Dan::setBrDVazenja(zadatiBrD);
		brNVazenja += zadatiBrD;
	}

	void fajl(ofstream& f)
	{
		Dan::fajl(f);
		f << osnovnaCenaNocne << " " << brNVazenja;
	}

	void prikazi()
	{
		Dan::prikazi();
		cout << osnovnaCenaNocne << " " << brNVazenja;
	}
};