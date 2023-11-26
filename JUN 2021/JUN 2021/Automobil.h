#pragma once
#include "Vozilo.h"

class Automobil:public Vozilo
{
private:
	int maxBrPutnika;//MAKSIMALNI BROJ PUTNIKA ZA KOJE JE REGISTROVANO VOZILO
public:
	Automobil() :Vozilo()
	{
		maxBrPutnika = 0;
	}

	~Automobil(){}

	void citaj(ifstream& f)
	{
		Vozilo::citaj(f);
		f >> maxBrPutnika;
	}

	void upisi(ofstream& f)
	{
		Vozilo::upisi(f);
		f << maxBrPutnika;
	}

	bool uporedi(Vozilo& V)
	{
		if (getMaxBrzina() > V.getMaxBrzina())
			return true;
		else
			return false;
	}

};