#pragma once
#include "Putnicka.h"
#include "PutnickaIDostavna.h"
#include"Distributer.h"

int main()
{
	Distributer* niz = new Distributer(5);
	Putnicka* obj1 = new Putnicka((char*)"MAtaa", 20, 2.2, 1.1, 12);
	Putnicka* obj2 = new Putnicka((char*)"Jana", 30, 2.2, 1.1, 15);
	PutnickaIDostavna* obj3 = new PutnickaIDostavna((char*)"Gaga", 20, 2.2, 1.1, 12,10,18);

	niz->dodaj(*obj1);
	niz->dodaj(*obj2);
	niz->dodaj(*obj3);

	niz->prikaziL();


	cout<<niz->prosecnaEfik()<<endl;
	cout << niz->ukupanBrProd()<<endl;

	niz->obrisi(1);
	niz->prikaziL();

	delete niz;
}
