#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

class KK
{
private:
	char* bojaDresa;
	char* listaSponzora;
	int budzet;//BUDZET TIMA
	int brKarata;//BROJ SEZONSKIH KARATA
public:
	KK()
	{
		budzet = 0;
		brKarata = 0;
		bojaDresa = new char[30];
		listaSponzora = new char[50];
	}

	KK(char* boja, char* lista, int budz, int karta)
	{
		if (lista != NULL && budz >= 50000)
		{
			bojaDresa = new char[strlen(boja) + 1];
			strcpy(bojaDresa, boja);

			listaSponzora = new char[strlen(lista) + 1];
			strcpy(listaSponzora, lista);

			budzet = budz;
			brKarata = karta;
		}
		else throw"Nisu ispunjeni uslovi!";
	}

	~KK()
	{
		delete[] listaSponzora;
		delete[] bojaDresa;
	}

	float vrednostKluba()
	{
		return budzet + brKarata * 500;//CENA JE 500DIN,MISLIM DA NE MOZE DA SE POSALJE
	}

	KK& operator=(KK& rhs)
	{
		if (this != &rhs)
		{
			budzet = rhs.budzet;
			brKarata = rhs.brKarata;

			delete[] bojaDresa;
			bojaDresa = new char[strlen(rhs.bojaDresa) + 1];
			strcpy(bojaDresa, rhs.bojaDresa);

			delete[] listaSponzora;
			listaSponzora = new char[strlen(rhs.listaSponzora)];
			strcpy(listaSponzora, rhs.listaSponzora);
		}
		else throw"Ovo je isti objekat";
		return *this;
	}

	bool operator>(KK& rhs)
	{
		if (this->vrednostKluba() > rhs.vrednostKluba())
		{
			return true;
		}
		else
			return false;
	}

	friend int operator+(int& ukupno, KK& rhs)
	{
		return ukupno + rhs.vrednostKluba();
	}

	

};