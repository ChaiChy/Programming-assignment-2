#ifndef VOLLADDIERER
#define VOLLADDIERER
#include "schaltung.hpp"
#include "or.hpp"
#include "and.hpp"
#include "xor.hpp"
#include "halbaddierer.hpp"
#include "volladdierer.hpp"
#include "baustein.hpp"

class Volladdierer : public Schaltung
{
public:
    friend void testFull(Volladdierer* voll);
    friend class Test;

    Volladdierer(Schnittstelle* input0, Schnittstelle* input1, Schnittstelle* input2,
        Schnittstelle* output0, Schnittstelle* output1)
    {
        addInput(input0);
        addInput(input1);
        addInput(input2);
        addOutput(output0);
        addOutput(output1);

        //create instances of *Schnittstelle i0, i1, i2 to use it as intermediate outputs in order to construct the full adder circuit
        Schnittstelle* i0 = new Schnittstelle();
        Schnittstelle* i1 = new Schnittstelle();
        Schnittstelle* i2 = new Schnittstelle();
        //output0 = sum && ouput1 = carry 
        Halbaddierer* halbaddierer_01 = new Halbaddierer(input0, input1, i0, i1);
        bausteine.push_back(halbaddierer_01);
        Halbaddierer* halbaddierer_02 = new Halbaddierer(i0, input2, output0, i2);
        bausteine.push_back(halbaddierer_02);
        Or2* orGate = new Or2(i1, i2, output1);
        bausteine.push_back(orGate);
        this->name = "Volladdierer";
    }
    void print()
    {
        std::cout << "Baustein: " << name << std::endl;
        for (int i = 0; i < input.size(); i++)
        {
            std::cout << "Input " << i << ": " << "Pegel = " << input[i]->getPegel() << std::endl;
        }
        std::cout << "Sum: " << "Pegel = " << output[0]->getPegel() << std::endl; 
        std::cout << "Carry: " << "Pegel = " << output[1]->getPegel() << std::endl;
    }
    void update()
    {
        bausteine[0]->update(); //halbaddierer_01
        bausteine[1]->update(); //halbaddierer_02
        bausteine[2]->update(); //orGate
    }
};

#endif
