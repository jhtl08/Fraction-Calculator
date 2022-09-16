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

std::ostream& operator<<(std::ostream& output, Fraction& fractionOutput)
{
    int gcf;
    int x = fractionOutput.numerator;
    int y = fractionOutput.denominator;
    if (y == 0)
    {
        output << "undefined" << std::endl;
    }
    else
    {
      while (y != 0)
      {
        gcf = y;
        y = x % y;
        x = gcf;
      }
      fractionOutput.numerator = fractionOutput.numerator / x;
      fractionOutput.denominator = fractionOutput.denominator / x;

      if (fractionOutput.denominator == 1) 
      { // special outcome for if denominator is equal to 1, in which case it can just be expressed as a whole number
        output << fractionOutput.numerator << std::endl;
      }
      else 
      {
        output << fractionOutput.numerator << "/" << fractionOutput.denominator << std::endl;
      }
    } 
  return output;
}