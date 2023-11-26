#pragma once
#include <iostream>
#include "Skup.h"
#include "Takmicar.h"

using namespace std;

int main()
{
	try
	{
		Skup<int>* niz1 = new Skup<int>(6);

		int* obj1 = new int(5);
		int* obj2 = new int(1);
		int* obj3 = new int(9);
		int* obj4 = new int(5);
		int* obj5 = new int(7);

		niz1->dodaj(*obj1);
		niz1->dodaj(*obj2);
		niz1->dodaj(*obj3);
		niz1->dodaj(*obj4);
		niz1->dodaj(*obj5);

		///////////
		Skup<int>* niz2 = new Skup<int>(5);

		int* obj6 = new int(15);
		int* obj7 = new int(1);
		int* obj8 = new int(6);
		int* obj9 = new int(3);
		int* obj10 = new int(5);

		niz2->dodaj(*obj6);
		niz2->dodaj(*obj7);
		niz2->dodaj(*obj8);
		niz2->dodaj(*obj9);
		niz2->dodaj(*obj10);

		niz2->obrisi(3);

		cout << (*niz1->unija(*niz2));//5 1 9 7 15 6 3
	}
	catch (const char* textic)
	{
		cout << textic;
	}
}