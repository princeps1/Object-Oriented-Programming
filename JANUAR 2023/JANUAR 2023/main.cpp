#pragma once
#include "Kolekcija.h"
#include "IzlozbeniPosetioci.h"

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	try
	{
		
		Kolekcija<IzlozbeniPosetioci>* niz = new Kolekcija<IzlozbeniPosetioci>(5);
		IzlozbeniPosetioci* obj1=new IzlozbeniPosetioci();
		IzlozbeniPosetioci* obj2=new IzlozbeniPosetioci();
		IzlozbeniPosetioci* obj3=new IzlozbeniPosetioci();

		ifstream f("text.txt");
		f >> (*obj1);
		f >> (*obj2);
		f >> (*obj3);
		f.close();



		niz->dodaj(*obj1);
		niz->dodaj(*obj2);
		niz->dodaj(*obj3);


		//niz->obrisi(1);
		//int min1, min2; 
		//niz->dvaNajmanjaDana(min1, min2);OVA NIJE DOBRA
		//cout << min1 << " " << min2;


		//cout<<niz->ukupniBrIzmedjuDvaDana(1, 3);

		ofstream f2("text2.txt");
		f2 << (*niz);
		f2.close();


		cout << (*niz);



		//DRUGI NIZ !!
		Kolekcija<int>* niz2 = new Kolekcija<int>(5);
		int* obj4 = new int();
		int* obj5 = new int();
		int* obj6 = new int();

		ifstream fajl1("intovi1.txt");
		fajl1 >> (*obj4);
		fajl1 >> (*obj5);
		fajl1 >> (*obj6);
		fajl1.close();

		niz2->dodaj(*obj4);
		niz2->dodaj(*obj5);
		niz2->dodaj(*obj6);

		cout << (*niz2);

		//niz2->obrisi(1);
		//cout << niz2->ukupniBrIzmedjuDvaDana(1,3);

		ofstream fajl2("intovi2.txt");
		fajl2 << (*niz2);
		//fajl2 << niz2->ukupniBrIzmedjuDvaDana(1, 3);
		fajl2.close();

		cout << (*niz);

		cout << "---------------------------------"<<endl;

		int* minMin = niz2->dvaNajmanjaDana();
		cout << minMin[0]<<" " <<minMin[1];

	}
	catch (const char* text)
	{
		cout << text;
	}
}