//TREBA DA SE NASTAVI OD FUNKCIJE dodajL
#include "Lokomotiva.h"
#include "Vagon.h"
#include<iostream>
#include<string.h>

using namespace std;

class Kompozicija
{
private:
	Lokomotiva** nizLokomotiva;
	int maxBrLokomotiva;
	int trBrLokomotiva;

	Vagon** nizVagona;
	int maxBrVagona;
	int trBrVagona;

public:
	Kompozicija(int maxBrL, int maxBrV)
	{
		nizLokomotiva = new Lokomotiva * [maxBrLokomotiva];
		maxBrLokomotiva = maxBrL;
		trBrLokomotiva = 0;

		nizVagona = new Vagon * [maxBrVagona];
		maxBrVagona = maxBrV;
		trBrVagona = 0;
	}

	~Kompozicija()
	{
		for (int i = 0; i < trBrLokomotiva; i++)
			delete nizLokomotiva[i];
		delete[] nizLokomotiva;
		for (int i = 0; i < trBrVagona; i++)
			delete nizVagona[i];
		delete[] nizVagona;
	}


};