#pragma once
#include "Lista.h"
#include "Takmicar.h"
#include <iostream>

using namespace std;

int main()
{
	try
	{
		Lista<int>* niz1 = new Lista<int>(5);

		int* obj1 = new int(1);
		int* obj2 = new int(2);
		int* obj3 = new int(3);

		niz1->dodaj(*obj1);
		niz1->dodaj(*obj2);
		niz1->dodaj(*obj3);


		Lista<int>* niz2 = new Lista<int>(5);

		int* obj4 = new int(9);
		int* obj5 = new int(8);
		int* obj6 = new int(4);
		int* obj7 = new int(3);

		niz2->dodaj(*obj4);
		niz2->dodaj(*obj5);
		niz2->dodaj(*obj6);
		niz2->dodaj(*obj7);

		cout << (*niz1->spoji(*niz2));
	}
	catch (const char* textic)
	{
		cout << textic;
	}
}