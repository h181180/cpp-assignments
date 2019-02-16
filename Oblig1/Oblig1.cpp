#include <iostream>
#include <vector>
#include "Spiller.h"


int Konto::kontoer = 0;
int Spiller::spillere = 0;



//lager en liste med spillere og kontoer med valgt valuta
std::vector<Spiller*> spillerListe(std::string *navn, int size, Valuta v, std::vector<Transaksjon> &t)
{
    std::vector<Spiller*> liste;
    std::string* p = navn;
    for(int i = 0; i < size; i++)
    {
        
        Spiller* s = new Spiller(*p,new Konto(v),t);
        s->innskudd(1000);
        std::cout << s->getBeholdning() << std::endl;
        liste.push_back(s);
        p++;
    }
    return liste;
}


int main()
{
	std::vector<Transaksjon> t;
    std::string navneliste[4] = {"Jon", "Johnny", "Dave", "Daniel"};
    std::string* nl = navneliste;
    
    std::vector<Spiller*> ss = spillerListe(nl, 4, Valuta::Bitcoin, t);
    
    ss.at(1)->innskudd(1000);
    ss.at(1)->betal(*ss.at(0), 50);
    ss.at(1)->betal(*ss.at(2), 87);
    ss.at(3)->betal(*ss.at(2), 300);
    
    // Overfører alt til Jon
    *ss.at(0) + *ss.at(1);
    // Overfører alt til Johnny
    *ss.at(0) - *ss.at(1);
    
    
    for(std::vector<Spiller*>::iterator it = ss.begin(); it != ss.end(); it++)
    {
        std::cout << **it << std::endl;
    }
    
    for(std::vector<Transaksjon>::iterator it = t.begin(); it != t.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    
    // Uten *dereferencing så sammenlignes bare pointer adressene (ikkje objektene)
    std::cout << (*ss.at(0) == *ss.at(1)) << std::endl;
    
    
}

