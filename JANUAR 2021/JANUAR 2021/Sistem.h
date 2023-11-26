#pragma once

#include "ObicnoDomacinstvo.h"

class Sistem
{
private:
	ObicnoDomacinstvo** niz;
	int maxBr;
	int trBr;
public:
	Sistem(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new ObicnoDomacinstvo * [max];
	}

	~Sistem()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}

	void dodaj(ObicnoDomacinstvo& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = &novi;
		}
		else
			cout << "Nema mesta"<<endl;
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

	void prosecnaPotrosnjaElEn()
	{
		cout << "PROSECNA POTROSNJA SVIH DOMACINSTAVA:" << endl;
		for (int i = 0; i < trBr; i++)
		{
			cout<<niz[i]->prosecnaPotrosnja()<<endl;
		}
	}

	void prikaziNiz()
	{
		cout << "PODACI SVI DOMACINSTAVA" << endl;
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->prikazi();
		}
	}

};