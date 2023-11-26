#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Student
{
protected:
	int index;//BROJ INDEXA
	int bodoviLab;//BROJ BODOVA SA LABOVA
	int bodoviUsmeni;//BROJ BODOVA NA USMENOM
public:
	Student(int ind, int lab, int usmeni)
	{
		index = ind;
		if (lab <= 20 && lab>=0)
		{
			bodoviLab = lab;
		}
		else throw"BROJ POENA SA LABA NEVALIDAN";

		if (usmeni <= 40 && usmeni >= 0)
		{
			bodoviUsmeni = usmeni;
		}
		else
			throw"BROJ POENA SA USMENOG NEVALIDAN";
	}

	virtual int ukupanBrojBodova()
	{
		return bodoviUsmeni + bodoviLab;
	}

	int getIndex()
	{
		return index;
	}

	virtual bool polozio() = 0;
	virtual void setBodovi(int dodatni) = 0;

	virtual void prikazi()
	{
		cout << index << " " << bodoviUsmeni << " " << bodoviLab<<" ";
	}

};