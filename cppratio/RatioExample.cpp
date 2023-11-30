// Example to demonstrate the Ratio class
// Jim Teresco, Siena College, CSIS 340, Fall 2023, and Copilot

#include "Ratio.h"
#include <iostream>

int main()
{
    Ratio r1(1, 2);
    Ratio r2(3, 4);
    Ratio r3 = r1.add(r2);
    r3.print();
    std::cout << std::endl;
    r3.addToThis(r1);
    r3.print();
    std::cout << std::endl;
    Ratio r4 = Ratio::add(r1, r2);
    r4.print();
    std::cout << std::endl;
    return 0;
}