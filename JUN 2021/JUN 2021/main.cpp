#pragma once
#include "Automobil.h"
#include "Kamion.h"
#include "Vozilo.h"
#include "VozniPark.h"
#include <iostream>

using namespace std;

int main()
{
	VozniPark* niz1 = new VozniPark(5);
	VozniPark* niz2 = new VozniPark(5);

	Automobil* obj1 = new Automobil();
	Automobil* obj2 = new Automobil();
	Automobil* obj3 = new Automobil();

	Kamion* obj4 = new Kamion();
	Kamion* obj5 = new Kamion();
	Kamion* obj6 = new Kamion();

	niz1->dodaj(*obj1);
	niz1->dodaj(*obj2);
	niz1->dodaj(*obj3);

	niz2->dodaj(*obj4);
	niz2->dodaj(*obj5);
	niz2->dodaj(*obj6);

	ifstream ulaz1("automobil.txt");
	niz1->citajNiz(ulaz1);
	ulaz1.close();


	ifstream ulaz2("kamion.txt");
	niz2->citajNiz(ulaz2);
	ulaz2.close();

	niz1->sortiraj();
	//niz1->upisiNiz(cout);
	ofstream izlaz1("automobil_izlaz.txt");
	niz1->upisiNiz(izlaz1);
	izlaz1.close();

	niz2->sortiraj();
	ofstream izlaz2("kamion_izlaz.txt");
	niz2->upisiNiz(izlaz2);
	izlaz2.close();
}