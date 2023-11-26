#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Tecni
{
protected:
	char* naziv;
	int masa;

	int dan;
	int mesec;
	int godina;
public:
	Tecni(char* n,int m,int d,int mes,int g)
	{
		naziv = new char[strlen(n) + 1];
		strcpy(naziv, n);

		masa = m;
		dan = d;
		mesec = mes;
		godina = g;
	}

	virtual ~Tecni() 
	{
		delete[] naziv;
	}

	virtual void prikazi()
	{
		cout << naziv << " " << masa << " " << dan << " " << mesec << " " << godina << endl;
	}
};