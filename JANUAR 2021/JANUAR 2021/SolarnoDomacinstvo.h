#pragma once
#include "ObicnoDomacinstvo.h"

class SolarnoDomacinstvo :public ObicnoDomacinstvo
{
private:
	float kolElEn;//KOLICINA ELEKTRICNE ENERGIJE DOBIJENE POMOCU SOLARNIH PANELA
	float koefPodsticaja;
	int cena;//CENA ODRZAVANJA SISTEMA ZA PRAVLJENJE ELEKTRICNE ENERGIJE IZ SOLARNIH PANELA
public:
	SolarnoDomacinstvo(int id, float p, float utr,float kol, float koef, int c)
		:ObicnoDomacinstvo(id,p,utr)
	{
		kolElEn = kol;
		koefPodsticaja = koef;
		cena = c;
	}

	float svotaNovca()
	{
		return(float)ObicnoDomacinstvo::svotaNovca() + cena - kolElEn * 10 * koefPodsticaja;
	}

	void prikazi()
	{
		cout << id << " " << povrsina << " " << utrosenaEn << " "
			<< kolElEn << " " << koefPodsticaja << " " << cena << endl;

	}
};