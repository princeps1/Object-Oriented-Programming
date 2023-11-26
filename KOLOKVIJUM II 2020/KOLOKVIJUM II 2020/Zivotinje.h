#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Zivotinje
{
protected:
	int masa;
public:
	Zivotinje()
	{
		masa = 1;
	}

	Zivotinje(int m)
	{
		if (m > 0)
		{
			masa = m;
		}
		else throw"NEVALIDNE VREDNOSTI";
	}

	friend int operator+(int masa, Zivotinje& rhs)
	{
		return masa + rhs.masa;
	}
};