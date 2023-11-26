#pragma once 
#include "Ucesnik.h"

class Glumac :public Ucesnik
{
private:
	int brRekvizita; //BROJ POTREBNIH REKVIZITA
	int poeniIdejuZ;//BROJ POENA ZIRIJA ZA IDEJU
	int poeniIzvodjenjeZ;//BROJ POENA ZIRIJA ZA IZVODJENJE

public:
	Glumac(int br, char* ime, char* prez, int publika, int rekviziti, int ideja, int izvodjenje)
		:Ucesnik(br, ime, prez, publika)
	{
		if (ideja > 0 && ideja <= 50 &&
			izvodjenje>0 && izvodjenje <= 50)
		{
			brRekvizita = rekviziti;
			poeniIdejuZ = ideja;
			poeniIzvodjenjeZ = izvodjenje;
		}
		else
			throw"POENI NISU VALIDNI";
	}

	~Glumac() {};

	int ukupnoPoena()
	{
		return Ucesnik::ukupnoPoena() + poeniIdejuZ + poeniIzvodjenjeZ;
	}

	bool proso()
	{
		if (poeniIdejuZ >= 25 && poeniIzvodjenjeZ >= 25 && ukupnoPoena()>=100)
		{
			return true;
		}
		return false;
	}

	void upisi(ostream& f)
	{
		Ucesnik::upisi(f);
		f << brRekvizita << " " << poeniIdejuZ << " " << poeniIzvodjenjeZ;
	}

	int brPomocnog()
	{
		return brRekvizita / 2;
	}

	int ukupnoPoenaZirija()
	{
		return poeniIdejuZ + poeniIzvodjenjeZ;
	}

	//OVO NE MOZE JER JE NIZ OBJEKATA TIPA Ucesnik I NIKAD NECE DA PREPOZNA OBJEKAT NIZA KAO GLUMAC,NEGO JE SVAKI UCESNIK
	/*friend ostream& operator<<(ostream& out, Glumac G)
	{
		out << G.rBr << ". " << G.ime << " " << G.prezime << " " << G.poeniPublike << " " 
			<< G.brRekvizita << " " << G.poeniIdejuZ << " " << G.poeniIzvodjenjeZ<<endl;

	}*/

};