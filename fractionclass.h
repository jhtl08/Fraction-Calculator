#ifndef FRACTIONCLASS_H
#define FRACTIONCLASS_H

#include <iostream>

class Fraction
{
  private:
    //attributes of a fraction
    int numerator, denominator;

  public:
    //constructors of the class
    //empty constructor
    Fraction();
    //non-empty constructor
    Fraction(int num, int den);
    
    //overloading the insertion operator
    friend std::ostream& operator<<(std::ostream& output, const Fraction& fractionOutput);
};

#endif