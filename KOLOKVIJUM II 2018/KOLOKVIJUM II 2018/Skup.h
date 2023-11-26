#pragma once
#include "Procesor.h"

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
		maxBr = max;
		trBr = 0;
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
			niz[trBr++] = novi;
		}
	}

	friend istream& operator>>(istream& in, Skup<T>& S)
	{
		for (int i = 0; i < S.trBr; i++)
		{
			in >> S.niz[i];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, Skup<T>& S)
	{
		for (int i = 0; i < S.trBr; i++)
		{
			out << S.niz[i]<<" ";
		}
		return out;
	}

	//int brDuplikata(Skup<T>& objekat)
	//{
	//	int duplikat = 0;
	//	for (int i = 0; i < trBr; i++)
	//	{
	//		if (niz[i] == objekat)//OVERLAOD
	//		{
	//			duplikat++;
	//		}
	//	}
	//	return duplikat;
	//}

	int obrisiDuplikatIVratiBrDuplikata()
	{
		int brDuplikata = 0;
		for (int i = 0; i < trBr - 1; i++)
		{
			for (int j = i + 1; j < trBr; j++)
			{
				if (niz[i] == niz[j])
				{
					for (int k = j; k < trBr - 1; k++)
					{
						niz[k] = niz[k + 1];
					}
					trBr--;
					brDuplikata++;
				}
			}
		}
		return brDuplikata;
	}

	void sortiraj()//NEOPADAJUCI
	{
		for (int i = 0; i < trBr-1; i++)
		{
			int imin = i;
			for (int j = i + 1; j < trBr; j++)
			{
				if (niz[imin] > niz[j])//OVERLOAD
				{
					imin = j;
				}
			}
			T pom = niz[imin];//OVERLOAD
			niz[imin] = niz[i];//OVERLOAD
			niz[i] = pom;//OVERLOAD
		}
	}

	Skup<T>* operator+(Skup<T>& rhs)
	{
		int maxBrUnije = this->maxBr + rhs.maxBr;
		Skup<T>* unija = new Skup<T>(maxBrUnije);

		for (int i = 0; i < this->trBr; i++)
		{
			unija->niz[unija->trBr++] = this->niz[i];
		}

		for (int i = 0; i < rhs.trBr; i++)
		{
			unija->niz[unija->trBr++] = rhs.niz[i];
		}
		int duplikati=unija->obrisiDuplikatIVratiBrDuplikata();

		//trBr -= duplikati;
		return unija;
	}

	Skup<T>* operator-(Skup<T>& rhs)
	{
		Skup<T>* presek = new Skup<T>(this->maxBr);

		for (int i = 0; i < this->trBr; i++)//1 2 3 4 
		{
			for (int j = 0; j < rhs.trBr; j++)//3 4 5 6 
			{
				if (this->niz[i] == rhs.niz[j])//OVERLOAD
				{
					presek->niz[presek->trBr++] = rhs.niz[j];//OVERLOAD
				}
			}
		}
		int duplikati=presek->obrisiDuplikatIVratiBrDuplikata();
		//trBr -= duplikati;
		return presek;
	}
};