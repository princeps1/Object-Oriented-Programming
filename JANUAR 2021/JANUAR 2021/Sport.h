#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Sport
{
private:
	int brIgraca;//BROJ IGRACA NA TERENU
	int brRezIgraca;//BROJ REZERVNIH IGRACA
	char* obuca;//OBUCA KOJU NOSE
	int budzet;//BUDZET TIMA
	int koefPopularnosti;//KOEFICIJENT POPULARNOSTI
public:
	Sport()
	{
		brIgraca = 0;
		brRezIgraca = 0;
		obuca = new char[30];
		budzet = 0;
		koefPopularnosti = 0;
	}

	~Sport()
	{
		delete[] obuca;
	}

	Sport& operator=(Sport& rhs)
	{
		if (this != &rhs)
		{
			brIgraca = rhs.brIgraca;
			brRezIgraca = rhs.brRezIgraca;

			//delete[] rhs.obuca;
			//obuca = new char[strlen(rhs.obuca) + 1];
			strcpy(obuca, rhs.obuca);
			budzet = rhs.budzet;
			koefPopularnosti = rhs.koefPopularnosti;
		}
		return *this;
	}

	bool operator>(Sport& rhs)
	{
		if (vrednsotSporta() > rhs.vrednsotSporta())
			return true;
		else
			return false;
	}

	int vrednsotSporta()
	{
		int vrednost=(brIgraca + brRezIgraca)* budzet* koefPopularnosti;
		return vrednost;
	}

	friend ifstream& operator>>(ifstream& f,Sport& Sp)
	{
		f >> Sp.brIgraca >> Sp.brRezIgraca >> Sp.obuca >> Sp.budzet >> Sp.koefPopularnosti;

		if (Sp.brIgraca > 20 || Sp.brRezIgraca > 10 || Sp.koefPopularnosti < 0 
			|| Sp.koefPopularnosti>1 || Sp.budzet > 50000)
		{
			throw"NEVALIDNE VREDNOSTI";
		}
		else
			return f;
	}

	friend ostream& operator<<(ostream& f1, Sport& Sp)
	{
		f1 << Sp.brIgraca << " " << Sp.brRezIgraca << " " << Sp.obuca << " " << Sp.budzet << " " << Sp.koefPopularnosti;
		return f1;
	}

	friend int operator+(int& suma,Sport& rhs)
	{
		return suma + rhs.vrednsotSporta();
	}
};