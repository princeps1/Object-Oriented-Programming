#pragma once
#include "Vozilo.h"

class Kamion :public Vozilo
{
private:
	int nosivost;//MAKSIMALNI BROJ PUTNIKA ZA KOJE JE REGISTROVANO VOZILO
public:
	Kamion():Vozilo()
	{
		nosivost = 0;
	}

	~Kamion() {}

	void citaj(ifstream& f)
	{
		Vozilo::citaj(f);
		f >> nosivost;
	}

	void upisi(ofstream& f)
	{
		Vozilo::upisi(f);
		f << nosivost;
	}

	bool uporedi(Vozilo& V)
	{
		if (getPotrosnja() > V.getPotrosnja())
			return true;
		else
			return false;
	}



};