#pragma once
#include "Posetilac.h"

class Sistem
{
private:
	char* naziv;
	Posetilac** niz;
	int trBr;
	int maxBr;
public:
	Sistem(char* naz,int max)
	{
		naziv = new char[strlen(naz) + 1];
		strcpy(naziv, naz);

		niz = new Posetilac * [max];

		trBr = 0;
		maxBr = max;
	}

	~Sistem()
	{
		delete[] naziv;

		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}


	
	void dodaj(Posetilac* novi)//RADJEN NA DRUGI NACIN I RADI NA OBA NACINA
	{
		if (trBr == 0)
		{
			niz[trBr++] = novi;
		}

		else if (trBr < maxBr)
		{
			bool zauzet = false;//AKO zauzet POSTANE TRUE ONDA JE TERMIN VEC ZAUZET
			int i = 0;
			while (i < trBr && zauzet ==false)
			{
				if ((*niz[i]) == *novi)
				{
					zauzet = true;//OVA PROMENLJIVA TEHNICKI NIJE NI TREBALA
					throw"TERMIN JE ZAUZET";
				}
				else i++;
			}

			bool nadjen = false;//AKO nadjen PSOTANE TRUE,NASLI SMO MESTO DE TREBA DA UMETNEMO NOVI OBJEKAT
			i = 0;
			while (i < trBr && nadjen == false)
			{
				if ((*niz[i]) > *novi)
				{
					nadjen = true;
					for (int j = trBr; j > i; j--)
					{
						niz[j] = niz[j - 1];
					}
					niz[i] = novi;
					trBr++;
				}
				else
					i++;
			}
			if (i == trBr)
			{
				niz[trBr++] = novi;
			}
		}
	}

	void prikaziNiz(ofstream& f)
	{
		f << naziv << endl;
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->prikazi(f);
			f << endl;
		}
	}

	void obrisi(int termin)
	{
		int i = 0;
		bool nadjen = false;
		while (i < trBr && nadjen == false)
		{
			if (termin == (*niz[i]))
			{
				nadjen = true;
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

	int prihodZamka()
	{
		int ukupno = 0;
		for (int i = 0; i < trBr; i++)
		{
			ukupno += niz[i]->cenaUlaznice();
		}
		return ukupno;
	}

	//MOGUCE JE VRATITI PODATKE O JEDNOM POSETIOCU KOJI DOBIJA ORDEN DREVNOG ZAMKA.
	//ORDEN ZAMKA SE DODELJUJE POSETIOCU KOJI IMA NAJVECI KOEFICIJENT ZAINTERESOVANOSTI

	Posetilac& najjaciPosetilac()
	{
		int imax = 0;
		for (int i = 1; i < trBr; i++)
		{
			if (niz[i]->koefZainteresovanosti() > niz[imax]->koefZainteresovanosti())
			{
				imax = i;
			}
		}
		return *niz[imax];
	}
};









