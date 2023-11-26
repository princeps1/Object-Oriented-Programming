#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Proizvod
{
protected:
	char* barkod;
	char* tip;
public:
	Proizvod(char* bar, char* t)
	{
		barkod = new char[strlen(bar) + 1];
		tip = new char[strlen(t) + 1];
		strcpy(barkod, bar);
		strcpy(tip, t);
	}

	virtual ~Proizvod()
	{
		delete[] barkod;
		delete[] tip;
	}

	void upisi(ofstream& f)
	{
		f << barkod << " " << tip << endl;
	}

	virtual bool defektan() = 0;
};