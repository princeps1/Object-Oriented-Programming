#pragma once
#include "Ucesnik.h"
#include "Evidencija.h"
#include "Pevac.h"
#include "Glumac.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		Evidencija* niz = new Evidencija(5);

		Glumac* obj1 = new Glumac(1, (char*)"Mateja", (char*)"Jovic", 60, 5, 30, 30);//ZADNJA DVA
		Glumac* obj2 = new Glumac(2, (char*)"Jana", (char*)"Jovic", 60, 5, 50, 40);//ZADNJA DVA
		Pevac* obj3 = new Pevac(3, (char*)"Dragana", (char*)"Jovic", 60, (char*)"Pile", 5, 5, 95);//ZADNJI


		//niz->dodaj(*obj1);
		//niz->dodaj(*obj2);
		//niz->dodaj(*obj3);

		niz->dodaj(obj1);
		niz->dodaj(obj2);
		niz->dodaj(obj3);

		ofstream f("text.txt");
		
		//niz->sortiranje(); NIJE DOBRO SKROZ PROMASENA FUNKCIJA
		niz->sortiraj();
		niz->upisiL(f);
		f << endl;

		f << "Srednja vrednost je: " << niz->srednjaVrednost() << endl ;

		f << "Najjaci takmicar je: " << niz->najjaciUcesnik();

		f.close();

		cout << "Srednja vrednost je: "<<niz->srednjaVrednost() << endl;
			
		cout << "Najjaci takmicar je: " << niz->najjaciUcesnik();


	}
	catch (const char* textic)
	{
		cout << textic;
	}
}