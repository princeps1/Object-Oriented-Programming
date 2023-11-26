#pragma once
#include "Zivotinje.h"
#include <fstream>

class Zaba :public Zivotinje
{
private:
	int gustinaPega;
	int velicinaMuve;
public:
	Zaba() :Zivotinje()
	{
		gustinaPega = 1;
		velicinaMuve = 1;
	}

	Zaba(int m, int gustina, int velicina)
		:Zivotinje(m)
	{
		if (gustina > 0 && velicina > 0)
		{
			gustinaPega = gustina;
			velicinaMuve = velicina;
		}
		else throw"NEVALIDNE VREDNOSTI";
	}

	bool operator==(Zaba& rhs)
	{
		if (masa == rhs.masa &&
			gustinaPega == rhs.gustinaPega &&
			velicinaMuve == rhs.velicinaMuve)
		{
			return true;
		}
		return false;
	}

	bool operator>(Zaba& rhs)
	{
		if (masa == rhs.masa)
		{
			if (gustinaPega == rhs.gustinaPega)
			{
				if (velicinaMuve > rhs.velicinaMuve)
				{
					return true;
				}
				else return false;
			}
			else if (gustinaPega > rhs.gustinaPega)
				return true;
			else return false;
		}
		else if (masa > rhs.masa)
			return true;
		else
			return false;
	}

	friend ifstream& operator>>(ifstream& f, Zaba& Z)
	{
		f >> Z.masa >> Z.gustinaPega >> Z.velicinaMuve;
		return f;
	}
};