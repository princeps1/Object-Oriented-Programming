#pragma once
#include "Zivotinje.h"

#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Sablon
{
private:
	T* niz;
	int maxBr;
	int trBr;
public:
	Sablon(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new T[max];
	}

	~Sablon()
	{
		delete[] niz;
	}

	bool duplikat(T& novi)
	{
		for (int i = 0; i < trBr; i++)
		{
			if (niz[i] == novi)//OVERLOAD
				return true;//DUPLIKAT
		}
		return false;
	}

	bool sortiraj()//RASTUCE SORTIRANJE TREBA DA BUDE
	{
		for (int i = 1; i < trBr; i++)
		{
			if (niz[i-1] > niz[i])//OVERLAOD
			{
				return false;//NISU SORTIRANI
			}
		}
		return true;
	}

	void dodaj(T& novi)
	{
		if (trBr == 0)
		{
			niz[trBr++] = novi;
		}
		else if (trBr < maxBr)
		{
			if (duplikat(novi) == true)
			{
				throw"DUPLIKAT";
			}
			else if (sortiraj() == false)
			{
				throw"NIZ NIJE SORTIRAN";
			}

			int i = 0;
			bool nadjen = false;
			while (i < trBr && nadjen == false)
			{
				if (niz[i] > novi)//OVERLOAD
				{
					nadjen = true;
					for (int j = trBr; j > i; j--)
					{
						niz[j] = niz[j - 1];
					}
					niz[i] = novi;//OVERLOAD
					trBr++;
				}
				else i++;
			}

			if (nadjen == false)
			{
				niz[trBr++] = novi;//OVERLOAD
			}
		}
		else throw"NIZ JE PREPUNJEN";
	}

	void obrisi(int index)
	{
		if (trBr == 0)
			throw"NIZ JE PRAZAN";
		else if (index < 0 && index >= trBr)
		{
			throw"INDEX NIJE VALIDAN";
		}

		for (int i = index; i < trBr; i++)
		{
			niz[i] = niz[i + 1];//OVERLOAD
		}
		trBr--;
	}

	friend ifstream& operator>>(ifstream& f, Sablon<T>& S)
	{
		for (int i = 0; i < S.trBr; i++)
		{
			f >> S.niz[i];
		}
		return f;
	}

	int ukupnaMasa()
	{
		int masa = 0;
		for (int i = 0; i < trBr; i++)
		{
			masa = masa + niz[i];//OVERLOAD
		}
		return masa;
	}
};