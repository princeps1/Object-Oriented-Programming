#pragma once
#include "Student.h"
#include "PisaniIspit.h"
#include "Kolokvijumi.h"
#include "Evidencija.h"

using namespace std;

int main()
{
	try
	{
		Evidencija* niz = new Evidencija(5);
		PisaniIspit* obj1 = new PisaniIspit(18700, 15, 35, 35);
		PisaniIspit* obj2 = new PisaniIspit(18701, 20, 25, 19);//PAO PISMENI
		PisaniIspit* obj3 = new PisaniIspit(18705, 10, 15, 35);//PAO USMENI

		Kolokvijumi* obj4 = new Kolokvijumi(18702, 11, 25, 15, 15);

		niz->dodaj(*obj1);
		niz->dodaj(*obj2);
		niz->dodaj(*obj3);
		niz->dodaj(*obj4);

		niz->prikaziL();
		cout<<niz->brStudenataPolozili()<<endl;

		cout << "..........................................." << endl;

		niz->obrisi(18700);
		niz->izmeniBodove(18701, 5);//IMCE SAD 24 I ONDA JE POROSO I ON

		niz->prikaziL();
		cout<<niz->brStudenataPolozili()<<endl;
		
		cout << "..........................................." << endl;

		niz->dodaj(*obj1);
		niz->prikaziL();
		cout<<niz->prosek();

	}
	catch (const char* textic)
	{
		cout << textic;
	}
}