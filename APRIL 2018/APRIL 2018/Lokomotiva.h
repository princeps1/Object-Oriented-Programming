#include <iostream>
#include <string.h>

using namespace std;

class Lokomotiva
{
private:
	char* tipMotora;//TIP MOTORA LOKOMOTIVE
	int maxTezP;//MAKSIMALNA TEZINA KOJU MOZE DA POVUCE
public:
	Lokomotiva(char* tipM, int maxTP)
	{
		tipMotora=new char[strlen(tipM)+1];//OBRATI PAZNJU,ZABORAVIO SI
		//tipMotora = tipM;NETACNO POGRESIO SI
		strcpy(tipMotora, tipM);//OBRATI PAZNJU!!
		maxTezP = maxTP;
	}
	~Lokomotiva()
	{
		delete[] tipMotora;
	}
};