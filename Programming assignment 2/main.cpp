#include <iostream>
#include "volladdierer.hpp"
#include "halbaddierer.hpp"
#include "baustein.hpp"
#include "schnittstelle.hpp"
#include "xor.hpp"
#include "and.hpp"
#include "schaltung.hpp"
#include "or.hpp"

class Test
{
public:
    void test(Baustein* baustein)
    {
        baustein->input[0]->setPegel(Schnittstelle::HIGH);
        baustein->input[1]->setPegel(Schnittstelle::HIGH);
        baustein->update();
        baustein->print();
    }
    void test(Volladdierer* volladdierer)
    {
        volladdierer->input[0]->setPegel(Schnittstelle::HIGH);
        volladdierer->input[1]->setPegel(Schnittstelle::LOW);
        volladdierer->input[2]->setPegel(Schnittstelle::HIGH);
        volladdierer->update();
        volladdierer->print();
    }

};

void test2(Baustein* baustein)
{
    baustein->input[0]->setPegel(Schnittstelle::HIGH);
    baustein->input[1]->setPegel(Schnittstelle::HIGH);
    baustein->update();
    baustein->print();
}
void testFull(Volladdierer* voll)
{
    voll->input[0]->setPegel(Schnittstelle::HIGH);
    voll->input[1]->setPegel(Schnittstelle::LOW);
    voll->input[2]->setPegel(Schnittstelle::HIGH);
    voll->update();
    voll->print();
}

int main()
{
    Schnittstelle e0, e1, e2, a0, a1;
    Volladdierer* voll = new Volladdierer(&e0, &e1, &e2, &a0, &a1);
    Halbaddierer* halb = new Halbaddierer(&e0, &e1, &a0, &a1);

    And2* and1 = new And2(&e0, &e1, &a0);
    Xor2* xor1 = new Xor2(&e0, &e1, &a0);
    Or2* or1 = new Or2(&e0, &e1, &a0);
    /*
    test2(and1);
    std::cout << "\n\n";
    test2(xor1);
    std::cout << "\n\n";
    test2(or1);
    std::cout << "\n\n";
    test2(halb);
    std::cout << "\n\n";
    testFull(voll);
    */

    Test tester;
    tester.test(voll);
    std::cout << "\n\n";
    tester.test(and1);
    std::cout << "\n\n";
    test2(xor1);
    std::cout << "\n\n";
    test2(or1);
}