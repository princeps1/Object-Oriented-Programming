#pragma once
#include "Objekat.h"

class ObjekatBasta :public Objekat
{
private:
	int pBaste;
	int porez;//KOLIKO JE POREZ NA BASTU VECI OD STANDARDNOG POREZA ZA PRIZEMLJE OBJEKTA
public:
	ObjekatBasta(int id, int brS, int pP, int pS, int pB, int p)
		:Objekat(id, brS, pP, pS)
	{
		pBaste = pB;
		porez = p;
	}

	void promeni(int kod, int vrednost)
	{
		Objekat::promeni(kod, vrednost);
		if (kod == 2)
		{
			pBaste = vrednost;
		}
	}
	
	void prikazi()
	{
		Objekat::prikazi();
		cout << pBaste << " " << porez << endl;
	}
};