#pragma once
#include "Sport.h"

template<class T>
class Skola
{
private:
	T* niz;
	int trBr;
	int maxBr;
public:
	Skola(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new T[max];
	}

	~Skola()
	{
		delete[] niz;
	}

	void dodaj(T& novi)
	{
		if (trBr == 0)
		{
			niz[trBr++] = novi;//OVERLOAD
		}

		else if (trBr < maxBr)
		{
			int i = 0;
			bool nadjen = false;
			while (i < trBr && !nadjen)//sve dok je nadjen=false je ustvari !nadjen
			{
				if (novi > niz[i])//MORA DA SE PREDEFINISE OPERATOR ">"
				{
					nadjen = true;
				}
				else
				{
					i++;
				}
			}
			if (nadjen == true)//ILI MOZE SAMO if(nadjen)
			{
				for (int j = trBr; j > i; j--)
				{
					niz[j] = niz[j - 1];//TREBA DA SE PREDEFINISE OPERATOR =
				}
				niz[i] = novi;//TREBA DA SE PREDEFINISE OPERATOR "="
				trBr++;
			}
			else
				niz[trBr++] = novi;
		}
		else
			throw"NIZ JE PUUUUUN";
	}

	void obrisi(int brSale)//INDEKS SALE JE brSale-1
	{
		if (brSale <= trBr)
		{
			for (int i = brSale - 1; i < trBr; i++)
			{
				niz[i] = niz[i + 1];
			}
		}
		else
			throw"OVA SALA NE POSTOJI";
	}

	//friend ifstream& operator>>(ifstream& f,Skola<T>& S)
	//{
	//	for (int i = 0; i < S.trBr; i++)
	//	{
	//		f >> S.niz[i];
	//	}
	//	return f;
	//}

	friend ostream& operator<<(ostream& f1, Skola<T>& S)
	{
		for (int i = 0; i < S.trBr; i++)
		{
			f1 << S.niz[i]<<endl;
		}
		return f1;
	}

	float prosek()
	{
		int ukupno = 0;
		for (int i = 0; i < trBr; i++)
		{
			ukupno = ukupno + niz[i];//OVERLOAD
		}
		return (float)ukupno / trBr;
	}

	T& najvrednijaAktivnost()
	{
		return niz[0];
	}

	T& najmanjeVrednaAktivnost()
	{
		return niz[trBr-1];
	}


};