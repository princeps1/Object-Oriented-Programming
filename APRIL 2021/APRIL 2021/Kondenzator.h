#pragma once
#include "Proizvod.h"

class Kondenzator :public Proizvod
{
private:
	int kapacitivnost;
public:
	Kondenzator(char* bar, char* t, int kap)
		:Proizvod(bar, t)
	{
		kapacitivnost = kap;
	}

	~Kondenzator() {}

	bool defektan()
	{
		if (kapacitivnost == 0)
		{
			return true;
		}
		return false;
	}

};