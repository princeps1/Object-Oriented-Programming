#pragma once
#include <iostream>
#include "Takmicar.h"

using namespace std;

template<class T>
class Skup
{
private:
	T* niz;
	int trBr;
	int maxBr;
public:
	Skup(int max)
	{
		trBr = 0;
		maxBr = max;
		niz = new T[max];
	}

	~Skup()
	{
		delete[] niz;
	}

	void dodaj(T& novi)
	{
		if (trBr < maxBr)
		{
			bool duplikat = false;
			int i = 0;
			while (i < trBr && !duplikat)
			{
				if (niz[i] == novi)//OVERLAOD
				{
					duplikat = true;
				}
				else i++;
			}
			if (duplikat == false)
			{
				niz[trBr++] = novi;//OVERLAOD
			}
		}
		else throw"NIZ JE PUN";
	}

	void obrisi(int id)
	{
		int i = 0;
		bool nadjen = false;
		while (i < trBr && nadjen == false)
		{
			if (id == niz[i])//OVERLOAD
			{
				nadjen = true;
				for (i; i < trBr; i++)
				{
					niz[i] = niz[i + 1];
				}
				trBr--;
			}
			else i++;
		}
	}

	Skup<T>* unija(Skup<T>& n2)//n2 JE NIZ2
	{
		int maxUnije = this->trBr + n2.trBr;
		Skup<T>* unija = new Skup<T>(maxUnije);

		//UBACIVANJE ELEMENATA
		for (int i = 0; i < this->trBr; i++)
		{
			unija->niz[unija->trBr++] = this->niz[i];
		}
		for (int i = 0; i < n2.trBr; i++)
		{
			unija->niz[unija->trBr++] = n2.niz[i];
		}
		//

		//IZBACIVANJE DUPLIAKTA
		for (int i = 0; i < unija->trBr; i++)
		{
			for (int j = i + 1; j < unija->trBr; j++)
			{
				if (unija->niz[i] == unija->niz[j])//OVERLOAD
				{
					for (int k = j; k < unija->trBr; k++)
					{
						unija->niz[k] = unija->niz[k+1];//OVERLOAD
					}
					unija->trBr--;
				}
			}
		}
		return unija;
	}

	friend ostream& operator<< (ostream & out, Skup<T>&S)
	{
		for (int i = 0; i < S.trBr; i++)
		{
			out << S.niz[i]<<" ";
		}
		return out;
	}

};