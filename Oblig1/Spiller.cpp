#include "Spiller.h"




Spiller::Spiller (std::string n, Konto* konto, std::vector<Transaksjon>& t) : id(spillere++), navn(n), konto(konto), transaksjoner(t) 
{

}

void Spiller::setNavn(std::string n)
{
	this->navn = n;
}

std::string Spiller::getNavn() const
{
	return navn;
}

int Spiller::getId() const
{
	return id;
}

Valuta Spiller::getValuta() const
{
	return konto->getValuta();
}

double Spiller::getBeholdning() const
{
	return konto->getBeholdning();
}

bool Spiller::uttak(double u)
{
	return konto->uttak(u);
}

bool Spiller::innskudd(double i)
{
	return konto->innskudd(i);
}

bool Spiller::betal(Spiller& spiller, double b)
{
	if (konto->getBeholdning() >= b && konto->getValuta() == spiller.getValuta())
	{
        transaksjoner.push_back(Transaksjon(id, spiller.getId(), b));
		return uttak(b) && spiller.innskudd(b);
	}
	else
	{
		std::cout << navn << " har ikkje dekning, eller har ikkje samme valuta som " << spiller.getNavn() << "\n";
		return false;
	}
}

int Spiller::getKontoId() const 
{
    return konto->getId();
}

