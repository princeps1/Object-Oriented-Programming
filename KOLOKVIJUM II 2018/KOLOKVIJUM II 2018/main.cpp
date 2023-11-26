#pragma once
#include "Objekat.h"
#include "ObjekatBasta.h"
#include "Sistem.h"
#include <iostream>

using namespace std;

int main()
{
	Sistem* niz = new Sistem(5);
	Objekat* obj1 = new Objekat(1, 3, 200, 300);
	Objekat* obj2 = new Objekat(2, 5, 200, 500);
	ObjekatBasta* obj3 = new ObjekatBasta(3, 6, 300, 600, 200, 5);

	niz->dodaj(*obj1);
	niz->dodaj(*obj2);
	niz->dodaj(*obj3);

	cout << niz->ukupnaPPrizemlja() << endl;

	niz->obrisi(1);
	cout << niz->ukupnaPPrizemlja() << endl;
	niz->prikaziNiz();


}
