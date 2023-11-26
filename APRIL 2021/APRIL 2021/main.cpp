#pragma once
#include <fstream>
#include <iostream>
#include "Proizvod.h"
#include "Otpornik.h"
#include "Kondenzator.h"
#include "Traka.h"

using namespace std;

int main()
{
	Traka* niz = new Traka(5);
	Kondenzator* obj1 = new Kondenzator((char*)"1", (char*)"Mata", 0);
	Otpornik* obj2 = new Otpornik((char*)"2", (char*)"Jana", 150, 2, 2);
	Otpornik* obj3 = new Otpornik((char*)"3", (char*)"Dragana", 200, 5, 5);
	Otpornik* obj4 = new Otpornik((char*)"3", (char*)"Backo", 200, 5, 5);


	niz->dodaj(*obj1);
	niz->dodaj(*obj2);
	niz->dodaj(*obj3);
	//niz->dodaj(*obj4);
	niz->zamena(*obj4);

	cout<<niz->trBrDefektnih()<<endl;
	cout << niz->trBrPraznih();


	ofstream f("fajl.txt");
	niz->upisiObrisi(f);
	f.close();

	niz->setMaxBr(6);



	//delete niz;

}