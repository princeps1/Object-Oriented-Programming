//MOZDA I NE TREBA OVO POSTO JE NAPISANO U RODITELJSKOJ KLASI
//#include <iostream>
//#include <string.h>
#include "Vagon.h"

class PutnickiVagon :public Vagon//NAGOVESTAVANJE DA JE IZVEDENA KLASA
{
private:
	int maxBrPut;
	int trBrPut;
public:
	/*MORA DA SE NAVEDU ATRIBUTI PRVO IZ RODITELJSKE PA ONDA 
	IZ IZVEDENE KLASE U IZVEDENOM KONSTRUKTORU.
	NISU NAVEDENI "MaxKapP i trPop" JER MORAJU DA SE IZRACUNAJU*/
	PutnickiVagon(int netoM, int maxBP, int trBP) : Vagon(netoM, maxBP * 80, trBP * 80)
	{
		maxBrPut = maxBP;
		trBrPut = maxBP;
	}
};

