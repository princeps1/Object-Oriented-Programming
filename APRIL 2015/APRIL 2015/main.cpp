#pragma once
#include "Sistem.h"
#include "Vanredni.h"
#include "Redovni.h"

using namespace std;

int main()
{
	Sistem* niz = new Sistem(100);

	Redovni* obj1 = new Redovni((char*)"Pk", (char*)"Nis", (char*)"2002-05-06 15:12:01", 50, 10);
	Redovni* obj2 = new Redovni((char*)"Nis", (char*)"Bg", (char*)"2004-06-26 17:12:01", 50, 10);
	Vanredni* obj3 = new Vanredni((char*)"Bg", (char*)"Novi Sad", (char*)"2002-02-10 18:12:01", 50, 10, 20);

	niz->dodaj(*obj1);
	niz->dodaj(*obj2);
	niz->dodaj(*obj3);

	//niz->obrisi((char*)"Pk", (char*)"Nis", (char*)"2002-05-06 15:12:01");

	niz->rezervisi((char*)"Pk", (char*)"Nis", (char*)"2002-05-06 15:12:01");
	niz->rezervisi((char*)"Pk", (char*)"Nis", (char*)"2002-05-06 15:12:01");
	niz->rezervisi((char*)"Pk", (char*)"Nis", (char*)"2002-05-06 15:12:01");
	niz->rezervisi((char*)"Pk", (char*)"Nis", (char*)"2002-05-06 15:12:01");

	niz->prikazi();
	cout << endl << endl;

	niz->obrisi((char*)"Pk", (char*)"Nis", (char*)"2002-05-06 15:12:01");
	niz->prikazi();
}