#pragma once
#include "Objekat.h"

class Sistem
{
private:
	Objekat** niz;
	int trBr;
	int maxBr;
public:
	Sistem(int max)
	{
		trBr = 0;
		maxBr = max;
		niz = new Objekat*[max];
	}
	~Sistem()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}

	void dodaj(Objekat& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = &novi;
		}
		else
			throw"Niz je pun";
	}

	void obrisi(int id)
	{
		int i = 0;
		bool nadjen = false;
		while (i < trBr && nadjen == false)
		{
			if (niz[i]->getId() == id)
			{
				nadjen = true;
				delete niz[i];
				for (int j = i; j < trBr; j++)
				{
					niz[j] = niz[j + 1];
				}
				trBr--;
			}
			else
				i++;
		}
	}

	int ukupnaPPrizemlja()
	{
		int ukupno = 0;
		for (int i = 0; i < trBr; i++)
		{
			ukupno += niz[i]->getPovrsinuP();
		}
		return ukupno;
	}

	void prikaziNiz()
	{
		for (int i= 0; i < trBr; i++)
		{
			niz[i]->prikazi();
			cout << endl;
		}
	}
};