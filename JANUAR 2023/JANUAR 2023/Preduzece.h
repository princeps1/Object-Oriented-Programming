#pragma once
#include "Dan.h"
#include <fstream>

using namespace std;

class Preduzece
{
private:
	Dan** niz;
	int maxBr;
	int trBr;
public:
	Preduzece(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new Dan*[max];
	}
	~Preduzece()
	{
		for (int i = 0; i < trBr; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}

	void dodaj(Dan& novi)
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
		while(i<trBr && nadjen==false)
		{
			if (niz[i]->getId() == id)
			{
				nadjen = true;
				delete niz[i];
			}
			else i++;
		}
		if (nadjen == true)
		{
			for (int j = i; j < trBr; j++)
			{
				niz[j] = niz[j + 1];
			}
			trBr--;
		}
	}


	void produzi(int id,int zadatiBrD)
	{
		int i = 0;
		bool nadjen = false;
		while (i < trBr && nadjen == false)
		{
			if (niz[i]->getId() == id)
			{
				nadjen = true;
				niz[i]->setBrDVazenja(zadatiBrD);
			}
			else
				i++;
		}
	}

	void Upisifajl(ofstream& f)//OVO NE TREBA PO ZADATKU
	{
		for (int i = 0; i < trBr; i++)

		{
			niz[i]->fajl(f);
			f << endl;
		}
	}

	void prikaziNiz()
	{
		for (int i = 0; i < trBr; i++)
		{
			niz[i]->prikazi();
			cout << endl;
		}
	}

	float zarada()
	{
		float ukupno = 0;
		for (int i = 0; i < trBr; i++)
		{
			ukupno += niz[i]->cena();
		}
		return ukupno;
	}
};