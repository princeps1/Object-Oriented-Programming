#pragma once
#include "Zivotinje.h"
#include <fstream>
using namespace std;

class Roda :public Zivotinje
{
private:
	int visina;
	int rasponKrila;
	int maxBrZaba;
public:
	Roda() :Zivotinje()
	{
		visina = 1;
		rasponKrila = 1;
		maxBrZaba = 1;
	}

	Roda(int m, int v, int raspon, int max)
		:Zivotinje(m)
	{
		if (v > 0 && raspon > 0 && max > 0)
		{
			visina = v;
			rasponKrila = raspon;
			maxBrZaba = max;
		}
		else throw"NEVALIDNE VREDNOSTI";
	}


	bool operator==(Roda& rhs)
	{
		if (masa == rhs.masa &&
			visina == rhs.visina &&
			rasponKrila == rhs.rasponKrila &&
			maxBrZaba==rhs.maxBrZaba)
		{
			return true;
		}
		return false;
	}

	bool operator>(Roda& rhs)
	{
		if (masa == rhs.masa)
		{
			if (visina == rhs.visina)
			{
				if (rasponKrila == rhs.rasponKrila)
				{
					if (maxBrZaba > rhs.maxBrZaba)
					{
						return true;
					}
					else return false;
				}
				else if (rasponKrila > rhs.rasponKrila)
					return true;
				else return false;
			}
			else if (visina > rhs.visina)
				return true;
			else return false;
		}
		else if (masa > rhs.masa)
			return true;
		else return false;
	}

	friend ifstream& operator>>(ifstream& f, Roda& R)
	{
		f >> R.masa >> R.rasponKrila >> R.maxBrZaba >> R.visina;
		return f;
	}
};