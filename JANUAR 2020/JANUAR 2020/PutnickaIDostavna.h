#pragma once
#include "Putnicka.h"

class PutnickaIDostavna :public Putnicka
{
private:
	int brZapUDostavna;//BROJ ZAPOSLENIH U DELU ZA DOSTAVNA VOZILA
	int brProdDostavnih;
public:
	PutnickaIDostavna(char* n, int br, float x, float y, int brProdP, int brZap, int brProdD)
		:Putnicka(n, br, x, y, brProdP)
	{
		brZapUDostavna = brZap;
		brProdDostavnih = brProdD;
	}

	~PutnickaIDostavna(){}

	float efikProdaje()
	{
		return (float)brProdDostavnih / brZapUDostavna;
	}

	float efikRada()
	{
		return (Putnicka::efikProdaje() + PutnickaIDostavna::efikProdaje()) / 2;
	}

	void setBrProd(int uvecaj)
	{
		brProdDostavnih += uvecaj;
	}

	void prikazi()
	{
		Putnicka::prikazi();
		cout << brZapUDostavna << " " << brProdDostavnih;
	}

	int getBrProd()
	{
		return brProdPutnickih+ brProdDostavnih;
	}
};