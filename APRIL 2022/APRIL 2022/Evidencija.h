#pragma once
#include "Student.h"

class Evidencija
{
private:
	Student** niz;
	int trBr;
	int maxBr;
public:
	Evidencija(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new Student * [max];
	}

	~Evidencija()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}

	void dodaj(Student& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = &novi;
		}
		else
			throw"NIZ JE PUN";
	}

	void obrisi(int index)
	{
		int i = 0;
		bool nadjen = false;
		while (i < trBr && !nadjen)
		{
			if (niz[i]->getIndex() == index)
			{
				nadjen = true;
				for (int j = i; j < trBr-1; j++)
				{
					niz[j] = niz[j + 1];
				}
				trBr--;
			}
			else
			{
				i++;
			}
		}
	}

	void izmeniBodove(int index,int dodatniBodovi)
	{
		int i = 0;
		bool nadjen = false;
		while (i < trBr && !nadjen)
		{
			if (niz[i]->getIndex() == index)
			{
				nadjen = true;
				niz[i]->setBodovi(dodatniBodovi);
			}
			else i++;
		}
	}

	void prikaziL()
	{
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->prikazi();
			cout << endl;
		}
	}

	int brStudenataPolozili()
	{
		int counter = 0;
		for (int i = 0; i < trBr; i++)
		{
			if (niz[i]->polozio() == true)
			{
				counter++;
			}
		}
		return counter;
	}

	float prosek()
	{
		int ukupanBrBodova = 0;
		for (int i = 0; i < trBr; i++)
		{
			if (niz[i]->polozio() == true)
			{
				ukupanBrBodova += niz[i]->ukupanBrojBodova();
			}
		}
		return (float) ukupanBrBodova/ brStudenataPolozili();
	}

	//FALI FUNKCIJA ZA PRONALAZENJE NAJVECEG
};