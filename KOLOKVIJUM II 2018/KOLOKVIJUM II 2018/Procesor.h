#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Procesor
{
private:
	char* naziv;//NAZIV PROCESORA
	int brzina;
	int brJezgara;
	int kolicinaKesa;
public:
	Procesor()
	{
		naziv = new char[30];
		brzina = 0;
		brJezgara = 0;
		kolicinaKesa = 0;
	}

	~Procesor()
	{
		delete[] naziv;
	}

	friend istream& operator>>(istream& in, Procesor& P)
	{
		in >> P.naziv >> P.brzina >> P.brJezgara >> P.kolicinaKesa;
		return in;
	}

	friend ostream& operator<<(ostream& out, Procesor& P)
	{
		out << P.naziv << " " << P.brzina <<
			" " << P.brJezgara << " " << P.kolicinaKesa;
		return out;
	}

	int brutoBrzina()
	{
		return brzina * brJezgara;
	}

	bool operator==(Procesor& rhs)
	{
		if (brutoBrzina() == rhs.brutoBrzina())
			return true;
		else
			return false;
	}


};