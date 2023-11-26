#pragma once
#include "Banana.h"
#include "Kolekcija.h"

#include <iostream>
using namespace std;

int main()
{
	try
	{
		Kolekcija<float>* niz1 = new Kolekcija<float>(5);

		float* obj1 = new float(100.05);
		float* obj2 = new float(140.8);
		float* obj3 = new float(90);
		float* obj4 = new float(110);
		float* obj5 = new float(76.66);

		niz1->dodaj(*obj1);
		niz1->dodaj(*obj2);
		niz1->dodaj(*obj3);
		niz1->dodaj(*obj4);
		niz1->dodaj(*obj5);

		float procenat;
		cout << "Unesi procenat: "; cin >> procenat;
		niz1->obrisi(procenat);

		cout << (*niz1);

		//////*BANANE*/////////
		Kolekcija<Banana>* niz2 = new Kolekcija<Banana>(5);

		Banana* obj6 = new Banana(100.05, (char*)"zrela");
		Banana* obj7 = new Banana(140.8, (char*)"zrela");
		Banana* obj8 = new Banana(90, (char*)"zrela");
		Banana* obj9 = new Banana(110, (char*)"trula");//TRULA
		Banana* obj10 = new Banana(76.66, (char*)"zrela");

		niz2->dodaj(*obj6);
		niz2->dodaj(*obj7);
		niz2->dodaj(*obj8);
		niz2->dodaj(*obj9);
		niz2->dodaj(*obj10);

		cout << endl;
		niz2->obrisi(procenat);

		cout << (*niz2);//OVDE CE DA IZADJU RAZLICITI OBJEKTI U ODNOSU NA FLOAT NIZ JER JE JEDAN ELEMENT TRUO I ONDA MU VREDNOST PADA NA -1!
	}
	catch (const char* textic)
	{
		cout << textic;
	}
}