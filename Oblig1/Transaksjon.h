#include <iostream>

class Transaksjon
{
private:
    int fraId, tilId;
    double belop;
    
public:
    Transaksjon(int f, int t, double b) : fraId{f}, tilId{t}, belop{b} {}
    friend std::ostream& operator<<(std::ostream& stream, const Transaksjon& t);
};


inline std::ostream& operator<<(std::ostream& stream, const Transaksjon& t)
{
    stream << "\t[Transaksjon]\n" << "+" << t.belop << " til konto " << t.tilId << ", \n" << "fra konto " << t.fraId << "\n\n";
    return stream;
}