#pragma once
#include <iostream>

using namespace std;

class Banana
{
private:
	float tezina;
	char* stanje;//DA LI JE ZRELA ILI NE
public:
	Banana()
	{
		tezina = 0;
		stanje = new char[30];
	}

	Banana(float tez, char* st)
	{
		if (strcmp(st, "zrela") == 0)
		{
			tezina = tez;
			stanje = new char[strlen(st) + 1];
			strcpy(stanje, st);
		}
		else if (strcmp(st, "trula") == 0)
		{
			tezina = -1;
			stanje = new char[strlen(st) + 1];
			strcpy(stanje, st);
		}
		else
			throw"STANJE NEVALIDNO";
	}

	~Banana()
	{
		delete[] stanje;
	}

	Banana& operator=(Banana& rhs)
	{
		if (this != &rhs)
		{
			tezina = rhs.tezina;
			delete[] stanje;
			stanje = new char[strlen(rhs.stanje) + 1];
			strcpy(stanje, rhs.stanje);
		}
		return *this;
	}

	friend float operator+(float& ukupno, Banana& rhs)
	{
		return ukupno + rhs.tezina;
	}

	friend ostream& operator<<(ostream& out, Banana& B)
	{
		out << B.tezina << " " << B.stanje ;
		return out;
	}

	bool operator>(float& rhs)
	{
		if (tezina > rhs)
			return true;
		else
			return false;
	}

	bool operator<(float& rhs)
	{
		if (tezina < rhs)
			return true;
		else
			return false;
	}
};