#pragma once
#include "Student.h"

class PisaniIspit :public Student
{
private:
	int bodoviPisani;//BODOVI OSVOJENI NA PISANOM DELU ISPITA
public:
	PisaniIspit(int ind, int lab, int usmeni, int pisani)
		:Student(ind, lab, usmeni)
	{
		if (pisani >= 0 && pisani <= 40)
		{
			bodoviPisani = pisani;
		}
		else throw"BROJ POENA SA PISANOG DELA NEVALIDAN";
	}

	int ukupanBrojBodova()
	{
		return bodoviPisani + Student::ukupanBrojBodova();
	}

	bool polozio()
	{
		if (bodoviPisani > 20 && bodoviUsmeni > 20 && ukupanBrojBodova() > 50)
			return true;
		else
			return false;
	}

	void setBodovi(int dodatni)
	{
		bodoviPisani += dodatni;
	}

	void prikazi()
	{
		Student::prikazi();
		cout << bodoviPisani;
	}
};