#pragma once
#include "Valuta.h"


class Konto
{
private:
	int id;
	//settes når objektet opprettes
	Valuta valuta;
	//starter på 0, alltid >= 0
	double beholdning;

public:
	Konto(Valuta v);
	//i > 0
	bool innskudd(double i);
	//u > 0 
	bool uttak(double u);
	//max 8 desimaler (bitcoin)
	double getBeholdning() const;
	Valuta getValuta() const;

	static int kontoer;


};

