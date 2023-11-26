#pragma once
#include "Sport.h"
#include "Skola.h"

int main()
{
	try
	{
		Skola<Sport>* niz = new Skola<Sport>(5);

		Sport* obj1 = new Sport();
		Sport* obj2 = new Sport();
		Sport* obj3 = new Sport();

		

		ifstream citaj("sport.txt");
		citaj >> (*obj1);
		citaj >> (*obj2);
		citaj >> (*obj3);
		citaj.close();

		niz->dodaj(*obj1);
		niz->dodaj(*obj2);
		niz->dodaj(*obj3);

		ofstream upisi("sport_izlaz.txt");
		upisi << (*niz);
		upisi.close();

		cout << niz->prosek()<<endl;
		cout << niz->najvrednijaAktivnost()<<endl;
		cout << niz->najmanjeVrednaAktivnost();
	}
	catch (const char* textic)
	{
		cout << textic;
	}
}