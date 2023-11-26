#pragma once
#include "Sablon.h"
#include "Roda.h"
#include "Zaba.h"
#include "Zivotinje.h"

#include <iostream>
#include<string.h>


using namespace std;

int main()
{
	try
	{
		Sablon<Roda>* niz = new Sablon<Roda>(5);

		Roda* obj1 = new Roda();
		Roda* obj2 = new Roda();
		Roda* obj3 = new Roda();
		Roda* obj4 = new Roda();
		Roda* obj5 = new Roda();

		ifstream f("rode.txt");
		//f >> (*niz);
		f >> (*obj1);
		f >> (*obj2); 
		f >> (*obj3);
		f >> (*obj4); 
		f >> (*obj5);

		f.close();

		niz->dodaj(*obj1);
		niz->dodaj(*obj2);
		niz->dodaj(*obj3);
		niz->dodaj(*obj4);
		niz->dodaj(*obj5);





	}
	catch (const char* text)
	{
		cout << text;
	}
}