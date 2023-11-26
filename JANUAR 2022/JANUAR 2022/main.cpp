#pragma once
#include "Figura.h"
#include "Kolekcija.h"
#include "Kvadrat.h"
#include "Pravougaonik.h"
#include <fstream>

int main()
{
	try
	{
		Kolekcija* niz = new Kolekcija(5);

		Kvadrat* obj1 = new Kvadrat(1, 1, 100);
		Kvadrat* obj2 = new Kvadrat(1, 1, 20);
		Pravougaonik* obj3 = new Pravougaonik(1, 1, 10, 20);

		niz->dodaj(*obj1);
		niz->dodaj(*obj2);
		niz->dodaj(*obj3);

		ofstream f("figure_izlaz.txt");
		niz->prikaziL(f);//IDE U FAJL
		cout << "..................................." << endl;

		niz->povrsinSvihFigura();//IDE NA STANDARD
		cout << "..................................." << endl;

		niz->obimSvihFigura();//IDE NA STANDARD
		cout << "..................................." << endl;

		niz->sortiraj();//NIJE DOBRO ODRADJENA

		niz->prikaziL(f);//IDE U FAJL


		f.close();


		delete niz;
	}
	catch (char* textic)
	{
		cout << textic;
	}
}