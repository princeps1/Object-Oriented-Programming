#pragma once
#include "Posetilac.h"
#include "Sistem.h"
#include "StvarniPosetilac.h"
#include "VirtualniPosetilac.h"

#include <fstream>

int main()
{
	try
	{
		Sistem* niz = new Sistem((char*)"Drakulin Zamak", 7);

		VirtualniPosetilac* obj1 = new VirtualniPosetilac(3, (char*)"Mateja", (char*)"Jovic", 1000, (char*)"princeps1", 2, 9);
		VirtualniPosetilac* obj2 = new VirtualniPosetilac(2, (char*)"Jana", (char*)"Jovic", 1000, (char*)"princeps2", 3, 15);

		StvarniPosetilac* obj3 = new StvarniPosetilac(1, (char*)"Dragana", (char*)"Jovic", 2000, (char*)"princeps3", 20, 500);
		StvarniPosetilac* obj4 = new StvarniPosetilac(5, (char*)"Backo", (char*)"Jovic", 2000, (char*)"princeps4", 50, 500);
		StvarniPosetilac* obj5 = new StvarniPosetilac(4, (char*)"Roki", (char*)"Jovic", 2000, (char*)"princeps5", 70, 500);
		StvarniPosetilac* obj0 = new StvarniPosetilac(4, (char*)"Roki", (char*)"Jovic", 2000, (char*)"princeps5", 70, 500);

		niz->dodaj(obj1);
		niz->dodaj(obj2);
		niz->dodaj(obj3);
		niz->dodaj(obj4);
		niz->dodaj(obj5);

		niz->obrisi(3);
		//niz->dodaj(obj0);//OVDE TREBA DA BACI EXCEPTION

		ofstream f("posete.txt");
		niz->prikaziNiz(f);
		f.close();

		cout << niz->prihodZamka()<<endl;

		/*cout << obj1->koefZainteresovanosti()<<endl;
		cout << obj2->koefZainteresovanosti()<<endl;
		cout << obj3->koefZainteresovanosti() << endl;
		cout << obj4->koefZainteresovanosti() << endl;
		cout << obj5->koefZainteresovanosti() << endl;*/

		//NAJJACI NACIN ZA PRIKAZIVANJE SVIH ELEMENATA IKAD!
		Posetilac* pom = new StvarniPosetilac();
		pom = (&niz->najjaciPosetilac());
		pom->prikazi(cout);

	}
	catch (const char* textic)
	{
		cout << textic;
	}
}