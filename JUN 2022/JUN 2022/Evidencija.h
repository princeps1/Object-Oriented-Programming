#pragma once
#include "Ucesnik.h"
#include <iostream>


class Evidencija
{
private:
	Ucesnik** niz;
	int trBr;
	int maxBr;
public:
	Evidencija(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new Ucesnik * [max];
	}

	~Evidencija()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}

	
	//void dodaj(Ucesnik& novi)
	//{
	//	if (trBr < maxBr)
	//	{
	//		niz[trBr++] = &novi;
	//	}
	//	else
	//		throw"NIZ PUN";
	//}

	//DRUGI NACIN ZA UBACIVANJE ELEMENATA U NIZ PONTERA
	void dodaj(Ucesnik* novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = novi;
		}
		else
			throw"NIZ PUN";
	}

	void obrisi(int r)//r-REDNI BROJ UCESNIKA KOJI TREBA DA SE IZBRISE
	{
		if (r < trBr)
		{
			for (int i = r; i < trBr-1; i++)
			{
				niz[i] = niz[i + 1];
			}
			trBr--;
		}
	}
	 
	void upisiL(ofstream& f)
	{
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->upisi(f);
			f << endl;
		}
	}

	float srednjaVrednost()
	{
		int ukupno = 0;
		int counter = 0;
		for (int i = 0; i < trBr; i++)
		{
			if (niz[i]->proso() == true)
			{
				ukupno += niz[i]->ukupnoPoena();
				counter++;
			}
		}
		return (float)ukupno / counter;
	}

	Ucesnik& najjaciUcesnik()
	{
		int imax = 0;
		for (int i = 1; i < trBr; i++)
		{
			if (niz[imax]->ukupnoPoenaZirija() < niz[i]->ukupnoPoenaZirija())
			{
				imax = i;
			}
		}
		return *niz[imax];
	}

	void sortiraj()
	{
		for (int i = 0; i < trBr-1; i++)
		{
			int imax = i;
			for (int j = i + 1; j < trBr; j++)
			{
				if (niz[j]->brPomocnog() > niz[imax]->brPomocnog())
				{
					imax = j;
				}
				Ucesnik* pom = niz[i];//SAMO JE NAPRAVLJEN POINTER NA RODITELJSKU KLASU NE I OBJEKAT,ZATO JE MOGLO OVO IAKO JE RODITELJSKA KLASA APSTRAKTNA
									  //,U PROMENLJIVU pom STAVLJAM ADRESU JER TO MOZE
				niz[i] = niz[imax];
				niz[imax] = pom;
			}
		}
	}

};










































//NIJE DOBRO SKROZ PROMAZENO
//void sortiranje()
//{
//	Ucesnik** pomNiz = new Ucesnik * [this->maxBr];
//	for (int i = 0; i < this->trBr; i++)
//	{
//		pomNiz[i] = niz[i];
//		delete niz[i];
//	}
//	delete[] niz;
//	niz = new Ucesnik * [this->maxBr];
//	int imax = 0;
//	for (int i = 1; i < trBr; i++)
//	{
//		if (pomNiz[i]->brPomocnog() > pomNiz[imax]->brPomocnog())
//		{
//			imax = i;
//		}
//		niz[this->trBr++] = pomNiz[imax];
//	}
//
//	for (int i = 0; i < trBr; i++)
//	{
//		delete niz[i];
//	}
//	delete[] niz;
//}