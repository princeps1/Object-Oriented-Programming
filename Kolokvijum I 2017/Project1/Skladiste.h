#pragma once
#include "Tecni.h"

class Skladiste
{
private:
	char* naziv;
	Tecni** niz;
	int maxBr;
	int trBr;
public:
	Skladiste(char* n,int max)
	{
		maxBr = max;
		trBr = 0;

		naziv = new char[strlen(n) + 1];
		strcpy(naziv, n);

		niz = new Tecni * [max];
	}

	~Skladiste()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;

		delete[] naziv;
	}

	void dodaj(Tecni& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = &novi;
		}
	}

	void prikaziNiz()
	{
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->prikazi();
		}
	}
	
};