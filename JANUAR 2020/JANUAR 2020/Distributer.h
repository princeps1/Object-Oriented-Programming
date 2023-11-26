#pragma once
#include "Putnicka.h"

class Distributer
{
private:
	Putnicka** niz;
	int maxBr;
	int trBr;
public:
	Distributer(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new Putnicka * [max];
	}

	~Distributer()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}

	void dodaj(Putnicka& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = &novi;
		}
	}

	void obrisi(int redniBr)
	{
		delete niz[redniBr - 1];
		for (int i = redniBr - 1; i < trBr; i++)
		{
			niz[i] = niz[i + 1];
		}
		trBr--;
	}

	void prikaziL()
	{
		cout << "Lista svih salona:" << endl;
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->prikazi();
			cout << endl;
		}
	}

	int brZapVeci(int granica)
	{
		int fleg = 0;
		for (int i = 0; i < trBr; i++)
		{
			if(niz[i]->getBrZap() > granica)
			{
				fleg++;
			}
		}
		return fleg;
	}

	int ukupanBrProd()
	{
		int ukupno = 0;
		for (int i = 0; i < trBr; i++)
		{
			ukupno+=niz[i]->getBrProd();
		}
		return ukupno;
	}

	int prosecnaEfik()
	{
		return ukupanBrProd() / trBr;
	}
};