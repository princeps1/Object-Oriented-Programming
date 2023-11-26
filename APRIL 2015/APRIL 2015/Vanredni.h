#pragma once
#include "Redovni.h"

class Vanredni :public Redovni
{
private:
	int brMestaVanredni;
public:
	Vanredni(char* pol, char* dol, char* dat, int brM, int brRez, int brMVanr)
		:Redovni(pol, dol, dat, brM, brRez)
	{
		brMestaVanredni = brMVanr;

	}

	~Vanredni() {}

	virtual void setBrRezMesta()
	{
		if (brRezMesta < brMestaVanredni)
		{
			brRezMesta++;
		}
		else
			cout << "Mesta su popunjena";
	}

	void prikaziL()
	{
		cout << polD << " " << dolD << " " << datIVreme << " "
			<< brMesta << " " << brRezMesta << " " << brMestaVanredni << endl;
	}


};