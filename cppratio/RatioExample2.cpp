// Second Example to demonstrate the Ratio class
// Jim Teresco, Siena College, CSIS 340, Fall 2023, and Copilot

#include "Ratio.h"
#include <iostream>

int main() {
    
    // pointers to some ratios
    Ratio *r1, *r2, *ans;

    // pointer to a dynamically-allocated array of Ratio pointers
    Ratio **r_array1;

    // a statically-allocated array of Ratio pointers
    Ratio *r_array2[3];

    // a statically-allocated array of Ratio objects (not pointers) 
    Ratio r_array3[3];

    int i;

    // create some Ratio objects
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
    
    return 0;
}