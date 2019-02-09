#include <iostream>
#include <vector>
#include "Spiller.h"


int Konto::kontoer = 0;
int Spiller::spillere = 0;



//lager en liste med spillere og kontoer med valgt valuta
std::vector<Spiller> spillerListe(std::string *navn, int size, Valuta v)
{
    std::vector<Spiller> liste;
    std::string* p = navn;
    for(int i = 0; i < size; i++)
    {
        Konto k(v);
        Spiller s(*p, k);
        liste.push_back(s);
        p++;
    }
    return liste;
}


int main()
{
	
    std::string navneliste[4] = {"Jon", "Rick", "Dave", "Daniel"};
    std::string* nl = navneliste;
    std::vector<Spiller> ss = spillerListe(nl, 4, Valuta::Bitcoin);
    
    for(std::vector<Spiller>::iterator it = ss.begin(); it != ss.cend(); it++)
    {
        std::cout << *it << std::endl;
    }
    
}

