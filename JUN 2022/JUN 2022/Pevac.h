#pragma once
#include "Ucesnik.h"

class Pevac :public Ucesnik
{
private:
	char* pesma;//PESMA KOJU PEVAC PEVA
	int brInstrumentala;//BROJ PRATECIH INSTRUMENTALA
	int brVokala;//BROJ PRATECIH VOKALA
	int poeniMuzickog;//POENI MUZICKOG ZIRIJA
public:
	Pevac(int br, char* ime, char* prez, int publika, char* p, int instrumentali, int vokali, int muzicki)
		:Ucesnik(br, ime, prez, publika)
	{
		if (muzicki > 0 && muzicki < 100)
		{
			pesma = new char[strlen(p) + 1];
			strcpy(pesma, p);

			brInstrumentala = instrumentali;
			brVokala = vokali;
			poeniMuzickog = muzicki;
		}
		else throw"POENI NISU VALIDNI";
	}

	~Pevac()
	{
		delete[] pesma;
	}

	int ukupnoPoena()
	{
		return Ucesnik::ukupnoPoena() + poeniMuzickog;
	}

	bool proso()
	{
		if (poeniMuzickog >= 50 && ukupnoPoena() >= 100)
			return true;
		return false;
	}

	void upisi(ostream& f)
	{
		Ucesnik::upisi(f);
		f << pesma << " " << brInstrumentala << " " 
			<< brVokala <<" "<< poeniMuzickog;
	}

	int brPomocnog()
	{
		return brInstrumentala + brVokala;
	}

	int ukupnoPoenaZirija()
	{
		return poeniMuzickog;
	}


	//OVO NE MOZE JER JE NIZ OBJEKATA TIPA Ucesnik I NIKAD NECE DA PREPOZNA OBJEKAT NIZA KAO PEVAC,NEGO JE SVAKI UCESNIK
	/*friend ostream& operator<<(ostream& out, Pevac P)
	{
		out << P.rBr << ". " << P.ime << " " << P.prezime << " " << P.poeniPublike << " "
			<< P.pesma << " " << P.brInstrumentala << " " << P.brVokala << " " << P.poeniMuzickog << endl;
		return out;
	}*/
};