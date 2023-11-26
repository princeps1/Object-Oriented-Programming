#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Dan
{
protected:
	int id;
	int rBrDPocetka;//REDNI BROJ DANA POCETKA NJENOG VAZENJA U ODNOSU NA PRVI DAN SKIJASKE SEZONE
	int brDVazenja;//BROJ DANA VAZENJA KARTE
	int osnovnaCena;//OSNOVNA CENA KARTE
	int popust;
public:
	Dan(int id, int rBr, int brD, int osnovna, int p)
	{
		this->id = id;
		rBrDPocetka = rBr;
		brDVazenja = brD;
		osnovnaCena = osnovna;
		popust = p;
	}
	virtual float zbirniPopust()
	{
		return(float) (popust + brDVazenja) * 0.02;
	}


	virtual float cena()
	{
		return (float)osnovnaCena + zbirniPopust();
	}

	int getId()
	{
		return id;
	}

	virtual void setBrDVazenja(int zadatiBrD)
	{
		brDVazenja += zadatiBrD;
	}

	virtual void fajl(ofstream& f)
	{
		f << id << " " << rBrDPocetka << " " << brDVazenja << " " <<
			osnovnaCena << " " << popust << " ";
	}

	virtual void prikazi()
	{
		cout << id << " " << rBrDPocetka << " " << brDVazenja << " " <<
			osnovnaCena << " " << popust << " ";
	}
};