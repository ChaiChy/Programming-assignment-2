#ifndef BAUSTEIN
#define BAUSTEIN

#include <iostream>
#include <vector>
#include <string>
#include "schnittstelle.hpp"


class Baustein // building block
{
protected:
    std::string name;
    std::vector<Schnittstelle*> input;
    std::vector<Schnittstelle*> output;
public:
    friend void test2(Baustein* baustein);
    friend class Test;

    void addInput(Schnittstelle* schnittstelle)
    {
        input.push_back(schnittstelle);
    }
    void addOutput(Schnittstelle* schnittstelle)
    {
        output.push_back(schnittstelle);
    }
    virtual void print() //virtual because func is designed to be overridden by different gate classes such as XOR, OR, AND etc
    {
        std::cout << "Baustein: " << name << std::endl;
        for (int i = 0; i < input.size(); i++)
        {
            std::cout << "Input " << i << ": " << "Pegel = " << input[i]->getPegel() << std::endl;
        }
        for (int i = 0; i < output.size(); i++)
        {
            std::cout << "Output " << i << ": " << "Pegel = " << output[i]->getPegel() << std::endl; // 2 inputs corresponds to 1 output
        }
    }

    virtual void update() = 0; //pure virtual
};

#endif
