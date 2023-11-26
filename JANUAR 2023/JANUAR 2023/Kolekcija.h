#pragma once
#include "IzlozbeniPosetioci.h"
#include <fstream>

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
		trBr = 0;
		maxBr = max;
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
			niz[trBr++] = novi;
		}
		else if (trBr == maxBr)
		{
			T* pomNiz = new T[trBr];

			for (int i = 0; i < trBr; i++)
			{
				pomNiz[i] = niz[i];
			}

			delete[] niz;

			maxBr += maxBr / 2;
			niz = new T[maxBr];

			for (int i = 0; i < trBr; i++)
			{
				niz[i] = pomNiz[i];
			}
			niz[++trBr] = novi;
			delete[] pomNiz;
		}
	}

	void obrisi(int X)
	{
		if (X > 0 && X <= trBr)
		{
			for (int i = 0; i < trBr - X; i++)
			{
				niz[i] = niz[i + X];//TREBAO BI DA SE OVERLOADUJE DA IMA ATRIBUT char*
			}
			trBr -= X;
		}
		else
			throw"NEVALIDNA VREDNOST X-a";
	}

	int ukupniBrIzmedjuDvaDana(int rBr1, int rBr2)//REDNI BROJ DANA JE INDEKS+1
	{
		if (rBr1 > 0 && rBr1 < rBr2 && rBr2 <= trBr)
		{
			int ukupno = 0;
			for (int i = rBr1; i < rBr2-1; i++)
			{
				ukupno = ukupno + niz[i];//OVERLOAD+
			}
			return ukupno;
		}
		throw"NEVALIDNE VREDNOSTI";
	}

	//FUNKCIJA dvaNajmanjaDana NIJE DOBAR ALGORITAM ZA PRONALAZENJE,MRZI ME DA RAZMISLJAM
	int* dvaNajmanjaDana()//PRAZNE IH SALJEM IZ main-a
	{
		int imin1 = 0;
		int imin2 = 0;
		for (int i = 1; i < trBr; i++)
		{
			if (niz[imin1] > niz[i])
			{
				imin1 = i;
			}
		}
		
		for (int i = 1; i < trBr; i++)
		{
			if (niz[imin2] > niz[i] && (niz[imin1] != niz[i]))//OVERLOAD != i >
			{
				imin2 = i;
			}
		}

		int* minMin=new int[2];
		minMin[0] = imin1+1;//+1 JER JE imin1 INDEKS A REDNI BROJ JE ZA JEDAN VECI POSTO U NIZU POCINJE OD NULA
		minMin[1] = imin2+1;//+1 JER JE imin1 INDEKS A REDNI BROJ JE ZA JEDAN VECI POSTO U NIZU POCINJE OD NULA

		return minMin;
		
	}

	friend ifstream& operator>>(ifstream& f, Kolekcija<T>& K)
	{
		for (int i = 0; i < K.trBr; i++)
		{
			f >> K.niz[i];
		}
		return f;
	}

	friend ostream& operator<<(ostream& out, Kolekcija<T>& K)
	{
		for (int i = 0; i < K.trBr; i++)
		{
			out << K.niz[i]<<endl;
		}
		return out;
	}

};

