#pragma once
#include "Spisak.h"
#include "Film.h"

int main()
{
	try
	{
		Spisak<Film>* niz = new Spisak<Film>(5, 5);

		Film* obj1 = new Film(12, (char*)"Undisputed", 2012, 7);
		Film* obj2 = new Film(1, (char*)"Never back down", 2006, 9);//TREBA DA ODSTAMPA
		Film* obj3 = new Film(5, (char*)"4. covek", 2000, 10);//TREBA DA ODSTAMPA
		Film* obj4 = new Film(9, (char*)"Purple heart", 2020, 7);//TREBA DA ODSTAMPA

		niz->dodaj(*obj1);
		niz->dodaj(*obj2);
		niz->dodaj(*obj3);
		niz->dodaj(*obj4);

		niz->obrisi(0);

		niz->promenaOcene(2, 6);

		cout<<niz->brFilmovaSaOcenom(10)<<endl;

		cout << (*niz)<<endl;

		Film* minmax = niz->minMax();
		cout << "NAJMANJI I NAJVECI" << endl;
		cout << minmax[0] <<minmax[1];


	}
	catch (const char* textic)
	{
		cout << textic;
	}
}