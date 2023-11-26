#pragma once 
#include "Posetilac.h"

class StvarniPosetilac :public Posetilac
{
private:
	char* trRadniStat;//TRENUTNI RADNI STATUS,SME SAMO UNOS "zaposljen" "nezaposljen"
	int brTacnihOdg;//BROJ TACNIH ODGOVORA NA KVIZU
	int popust;
public:
	StvarniPosetilac(int termin, char* ime, char* prezime, int cena, char* status, int odgovori, int pop)
		:Posetilac(termin, ime, prezime, cena)
	{
		trRadniStat = new char[strlen(status) + 1];
		strcpy(trRadniStat, status);

		brTacnihOdg = odgovori;
		popust = pop;
	}

	StvarniPosetilac()
	{
		trRadniStat = new char[30];
		brTacnihOdg = 0;
		popust = 0;
	}

	~StvarniPosetilac()
	{
		delete[] trRadniStat;
	}

	int cenaUlaznice()
	{
		return cena - popust;
	}

	int koefZainteresovanosti()
	{
		return brTacnihOdg;
	}

	void prikazi(ostream& f)
	{
		Posetilac::prikazi(f);
		f << trRadniStat << " " << brTacnihOdg << " " << popust;
	}
};