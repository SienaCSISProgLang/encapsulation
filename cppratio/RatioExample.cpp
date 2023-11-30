// Example to demonstrate the Ratio class
// Jim Teresco, Siena College, CSIS 340, Fall 2023, and Copilot

#include "Ratio.h"
#include <iostream>

int main()
{
    Ratio *r1 = new Ratio(1, 2);
    Ratio *r2 = new Ratio(3, 4);
    Ratio *r3 = r1->add(r2);
    r3->print();
    std::cout << std::endl;
    r3->addToThis(r1);
    r3->print();
    std::cout << std::endl;
    Ratio *r4 = Ratio::add(r1, r2);
    r4->print();
    std::cout << std::endl;
    delete r1;
    delete r2;
    delete r3;
    delete r4;
    return 0;
}