//fractionclass.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 15, 2022

#include <iostream>
#include "fractionclass.h"

Fraction::Fraction()
    {
      numerator = 0;
      denominator = 0;
    }

Fraction::Fraction(int num, int den)
    {
      numerator = num;
      denominator = den;
    }

std::ostream& operator<<(std::ostream& output, const Fraction& fractionOutput)
{
  output<<fractionOutput.numerator<<"/"<<fractionOutput.denominator<<std::endl;   
  return output;
}