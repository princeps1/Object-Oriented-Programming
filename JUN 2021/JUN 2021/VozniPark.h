#pragma once
#include "Vozilo.h"

class VozniPark
{
private:
	Vozilo** niz;
	int trBr;
	int maxBr;
	char* tipVoznogParka;
public:
	VozniPark(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new Vozilo * [max];
		tipVoznogParka = new char[30];
	}

	~VozniPark()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;

		delete[] tipVoznogParka;
	}

	void dodaj(Vozilo& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = &novi;
		}

		else
		{
			int i = 0;
			Vozilo** pomNiz = new Vozilo * [trBr];

			while(i<trBr)
			{
				pomNiz[i] = niz[i];
				delete niz[i];
				i++;
			}//NA KRAJU OVE WHILE PETLJE IJE JEDNAKO SA trBr
			delete[] niz;

			maxBr += maxBr / 2;
			niz = new Vozilo * [maxBr];

			int j = 0;
			while(j<i)
			{
				niz[j] = niz[j];
				delete pomNiz[j];
				j++;
			}
			delete[] pomNiz;
			niz[++trBr] = &novi;
		}
	}

	void citajNiz(ifstream& f)
	{
		f >> tipVoznogParka;
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->citaj(f);
		}
	}

	void upisiNiz(ofstream& f)
	{
		f << tipVoznogParka << endl;
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->upisi(f);
			f << endl;
		}

	}

	void sortiraj()
	{
		for (int i = 0; i < trBr-1; i++)
		{
			int imax = i;
			for (int j = i + 1; j < trBr; j++)
			{
				if (niz[imax]->uporedi(*niz[j]) == false)
				{
					imax = j;
				}
			}
			if (imax != i)
			{
				Vozilo* pom = niz[i];
				niz[i] = niz[imax];
				niz[imax] = pom;
			}
		}
	}


};