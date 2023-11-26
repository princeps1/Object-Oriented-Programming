#pragma once
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class IzlozbeniPosetioci
{
private:
	int brOdraslih;//BROJ ODRASLIH POSETIOCA
	int brSkolske;//BROJ SKOLESKE DECE
	int brDo7;//BROJ DECE DO 7 GODINA U JEDNOM DANU
public:
	IzlozbeniPosetioci()
	{
		brOdraslih = 0;
		brSkolske = 0;
		brDo7 = 0;
	}

	IzlozbeniPosetioci(int odrasli,int skolske,int do7)
	{
		brOdraslih = odrasli;
		brSkolske = skolske;
		brDo7 = do7;
	}

	int ukupanBr()
	{
		return brOdraslih + brSkolske + brDo7;
	}

	friend int operator+(int ukupno, IzlozbeniPosetioci& rhs)
	{
		return ukupno + rhs.ukupanBr();
	}

	int zarada()
	{
		return brSkolske * (500 / 2) + brOdraslih * 500;//500 JE CENA KARTE!!!
	}

	bool operator>(IzlozbeniPosetioci& rhs)
	{
		if (zarada() > rhs.zarada())
			return true;
		else 
			return false;
	}

	friend ifstream& operator>>(ifstream& f, IzlozbeniPosetioci& I)
	{
		f >> I.brOdraslih >> I.brSkolske >> I.brDo7;
		return f;
	}

	friend ostream& operator<<(ostream& out, IzlozbeniPosetioci& I)
	{
		out << I.brOdraslih << " " << I.brSkolske << " " << I.brDo7;
		return out;
	}

	bool operator!=(IzlozbeniPosetioci& rhs)
	{
		if (brOdraslih != rhs.brOdraslih ||
			brSkolske != rhs.brSkolske ||
			brDo7 != rhs.brDo7)
		{
			return true;
		}
		else
			return false;
	}


};
