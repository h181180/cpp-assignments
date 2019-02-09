#include "pch.h"
#include <iostream>
#include <vector>
#include "Spiller.h"


int Konto::kontoer = 0;
int Spiller::spillere = 0;

int main()
{
	Konto k1(Valuta::Bitcoin);
	Konto k2(Valuta::Gullmynter);
	Konto k3(Valuta::Hackos);
	Konto k4(Valuta::Bitcoin);

	std::vector<Spiller> spillerListe;

	
	Spiller a("Jens", k1);
	a.innskudd(2000);
	Spiller b("Bob", k2);
	b.innskudd(200);
	Spiller c("Peter", k3);
	c.innskudd(400);
	Spiller d("Patty", k4);
	d.innskudd(1000);
	
	a.betal(d, 1500);
	a.betal(b, 500);
	a.betal(d, 1000);


	

    std::cout << a << b << c << d; 
}
