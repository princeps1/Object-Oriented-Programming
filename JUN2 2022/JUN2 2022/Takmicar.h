#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Takmicar
{
private:
	//TAKMICAR JE ISTI AKO IMA ISTI IDENTIFIKATOR
	int id;
	int startniBroj;
	int rezultat;
public:
	Takmicar()
	{
		id = 0;
		startniBroj = 0;
		rezultat = 0;
	}

	Takmicar(int id, int broj, int rez)
	{
		this->id = id;
		startniBroj = broj;
		rezultat = rez;
	}

	friend bool operator==(Takmicar& T,int& id)//KAD JE FRIEND MORA DA IMA DVA PARAMETRA
	{
		if (T.id == id)
		{
			return true;
		}
		else
			return false;
	}
};