#include <iostream>
#include <string.h>

using namespace std;

class Vagon
{
protected://MORAJU DA BUDU PROTECTED ZA NASLEDJIVANJE
	int netoMasa;//NETO MASA VAGONA U TONAMA
	int maxKapPon;//MAKSIMALNI KAPACITET KOJI MOZE VAGON DA PONESE
	int trPop;//TRENUTNA POPUNJENOST VAGONA
public:
	Vagon(int netoM, int maxKP, int trPop)
	{
		netoMasa = netoM;
		maxKapPon = maxKP;
		this->trPop = trPop;
	}

};