// a simple Ratio class to demonstrate C++ classes
// Jim Teresco, Siena College, CSIS 340, Fall 2023, and Copilot

#include "Ratio.h"
#include <iostream>

// general constructor
Ratio::Ratio(int n, int d)
{
    numerator = n;
    denominator = d;
}

// default constructor that initializes to 1/1  
Ratio::Ratio()
{
    numerator = 1;
    denominator = 1;
}

// method to print a Ratio in n/d format
void Ratio::print()
{
    std::cout << numerator << "/" << denominator;
}

// set the numerator of a Ratio
void Ratio::setNumerator(int n)
{
    numerator = n;
}

// set the denominator of a Ratio
void Ratio::setDenominator(int d)
{
    denominator = d;
}

// get the numerator of a Ratio
int Ratio::getNumerator()
{
    return numerator;
}

// get the denominator of a Ratio
int Ratio::getDenominator()
{
    return denominator;
}

// reduce a Ratio to lowest terms
void Ratio::reduce()
{
    int gcd = 1;
    int smaller = numerator < denominator ? numerator : denominator;
    for (int i = 2; i <= smaller; i++) {
        if (numerator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }
    numerator /= gcd;
    denominator /= gcd;
}

// add a Ratio object to this Ratio, updating this Ratio to the new value
void Ratio::addToThis(Ratio r)
{
    numerator = numerator * r.denominator + r.numerator * denominator;
    denominator = denominator * r.denominator;
}

// add another Ratio object to this Ratio and return a new Ratio
Ratio Ratio::add(Ratio r)
{
    Ratio result;
    result.numerator = numerator * r.denominator + r.numerator * denominator;
    result.denominator = denominator * r.denominator;
    return result;
}

// static method to add two Ratio objects and return a new Ratio
Ratio Ratio::add(Ratio r1, Ratio r2)
{
    Ratio result;
    result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;
    return result;
}
Ratio::~Ratio()
{
}
