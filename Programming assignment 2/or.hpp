#ifndef OR
#define OR
#include "baustein.hpp"
#include "schnittstelle.hpp"

class Or2 : public Baustein
{
public:
    Or2(Schnittstelle* input0, Schnittstelle* input1, Schnittstelle* output0)
    {
        this->name = "Or2";
        addInput(input0);
        addInput(input1);
        addOutput(output0);
    }
    void update()
    {
        if (input[0]->getPegel() == Schnittstelle::LOW && input[1]->getPegel() == Schnittstelle::LOW)
        {
            output[0]->setPegel(Schnittstelle::LOW);
        }
        else if ((input[0]->getPegel() == Schnittstelle::HIGH || input[1]->getPegel() == Schnittstelle::HIGH)
            && (input[0]->getPegel() != Schnittstelle::UNDEFINED && input[1]->getPegel() != Schnittstelle::UNDEFINED))
        {
            output[0]->setPegel(Schnittstelle::HIGH);
        }
        else
        {
            output[0]->setPegel(Schnittstelle::UNDEFINED);
        }
    }
};

#endif
