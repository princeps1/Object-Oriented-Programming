#pragma once

#include "Praskasti.h"
#include "Skladiste.h"
#include "Tecni.h"
#include <iostream>
using namespace std;

int main()
{
	Skladiste* niz = new Skladiste((char*)"Mataa", 5);
	Praskasti* obj2 = new Praskasti((char*)"Praskasti", 1500, 6, 5, 2002, 53);
	Tecni* obj1 = new Tecni((char*)"Tecni", 1000, 26,6,2004);

	obj2->rokTrajanja();
	niz->dodaj(*obj1);
	niz->dodaj(*obj2);

	niz->prikaziNiz();
}