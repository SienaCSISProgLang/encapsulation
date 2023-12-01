// Second Example to demonstrate the Ratio class
// Jim Teresco, Siena College, CSIS 340, Fall 2023, and Copilot

#include "Ratio.h"
#include <iostream>

// a global Ratio, static allocation
Ratio r_glob;

int main() {
    
    // pointers to some ratios to use later
    Ratio *r1, *r2, *ans;

    // a stack-dynamic Ratio, using default constructor
    Ratio r3;

    // another stack-dynamic Ratio initialized to 3/4
    Ratio r4(3, 4);

    // pointer to a dynamically heap-allocated array of Ratio pointers
    Ratio **r_array1;

    // a stack-dynamic allocated array of Ratio pointers
    Ratio *r_array2[3];

    // a stack-dynamic array of Ratio objects (not pointers) 
    Ratio r_array3[3];

    int i;

    // give r_glob some values
    r_glob.setNumerator(1);
    r_glob.setDenominator(2);
    // print r_glob
    std::cout << "r_glob is ";
    r_glob.print();
    std::cout << std::endl;

    // construct some Ratio objects
    r1 = new Ratio(1, 3);
    r2 = new Ratio(1, 6);

    ans = Ratio::add(r1, r2);

    // print the addends and the sum
    r1->print();
    std::cout << " + ";
    r2->print();
    std::cout << " = ";
    ans->print();
    std::cout << std::endl;

    // free the memory allocated so far
    delete r1;
    delete r2;
    delete ans;

    // create the dynamically-allocated array of Ratio pointers
    r_array1 = new Ratio*[3];

    // put some Ratio objects in that array
    r_array1[0] = new Ratio(15, 24);
    r_array1[1] = new Ratio(3, 6);
    r_array1[2] = new Ratio(9, 16);

    // reduce these to lowest terms
    for (i = 0; i < 3; i++) {
        r_array1[i]->print();
        std::cout << " reduced is ";
        r_array1[i]->reduce();
        r_array1[i]->print();
        std::cout << std::endl;
    }

    // save pointers to two of these in our statcally-allocated array
    r_array2[0] = r_array1[0];
    r_array2[1] = r_array1[1];

    // free the memory of the third
    delete r_array1[2];

    // free the memory of the dynamically-allocated array
    delete [] r_array1;

    // add the two in the stack-allocated array and store the new Ratio in the third
    r_array2[2] = Ratio::add(r_array2[0], r_array2[1]);

    // print this addition problem
    r_array2[0]->print();
    std::cout << " + ";
    r_array2[1]->print();
    std::cout << " = ";
    r_array2[2]->print();
    std::cout << std::endl;

    // free the memory of the Ratios in r_array2
    for (i = 0; i < 3; i++) {
        delete r_array2[i];
    }

    // put some values in r_array3
    r_array3[0].setNumerator(10);
    r_array3[0].setDenominator(13);
    r_array3[1].setNumerator(4);
    r_array3[1].setDenominator(10);
    r_array3[2].setNumerator(8);
    r_array3[2].setDenominator(9);

    // Reduce and print the Ratios in r_array3
    for (i = 0; i < 3; i++) {
        r_array3[i].print();
        std::cout << " reduced is ";
        r_array3[i].reduce();
        r_array3[i].print();
        std::cout << std::endl;
    }
    
    // Set the numerator and denominator of our stack-dynamic allocated Ratio that used the default constructor
    r3.setNumerator(6);
    r3.setDenominator(27);
    // print r3
    std::cout << "r3 before reduce is ";
    r3.print();
    std::cout << std::endl;
    // reduce r3
    r3.reduce();
    // print r3 again
    std::cout << "r3 after reduce is ";
    r3.print();
    std::cout << std::endl;

    // now add r3 to the other stack-dynamic Ratio, r4
    std::cout << "r4 before adding r3 is ";
    r4.addToThis(r3);
    // print r4
    std::cout << "r4 after adding r3 is ";
    r4.print();
    std::cout << std::endl;

    return 0;
}