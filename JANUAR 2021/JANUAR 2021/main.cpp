#pragma once
#include "Sistem.h"
#include "SolarnoDomacinstvo.h"
#include "ObicnoDomacinstvo.h"

int main()
{
	Sistem* niz = new Sistem(5);
	ObicnoDomacinstvo* obj1 = new ObicnoDomacinstvo(1, 100, 200);
	SolarnoDomacinstvo* obj2 = new SolarnoDomacinstvo(2, 150, 250, 300, 3, 2000);
	ObicnoDomacinstvo* obj3 = new ObicnoDomacinstvo(3, 500, 800);
	SolarnoDomacinstvo* obj4 = new SolarnoDomacinstvo(4, 150, 850, 652, 4, 200000);


	niz->dodaj(*obj1);
	niz->dodaj(*obj2);
	niz->dodaj(*obj3);
	niz->dodaj(*obj4);

	niz->prosecnaPotrosnjaElEn();
	niz->obrisi(1);
	niz->prikaziNiz();

}

