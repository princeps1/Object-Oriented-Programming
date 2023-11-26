#pragma once
#include "Film.h"

template<class T>
class Spisak
{
private:
	T* niz;
	int trBr;
	int maxBr;
	int minOcena;
public:
	Spisak(int max,int minO)
	{
		maxBr = max;
		trBr = 0;
		niz = new T[max];
		minOcena = minO;
	}

	~Spisak()
	{
		delete[] niz;
	}

	void dodaj(T& novi)
	{
		if (trBr < maxBr)
		{
			if (novi > minOcena)//OVERLOAD
			{
				niz[trBr++] = novi;//OVERLOAD
			}
			else
				throw"OCENA FILMA JE MANJA OD MINIMALNE";
		}
		else
			throw"NIZ JE PUN";
	}

	void obrisi(int index)//INDEX NIZA 
	{
		if (index >= 0 && index <= trBr)
		{
			for (int i = index; i < trBr - 1; i++)
			{
				niz[i] = niz[i + 1];
			}
			trBr--;
		}
		else
			throw"NEVALIDAN INDEX";
	}

	void promenaOcene(int index,int novaOcena)//INDEX NIZA 
	{
		if (index >= 0 && index <= trBr)
		{
			niz[index].promeniOcenu(novaOcena);
			if (niz[index] < minOcena)//OVERLOAD
			{
				obrisi(index);
			}
		}
		else
			throw"NEVALIDAN INDEX";
	}

	int brFilmovaSaOcenom(int ocena)
	{
		int ukupno = 0;
		for (int i = 0; i < trBr; i++)
		{
			if (niz[i] == ocena)
			{
				ukupno++;
			}
		}
		return ukupno;
	}

	//minMax
	T* minMax()
	{
		int imin = 0;
		int imax = 0;
		for (int i = 1; i < trBr; i++)
		{
			if (niz[i] > niz[imax])
			{
				imax = i;
			}

			if (niz[imin] > niz[i])
			{
				imin = i;
			}
		}
		T* pomNiz = new T[2];

		pomNiz[0] = niz[imin];
		pomNiz[1] = niz[imax];

		return pomNiz;
	}

	friend ostream& operator<<(ostream& out, Spisak<T>& S)
	{
		for (int i = 0; i < S.trBr; i++)
		{
			out << S.niz[i];
		}
		return out;
	}

	friend istream& operator>>(istream& in, Spisak<T>& S)
	{
		for (int i = 0; i < S.trBr; i++)
		{
			in >> S.niz[i];
		}
		return in;
	}
};