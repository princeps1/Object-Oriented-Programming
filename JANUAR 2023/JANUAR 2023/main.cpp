#pragma once
#include "Dan.h"
#include "DanNoc.h"
#include <iostream>
#include "Preduzece.h"

int main()
{
	try
	{
		Preduzece* niz = new Preduzece(5);
		Dan* obj1 = new Dan(1, 5, 10, 1000, 25);
		Dan* obj2 = new Dan(2, 8, 9, 2000, 20);
		DanNoc* obj3 = new DanNoc(3, 5, 10, 1000, 25, 2000, 10);

		niz->dodaj(*obj1);
		niz->dodaj(*obj2);
		niz->dodaj(*obj3);

		ofstream f("proba.txt");
		niz->Upisifajl(f);
		f.close();

		niz->obrisi(1);
		cout<<niz->zarada()<<endl;
		niz->produzi(2,57);
		niz->prikaziNiz();
	}
	catch (char* text)
	{
		cout << text;
	}

}