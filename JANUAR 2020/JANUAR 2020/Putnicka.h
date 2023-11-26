#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Putnicka
{
protected:
	char* naziv;
	int brZaposlenih;
	float x;
	float y;
	int brProdPutnickih;
public:
	Putnicka(char* n, int br, float x, float y, int brProdP)
	{
		naziv = new char[strlen(n) + 1];
		strcpy(naziv, n);
		brZaposlenih = br;
		this->x = x;
		this->y = y;
		brProdPutnickih = brProdP;
	}

	virtual ~Putnicka()
	{
		delete[]naziv;
	}

	virtual float efikProdaje()
	{
		return (float)brProdPutnickih / brZaposlenih;
	}

	virtual float efikRada()
	{
		return efikProdaje();
	}

	virtual void setBrProd(int uvecaj)
	{
		brProdPutnickih += uvecaj;
	}

	virtual void prikazi()
	{
		cout << naziv << " " << brZaposlenih << " " << x << " " << y << " " 
			<< brProdPutnickih << " ";
	}

	int getBrZap()
	{
		return brZaposlenih;
	}

	virtual int getBrProd()
	{
		return brProdPutnickih;
	}
};