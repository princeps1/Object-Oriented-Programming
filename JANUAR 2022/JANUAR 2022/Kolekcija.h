#pragma once
#include "Figura.h"

class Kolekcija
{
	Figura** niz;
	int maxBr;
	int trBr;
public:
	Kolekcija(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new Figura * [max];
	}

	~Kolekcija()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}

	void dodaj(Figura& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = &novi;
		}
		else
		{
			Figura** pomNiz = new Figura * [trBr];
			for (int i = 0; i < trBr; i++)
			{
				pomNiz[i] = niz[i];
				delete niz[i];
			}

			maxBr += maxBr / 2;
			niz = new Figura * [maxBr];

			for (int i = 0; i < trBr; i++)
			{
				niz[i] = pomNiz[i];
				delete pomNiz[i];
			}
			delete[] pomNiz;

			niz[++trBr] = &novi;
		}
	}

	void povrsinSvihFigura()
	{
		for (int i = 0; i < trBr; i++)
		{
			cout << "Povrsina " << i + 1 << ". figure: " << niz[i]->povrsina() << endl;
		}
	}

	void obimSvihFigura()
	{
		for (int i = 0; i < trBr; i++)
		{
			cout << "Obim " << i + 1 << ". figure: " << niz[i]->obim() << endl;
		}
	}

	void prikaziL(ofstream& f)
	{
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->prikazi(f);
		}
		f << endl;
	}

	void sortiraj()//NIJE DOBRO ODRADJENA
	{

		for (int i = 0; i < trBr - 1; i++)
		{
			int imin = i;
			for (int j = 1; j < trBr; j++)
			{
				if (niz[imin]->obim() > niz[j]->obim())
				{
					imin = j;
				}
			}

		}
	}




};