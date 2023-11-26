#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Redovni
{
protected:
	char* polD;
	char* dolD;
	char* datIVreme;
	int brMesta;//BROJ MESTA REDOVNOG LETA
	int brRezMesta;
public:
	Redovni(char* pol, char* dol, char* dat, int brM, int brRez)
	{
		polD = new char[strlen(pol) + 1];
		strcpy(polD, pol);

		dolD = new char[strlen(dol) + 1];
		strcpy(dolD, dol);

		datIVreme = new char[strlen(dat) + 1];
		strcpy(datIVreme, dat);

		brMesta = brM;
		brRezMesta = brRez;
	}

	virtual ~Redovni()
	{
		delete[] polD;
		delete[] dolD;
		delete[] datIVreme;
	}

	virtual void setBrRezMesta()
	{
		if (brRezMesta < brMesta)
		{
			brRezMesta++;
		}
		else
			cout << "Mesta su popunjena";
	}

	virtual void prikaziL()
	{
		cout << polD << " " << dolD << " " << datIVreme << " "
			<< brMesta << " " << brRezMesta << " ";
	}

	char* getPolD()
	{
		return polD;
	}

	char* getDolD()
	{
		return dolD;
	}

	char* getDatIVreme()
	{
		return datIVreme;
	}
};