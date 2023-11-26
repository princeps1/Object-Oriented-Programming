#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Ucesnik
{
protected:
	int rBr;
	char* ime;
	char* prezime;
	int poeniPublike;
public:
	Ucesnik(int br, char* ime, char* prez, int publika)
	{
		if (publika > 0 && publika < 100)
		{
			rBr = br;

			this->ime = new char[strlen(ime) + 1];
			strcpy(this->ime, ime);

			prezime = new char[strlen(prez) + 1];
			strcpy(prezime, prez);

			poeniPublike = publika;
		}
		else throw"POENI NISU VALIDNI";
	}

	virtual ~Ucesnik()
	{
		delete[] ime;
		delete[] prezime;
	}

	virtual int ukupnoPoena()
	{
		return poeniPublike;
	}

	virtual bool proso() = 0;

	virtual void upisi(ostream& f)
	{
		f << rBr << ". " << ime << " " << prezime << " " << poeniPublike << " ";
	}

	virtual int brPomocnog() = 0;
	virtual int ukupnoPoenaZirija() = 0;

	friend ostream& operator<<(ostream& out, Ucesnik& U)
	{
		out << U.rBr << ". " << U.ime << " " << U.prezime << endl;
		return out;
	}
};