#pragma once
#include "Valuta.h"


class Konto
{
private:
	int id;
    //starter på 0, alltid >= 0
	double beholdning;
	//settes når objektet opprettes
	Valuta valuta;

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

