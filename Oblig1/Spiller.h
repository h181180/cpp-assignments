#pragma once
#include <string>
#include <iostream>
#include "Konto.h"

class Spiller
{
private:

	int id;
	std::string navn;
	Konto& konto;

public:

	Spiller(std::string n, Konto& konto);
	void setNavn(std::string n);
	std::string getNavn() const;
	int getId() const;
	Valuta getValuta() const;
	double getBeholdning() const;
	bool uttak(double u);
	bool innskudd(double i);

	bool betal(Spiller& spiller, double belop);
	void opprettTransaksjon(Spiller& spiller, double belop);
	//sjekke om begge spillerene bruker samme valuta
	bool operator==(const Spiller& spiller) const;
	friend std::ostream& operator<<(std::ostream& stream, const Spiller& s);
	static int spillere;


};


inline std::ostream& operator<<(std::ostream& stream, const Spiller& s)
{
	stream << "Spiller: " << s.navn << "(" << s.id << ")" << "\n" << "Konto: " << s.getBeholdning() << "\n\n";
	return stream;
}
