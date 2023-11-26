#pragma once
#include "Procesor.h"
#include "Skup.h"

int main()
{
	/////////*INTOVI*///////////
	/////////*PRVI NIZ*/////////
	Skup<int>* niz1 = new Skup<int>(5);

	int* obj1 = new int();
	int* obj2 = new int();
	int* obj3 = new int();
	int* obj4 = new int();

	niz1->dodaj(*obj1);
	niz1->dodaj(*obj2);
	niz1->dodaj(*obj3);
	niz1->dodaj(*obj4);

	cout << "Prvi niz: ";
	cin >> (*niz1);

	//////*DRUGI NIZ*//////////
	Skup<int>* niz2 = new Skup<int>(5);

	int* obj5 = new int();
	int* obj6 = new int();
	int* obj7 = new int();
	int* obj8 = new int();

	niz2->dodaj(*obj5);
	niz2->dodaj(*obj6);
	niz2->dodaj(*obj7);
	niz2->dodaj(*obj8);

	cout << "Drugi niz: ";
	cin >> (*niz2);

	//////*UNIJA////////
	cout << (*(*niz1 + (*niz2)))<<endl;//UNIJA

	cout << (*(*niz1 - (*niz2)))<<endl;//PRESEK

	////////*PROCESORI*///////////////
	/////////*PRVI NIZ*/////////
	//Skup<Procesor>* niz3 = new Skup<Procesor>(5);

	//Procesor* P1 = new Procesor();
	//Procesor* P2 = new Procesor();
	//Procesor* P3 = new Procesor();
	//Procesor* P4 = new Procesor();

	//niz3->dodaj(*P1);
	//niz3->dodaj(*P2);
	//niz3->dodaj(*P3);
	//niz3->dodaj(*P4);

	//cin >> (*niz3);

	///////////*DRUGI NIZ*/////////
	//Skup<Procesor>* niz4 = new Skup<Procesor>(5);

	//Procesor* P5 = new Procesor();
	//Procesor* P6 = new Procesor();
	//Procesor* P7 = new Procesor();
	//Procesor* P8 = new Procesor();

	//niz4->dodaj(*P5);
	//niz4->dodaj(*P6);
	//niz4->dodaj(*P7);
	//niz4->dodaj(*P8);

	//cin >> (*niz4);

	////////*UNIJA////////
	//cout << (*(*niz3 + *niz4));
}