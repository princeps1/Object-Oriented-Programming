#pragma once
#include <iostream>
#include <string.h>
#include "Takmicar.h"
//TEMPLEJT KLASA

template<class T>
class Lista
{
private:
	T* niz;
	int trBr;
	int maxBr;
public:
	Lista(int max)
	{
		trBr = 0;
		maxBr = max;
		niz = new Lista[max];
	}

	~Lista()
	{
		delete[] niz;
	}

	void dodaj(T& novi)
	{
		if (trBr < maxBr)
		{
			niz[trBr++] = novi;
		}
		else
			throw"NIZ JE PUN";
	}

	void obrisi(int id)
	{
		int i = 0;
		bool nadjen = false;
		while (i < trBr && nadjen == false)
		{
			if (id == niz[i])//OVERLOAD
			{
				nadjen == true;
			}
			else i++;
		}
		if (nadjen == true)
		{
			for (int j = i; j < trBr; j++)
			{
				niz[j] = niz[j + 1];//OVERLOAD
			}
			trBr--;
		}
	}



};
