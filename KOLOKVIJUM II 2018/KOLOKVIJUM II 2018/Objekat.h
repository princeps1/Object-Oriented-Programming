#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Objekat
{
protected:
	int id;
	int brSpratova;
	int pPrizemlja;//POVRSINA U PRIZEMLJU
	int pSpratova;//POVRSINA NA SPRATOVIMA
public:
	Objekat(int id, int brS, int pP, int pS)
	{
		this->id = id;
		brSpratova = brS;
		pPrizemlja = pP;
		pSpratova = pS;
	}

	int getId()
	{
		return id;
	}

	virtual void promeni(int kod,int vrednost)
	{
		if (kod == 0)
		{
			pPrizemlja = vrednost;
		}
		else if (kod == 1)
		{
			pSpratova = vrednost;
		}
	}

	int getPovrsinuP()
	{
		return pPrizemlja;
	}

	int getPovrsinuS()
	{
		return pSpratova;
	}

	void prikazi()
	{
		cout << id << " " << brSpratova << " " << pPrizemlja << " "
			<< pSpratova << " ";
	}
};