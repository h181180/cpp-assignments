#include <iostream>
#include <vector>
#include "Spiller.h"


int Konto::kontoer = 0;
int Spiller::spillere = 0;



//lager en liste med spillere og kontoer med valgt valuta
std::vector<Spiller*> spillerListe(std::string *navn, int size, Valuta v)
{
    std::vector<Transaksjon> t;
    std::vector<Spiller*> liste;
    std::string* p = navn;
    for(int i = 0; i < size; i++)
    {
        
        Spiller* s = new Spiller(*p,new Konto(v),t);
        s->innskudd(2000);
        std::cout << s->getBeholdning() << std::endl;
        liste.push_back(s);
        p++;
    }
    return liste;
}


int main()
{
	
    std::string navneliste[4] = {"Jon", "Rick", "Dave", "Daniel"};
    std::string* nl = navneliste;
    Konto k(Valuta::Bitcoin);
    k.innskudd(1000);
    std::cout << k.getBeholdning() << std::endl;
    std::vector<Spiller*> ss = spillerListe(nl, 4, Valuta::Bitcoin);
    
    for(std::vector<Spiller*>::iterator it = ss.begin(); it != ss.end(); it++)
    {
        std::cout << **it << std::endl;
    }
    
    Konto* k2 = new Konto(Valuta::Hackos);
    std::vector<Transaksjon> abc;
    Spiller s1("Test", k2, abc);
    s1.innskudd(1500);
    std::cout << s1 << std::endl;
    
}

