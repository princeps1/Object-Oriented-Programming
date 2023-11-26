#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Vozilo
{
protected:
	char* naziv;//NAZIV VOZILA
	char* tablice;//REGISTARSKA OZNAKA VOZILA
	int maxBrzina;//MAKSIMALNA BRZINA U KM/H
	int potrosnja;//POSTROSNJA GORIVA U LITAR/KILOMETAR
public:
	Vozilo()
	{
		naziv = new char[30];
		tablice = new char[30];
		maxBrzina = 0;
		potrosnja = 0;
	}

	virtual ~Vozilo()
	{
		delete[] naziv;
		delete[] tablice;
	}

	virtual void citaj(ifstream& f)
	{
		f >> naziv >> tablice >> maxBrzina >> potrosnja;
	}

	virtual void upisi(ofstream& f)
	{
		f << naziv << " " << tablice << " " 
		  << maxBrzina << " " << potrosnja << " ";
	}

	int getMaxBrzina()
	{
		return maxBrzina;
	}

	int getPotrosnja()
	{
		return potrosnja;
	}

	virtual bool uporedi(Vozilo& V)=0;	

};