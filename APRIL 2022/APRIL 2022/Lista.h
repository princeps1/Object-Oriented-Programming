#pragma once
#include "Takmicar.h"
#include <iostream>

using namespace std;

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
		maxBr = max;
		trBr = 0;
		niz = new T[max];
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
		//bool nadjen = false;
		int i = 0;
		while (i < trBr)
		{
			if (niz[i] == id)//OVERLOAD
			{
				for (int j = i; j < trBr - 1; j++)
				{
					niz[j] = niz[j + 1];//OEVRLOAD
				}
				trBr--;
			}
			else
				i++;
		}
	}
	Lista<T>* spoji(Lista<T>& l2)
	{
		//TRAZENJE maxBr ZA NOVU LISTU I ALOCIRANJE MEMORIJE ZA NOVU LISTU 
		int maxBrListe3 = 0;
		if (this->trBr > l2.trBr)
		{
			maxBrListe3 += 2 * l2.trBr + (this->trBr - l2.trBr) * 2+1;
		}
		else if (l2.trBr > this->trBr)
		{
			maxBrListe3 += 2 * this->trBr + (l2.trBr - this->trBr) * 2+1;
		}
		else
			maxBrListe3 += this->trBr + l2.trBr;

		Lista<T>* lista3 = new Lista<T>(maxBrListe3);
		//

		bool kraj1 = false;
		bool kraj2 = false;
		int i = 0;
		int j = 0;

		while (i < lista3->maxBr && kraj1 == false && kraj2 == false)
		{
			if (lista3->trBr % 2 == 0)//&& kraj1==false)
			{
				lista3->niz[lista3->trBr] = this->niz[i];
				i++;
				if (i == this->trBr)
					kraj1 = true;
			}

			if (lista3->trBr % 2 == 1)//&& kraj2 == false)
			{
				lista3->niz[lista3->trBr] = l2.niz[j];
				j++;
				if (i == l2.trBr)
					kraj2 = true;
			}
			lista3->trBr++;
		}
		if (kraj1 == true)
		{
			for (j; j < l2.trBr; j++)
			{
				lista3->niz[lista3->trBr++] = l2.niz[j];
				lista3->niz[lista3->trBr++] = l2.niz[j];
			}
		}

		if (kraj2 == true)
		{
			for (i; i < this->trBr; i++)
			{
				lista3->niz[lista3->trBr++] = this->niz[j];
				lista3->niz[lista3->trBr++] = this->niz[j];
			}
		}
		return lista3;
	}

	friend ostream& operator<<(ostream& out, Lista<T> L)
	{
		for (int i = 0; i < L.trBr; i++)
		{
			out << L.niz[i];
		}
		return out;
	}
};