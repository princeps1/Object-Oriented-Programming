#pragma once
#include "KK.h"
#include <iostream>
#include<fstream>

using namespace std;

template <class T>
class Sale
{
private:
	T* niz;
	int maxBr;
	int trBr;
public:
	Sale(int max)
	{
		maxBr = max;
		trBr = 0;
		niz = new T[max];
	}

	~Sale()
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
			while (i < trBr && nadjen == false)
			{
				if (novi > niz[i])//OVERLOAD
				{
					nadjen = true;

					for (int j = trBr; j > i; j--)
					{
						niz[j] = niz[j - 1];//OVERLOAD
					}
					trBr++;
					niz[i] = novi;//OVERLAOD
				}
				else
				{
					i++;
				}
			}
		}
		else throw"NIZ JE PUN";
	}

	void obrisi(int index)
	{
		if (index >= 0 && index < trBr)
		{
			for (int i = index; i < trBr - 1; i++)
			{
				niz[i] = niz[i + 1];//OVERLOAD
			}
			trBr--;
		}
		else throw"INDEX NE POSTOJI !!!";
	}

	float prosecnaVrednost()
	{
		float ukupno = 0;
		for (int i = 0; i < trBr; i++)
		{
			ukupno = ukupno + niz[i];
		}
		return (float)ukupno / trBr;
	}

	T& najvredniji()
	{
		imax = 0;
		for (int i = 1; i < trBr; i++)
		{
			if (niz[i] > niz[imax])//OVERLOAD
			{
				imax = i;
			}
		}
		return niz[imax];
	}

	T& najmanjeVredan()
	{
		imin = 0;
		for (int i = 1; i < trBr; i++)
		{
			if (niz[imin]>niz[i])//OVERLOAD
			{
				imin = i;
			}
		}
		return niz[imin];
	}



};
