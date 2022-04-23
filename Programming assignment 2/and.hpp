#ifndef AND
#define AND
#include "baustein.hpp"
#include "schnittstelle.hpp"

class And2 : public Baustein
{
public:
    And2(Schnittstelle* input0, Schnittstelle* input1, Schnittstelle* output0)
    {
        this->name = "And2";
        addInput(input0);
        addInput(input1);
        addOutput(output0);
    }
    void update()
    {
        if (input[0]->getPegel() == Schnittstelle::HIGH && input[1]->getPegel() == Schnittstelle::HIGH)
        {
            output[0]->setPegel(Schnittstelle::HIGH);
        }
        else if (input[0]->getPegel() == Schnittstelle::UNDEFINED || input[1]->getPegel() == Schnittstelle::UNDEFINED)
        {
            output[0]->setPegel(Schnittstelle::UNDEFINED);
        }
        else
        {
            output[0]->setPegel(Schnittstelle::LOW);
        }
    }
};

#endif
