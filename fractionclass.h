//fractionclass.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 15, 2022

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
    friend std::ostream& operator<<(std::ostream& output, Fraction& fractionOutput);

};

#endif