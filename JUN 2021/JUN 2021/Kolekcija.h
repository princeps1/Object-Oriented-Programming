#pragma once
#include "Banana.h"

template<class T>
class Kolekcija
{
private:
	T* niz;
	int trBr;
	int maxBr;
public:
	Kolekcija(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new T[max];
	}

	~Kolekcija()
	{
		delete[] niz;
	}

	void dodaj(T& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = novi;//OVERLOAD
		}
		else
			throw"NIZ JE PUN";
	}

	float procenat()
	{
		float ukupno = 0;
		for (int i = 0; i < trBr; i++)
		{
			ukupno = ukupno + niz[i];//OVERLOAD
		}
		return ukupno / trBr;
	}

	void obrisi(float odstupanjeProcenat)
	{
		float gGranica = (procenat() + procenat() * odstupanjeProcenat / 100);
		float dGranica =  (procenat() - procenat() * odstupanjeProcenat / 100);
		for (int i = 0; i < trBr; i++)
		{
			if (niz[i]>gGranica || niz[i] < dGranica)
			{
				for (int j = i; j < trBr-1; j++)
				{
					niz[j] = niz[j + 1];
				}
				trBr--;
			}
		}
	}

	friend ostream& operator<<(ostream& out, Kolekcija<T>& K)
	{
		for (int i = 0; i < K.trBr; i++)
		{
			out << K.niz[i]<<"|";
		}
		return out;
	}
};
