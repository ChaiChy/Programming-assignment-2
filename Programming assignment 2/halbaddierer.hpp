#ifndef HALBADDIERER
#define HALBADDIERER
#include "schaltung.hpp"
#include "or.hpp"
#include "and.hpp"
#include "xor.hpp"


class Halbaddierer : public Schaltung
{
public:
    Halbaddierer(Schnittstelle* input0, Schnittstelle* input1, Schnittstelle* output0, Schnittstelle* output1)
    {
        addInput(input0);
        addInput(input1);
        addOutput(output0);
        addOutput(output1);
        Xor2* xorGate = new Xor2(input0, input1, output0);
        bausteine.push_back(xorGate);
        And2* andGate = new And2(input0, input1, output1);
        bausteine.push_back(andGate);
        this->name = "Halbaddierer";
    }

    void update()
    {
        bausteine[0]->update(); //xor
        bausteine[1]->update(); //and
    }
};
#endif
