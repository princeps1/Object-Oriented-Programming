#pragma once
#include "Redovni.h"

class Sistem
{
private:
	Redovni** niz;
	int maxBr;
	int trBr;
public:
	Sistem(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new Redovni * [max];
	}
	~Sistem()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}

	void dodaj(Redovni& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = &novi;
		}
		else
			cout << "Niz je pun";
	}

	void obrisi(char* pol, char* dol, char* dat)
	{
		int nadjen = 0;
		int i = 0;
		while (i < trBr && nadjen == 0)
		{
			if (strcmp(pol, niz[i]->getPolD()) == 0 &&
				strcmp(dol, niz[i]->getDolD()) == 0 &&
				strcmp(dat, niz[i]->getDatIVreme()) == 0)
			{
				delete niz[i];
				for (int j = i; j < trBr; j++)
				{
					niz[j] = niz[j + 1];
				}
				nadjen = 1;
			}
			else
				i++;
		}
		if (i == trBr)
		{
			cout << "Ne postoji takav let";
		}
	}

	void rezervisi(char* pol, char* dol, char* dat)
	{
		int i = 0;
		int nadjen = 0;
		while (i < trBr && nadjen == 0)
		{
			if (strcmp(pol, niz[i]->getPolD()) == 0 &&
				strcmp(dol, niz[i]->getDolD()) == 0 &&
				strcmp(dat, niz[i]->getDatIVreme()) == 0)
			{
				niz[i]->setBrRezMesta();
				nadjen = 1;
			}
			else
				i++;
		}
	}

	void prikazi()
	{
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->prikaziL();
			cout << endl;
		}
	}
};
