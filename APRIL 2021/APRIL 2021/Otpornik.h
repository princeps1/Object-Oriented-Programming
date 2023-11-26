#pragma once
#include "Proizvod.h"

class Otpornik :public Proizvod
{
private:
	int otpornost;
	int minOpTemp;
	int maxOpTemp;
public:
	Otpornik(char* bar, char* t, int otp, int min,int max)
		:Proizvod(bar, t)
	{
		otpornost = otp;
		minOpTemp = min;
		maxOpTemp = max;
	}

	~Otpornik() {}

	bool defektan()
	{
		if (otpornost == INT_MAX || otpornost == 0)
		{
			return true;//DEFEKTAN JE
		}
		return false;
	}

};