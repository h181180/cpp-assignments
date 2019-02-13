#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "Konto.h"
#include "Transaksjon.h"

class Spiller
{
private:

	int id;
	std::string navn;
	Konto* konto;
    std::vector<Transaksjon>& transaksjoner;

public:

	Spiller(std::string n, Konto* konto, std::vector<Transaksjon>& t);
	void setNavn(std::string n);
	std::string getNavn() const;
	int getId() const;
	Valuta getValuta() const;
	double getBeholdning() const;
	bool uttak(double u);
	bool innskudd(double i);
    int getKontoId() const;

	bool betal(Spiller& spiller, double belop);
	void opprettTransaksjon(Spiller& spiller, double belop);
	//sjekke om begge spillerene bruker samme valuta
	bool operator==(const Spiller& spiller) const;
	friend std::ostream& operator<<(std::ostream& stream, const Spiller& s);
	static int spillere;


};


inline std::ostream& operator<<(std::ostream& stream, const Spiller& s)
{
	stream << "Spiller: " << s.navn << "(" << s.id << ")" << "\n" << "Konto: " << s.getBeholdning() << "\tid: " << s.getKontoId() << "\n\n";
	return stream;
}
