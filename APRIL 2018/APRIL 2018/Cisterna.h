//POKAZI OVDEEEEEEEE
#include "Vagon.h"

class Cisterna :public Vagon
{
private:
	float gustina;
public:
	Cisterna(int netoM, int maxKP, int trPop, float g) : Vagon(netoM, maxKP, trPop)
	{
		gustina = g;
	}
};