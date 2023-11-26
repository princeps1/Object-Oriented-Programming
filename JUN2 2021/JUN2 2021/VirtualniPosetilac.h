#pragma once
#include "Posetilac.h"

class VirtualniPosetilac:public Posetilac
{
private:
	char* korisnickoIme;//KORISNICKO IME PRIJAVE
	int brSati;//BROJ SATI ZA KOJE SE VIRTUALNI POSETILAC PRIJAVIO
	int brKomentara;//BROJ KOMENTARA POSTAVLJENIH NA PLATFORMI ZAMKA
	//OVDE JE ATRIBUT CENA USTVARI CENA PO SATU
public:
	VirtualniPosetilac(int termin, char* ime, char* prezime, int cena, char* korisnicko, int sati, int komentari)
		:Posetilac(termin, ime, prezime, cena)
	{
		korisnickoIme = new char[strlen(korisnicko) + 1];
		strcpy(korisnickoIme, korisnicko);

		brSati = sati;
		brKomentara = komentari;
	}

	VirtualniPosetilac()
	{
		korisnickoIme = new char[30];
		brSati = 0;
		brKomentara = 0;
	}

	~VirtualniPosetilac()
	{
		delete[] korisnickoIme;
	}

	int cenaUlaznice()
	{
		return cena * brSati;
	}

	int koefZainteresovanosti()
	{
		return brSati * brKomentara;
	}


	void prikazi(ostream& f)
	{
		Posetilac::prikazi(f);
		f << korisnickoIme << " " << brSati << " " << brKomentara;
	}


};