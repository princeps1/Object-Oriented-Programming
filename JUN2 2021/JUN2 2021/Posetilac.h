#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
 
class Posetilac
{
protected:
	int brTermina;
	char* ime;
	char* prezime;
	int cena;//OVO JE CENA PO SATU ILI OSNOVNA CENA,ZAVISNO OD TOGA ZA KOJU KLASU TREBA
public:
	Posetilac(int termin,char* ime,char* prezime,int cena)
	{
		brTermina = termin;

		this->ime = new char[strlen(ime) + 1];
		strcpy(this->ime, ime);

		this->prezime = new char[strlen(prezime) + 1];
		strcpy(this->prezime, prezime);

		this->cena = cena;
	}

	Posetilac()
	{
		brTermina = 0;
		ime = new char[10];
		prezime = new char[10];
		cena = 0;
	}

	virtual ~Posetilac()
	{
		delete[] ime;
		delete[] prezime;
	}

	virtual int cenaUlaznice() = 0;
	virtual int koefZainteresovanosti() = 0;

	int getBrTermina()
	{
		return brTermina;
	}

	bool operator==(Posetilac& rhs)
	{
		if (brTermina == rhs.brTermina)
			return true;
		else
			return false;
	}

	bool operator>(Posetilac& rhs)
	{
		if (brTermina > rhs.brTermina)
			return true;
		else
			return false;
	}



	virtual void prikazi(ostream& f)
	{
		f << brTermina << " " << ime << " " << prezime << " ";//BEZ OSNOVNE CENA
	}

	friend bool operator==(int& termin, Posetilac& P)
	{
		if (termin == P.brTermina)
			return true;
		else
			return false;
	}
};
