#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Film
{
private:
	int id;
	char* naziv;//ZASTO JE OVDE PREPORUKA DA SE KORSITI TIP STRING
	int godina;
	int ocena;
public:
	Film(int id, char* naz, int god, int ocen)
	{
		this->id = id;

		naziv = new char[strlen(naz) + 1];
		strcpy(naziv, naz);

		godina = god;
		ocena = ocen;
	}
	Film()
	{
		id = 0;
		naziv = new char[30];
		godina = 0;
		ocena = 0;
	}
	~Film()
	{
		delete[] naziv;
	}

	bool operator>(int minO)
	{
		if (ocena > minO)
			return true;
		else
			return false;
	}

	bool operator>(Film& rhs)
	{
		if (ocena > rhs.ocena)
			return true;
		else
			return false;
	}

	bool operator<(int minO)
	{
		if (ocena < minO)
			return true;
		else
			return false;
	}

	Film& operator=(Film& rhs)
	{
		id = rhs.id;
		naziv = new char[strlen(rhs.naziv) + 1];
		strcpy(naziv, rhs.naziv);
		godina = rhs.godina;
		ocena = rhs.ocena;
		return *this;
	}

	void promeniOcenu(int novaOcena)
	{
		ocena = novaOcena;
	}

	bool operator==(int ocena)
	{
		if (this->ocena == ocena)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& out, Film& F)
	{
		out << F.id << " " << F.naziv << " " << F.godina << " " << F.ocena << endl;
		return out;
	}

	friend istream& operator>>(istream& in, Film& F)
	{
		in >> F.id >> F.naziv >> F.godina >> F.ocena;
		return in;
	}


};