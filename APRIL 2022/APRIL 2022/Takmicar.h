#pragma once
#include <iostream>


using namespace std;

class Takmicar
{
private:
	int id;
	int startniBroj;
	int rezultat;
public:
	Takmicar()
	{
		id = 0;
		startniBroj = 0;
		rezultat = 0;
	}

	Takmicar(int id, int start, int rez)
	{
		this->id = id;
		startniBroj = start;
		rezultat = rez;
	}

	bool operator==(int id)
	{
		if (this->id == id)
			return true;
		else
			return false;
	}

	friend ostream& operator<<(ostream& out, Takmicar& T)
	{
		out << T.id << " " << T.startniBroj << " " << T.rezultat << endl;
		return out;
	}
};