#include "pch.h"
#include "Konto.h"
#include <cmath>


Konto::Konto(Valuta v) : id(kontoer++), beholdning(0), valuta(v)
{
}

bool Konto::innskudd(double i)
{
	if (i > 0)
	{
		beholdning += i;
		return true;
	}
	else
	{
		return false;
	}
}

bool Konto::uttak(double u)
{
	if (u > 0 && (beholdning - u) >= 0)
	{
		beholdning -= u;
		return true;
	}
	else
	{
		return false;
	}
}


/*
	returnerer med 8 desimaler med bitcoin, 2 desimaler for resten
*/
double Konto::getBeholdning() const
{
	double b = beholdning;
	if (valuta == Valuta::Bitcoin)
	{
		return floor(b * 100000000) / 100000000;
	}
	else
	{
		return floor(b * 100) / 100;
	}
}

Valuta Konto::getValuta() const
{
	return valuta;
}