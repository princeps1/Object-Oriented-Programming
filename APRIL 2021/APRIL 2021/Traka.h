#pragma once
#include "Proizvod.h"

class Traka
{
private:
	Proizvod** niz;
	int maxBr;
	int trBr;
public:

	Traka(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new Proizvod * [max];
	}

	~Traka()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}

	void dodaj(Proizvod& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = &novi;
		}
	}

	void upisiObrisi(ofstream& f)
	{
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->upisi(f);
			delete niz[i];
		}
		delete[] niz;
	}

	void setMaxBr(int promenjen)
	{
		Proizvod** pomNiz = new Proizvod * [trBr];
		for (int i = 0; i < trBr; i++)
		{
			pomNiz[i] = niz[i];
		}

		maxBr += promenjen;
		niz = new Proizvod * [maxBr];

		for (int i = 0; i < trBr; i++)
		{
			niz[i] = pomNiz[i];
		}
		delete[] pomNiz;
	}

	void zamena(Proizvod& zamenski)
	{
		int trecina = maxBr / 3;
		int i = 0;
		bool nadjen=false;
		while (i < trBr && nadjen == false)
		{
			if (niz[i]->defektan() == true)
			{
				nadjen = true;

				if (i <= trecina)
				{
					delete niz[i];
					niz[i] = &zamenski;
				}
				else
				{
					delete niz[i];
					for (int j = i; j < trBr; j++)
					{
						niz[j] = niz[j + 1];
					}
				}
			}
			else
			{
				i++;
			}
		}
	}

	int trBrDefektnih()
	{
		int brojDefektnih = 0;
		for (int i = 0; i < trBr; i++)
		{
			if(niz[i]->defektan() == true)
			{
				brojDefektnih++;
			}

		}
		return brojDefektnih;
	}

	int trBrPraznih()
	{
		int brojPraznih = 0;
		for (int i = 0; i < trBr; i++)
		{
			if (niz[i] == NULL)
			{
				brojPraznih++;
			}
		}
		brojPraznih += (maxBr - trBr);
		return brojPraznih;
	}
};