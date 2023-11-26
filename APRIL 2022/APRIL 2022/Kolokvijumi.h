#pragma once
#include "Student.h"

class Kolokvijumi :public Student
{
private:
	int bodoviKolokvijum1;//BODOVI SA PRVOG KOLOKVIJUMA
	int bodoviKolokvijum2;//BODOVI ZA DRUGOG KOLOKVIJUMA
public:
	Kolokvijumi(int ind, int lab, int usmeni, int prvi, int drugi)
		:Student(ind, lab, usmeni)
	{
		if (prvi >= 0 && drugi >= 0 &&
			prvi <= 20 && drugi <= 20)
		{
			bodoviKolokvijum1 = prvi;
			bodoviKolokvijum2 = drugi;
		}
		else
			throw"BROJ POENA JEDNOG OD KOLOKVIJUMA NEVALIDAN";
	}

	int ukupanBrojBodova()
	{
		return bodoviKolokvijum1 + bodoviKolokvijum2 + Student::ukupanBrojBodova();
	}

	bool polozio()
	{
		if (bodoviKolokvijum1 > 10 && bodoviKolokvijum2 > 10 
			&& bodoviUsmeni > 20 && ukupanBrojBodova() > 50)
			return true;
		else
			return false;
	}

	void setBodovi(int dodatni)
	{
		bodoviKolokvijum1 += dodatni;
	}


	void prikazi()
	{
		Student::prikazi();
		cout << bodoviKolokvijum1 << " " << bodoviKolokvijum2;
	}
};