// header file for Ratio class example
// Jim Teresco, Siena College, CSIS 340, Fall 2023, and Copilot

class Ratio
{
private:
    int numerator;
    int denominator;
public:
    Ratio(int n, int d);
    Ratio();
    ~Ratio();
    void print();
    void setNumerator(int n);
    void setDenominator(int d);
    int getNumerator();
    int getDenominator();
    void reduce();
    Ratio *add(Ratio *other);
    void addToThis(Ratio *other);
    void addToThis(Ratio other);
    static Ratio *add(Ratio *r1, Ratio *r2);

};