#pragma once
#include "Tecni.h"

class Praskasti:public Tecni
{
private:
	int ShelfLife;
public:
	Praskasti(char* n, int m, int d, int mes, int g,int she)
		:Tecni(n, m, d, mes, g)
	{
		ShelfLife = she;
	}

	~Praskasti(){}

	void rokTrajanja()
	{
		if (ShelfLife > 31 && ShelfLife<365)
		{
			int m = ShelfLife / 31;
			int d = ShelfLife % 31;
			if (mesec + m <= 12)
			{
				mesec += m;
			}
			else
			{
				godina++;
				if (m < mesec)
					m -= mesec;
				else
				{
					m = mesec - m;

				}
				mesec += m;
			}

			dan += d;
		}

		else if (ShelfLife > 365)
		{
			int g = ShelfLife / 365;
			int dan = ShelfLife % 365;

			godina += g;

			int m = dan / 31;
			int d = dan % 31;
			if (mesec + m <= 12)
			{
				mesec += m;
			}
			else
			{
				godina++;
				if (m < mesec)
					m -= mesec;
				else
				{
					m = mesec - m;

				}
				mesec += m;
			}

			dan += d;
		}
	}

	void prikazi()
	{
		cout << naziv << " " << masa << " " << dan << " "
		<< mesec << " " << godina << " " << ShelfLife << endl;

	}
};