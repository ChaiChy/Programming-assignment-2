#ifndef SCHALTUNG
#define SCHALTUNG
#include "baustein.hpp"
#include "schnittstelle.hpp"

class Schaltung : public Baustein
{
public:
    std::vector<Schnittstelle*> intermediate; //intermediate outputs for full adder circuit
    std::vector<Baustein*> bausteine;
};

#endif
