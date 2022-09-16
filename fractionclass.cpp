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
  if (fractionOutput.denominator == 1) { // special outcome for if denominator is equal to 1, in which case it can just be expressed as a whole number
    output << fractionOutput.numerator << std::endl;
  }
  else if (fractionOutput.denominator == 0) { //special outcome for if denominator is equal to 0, in which case it returns an undefined value
    output << "undefined" << std::endl;
  }
  else {
    output << fractionOutput.numerator << "/" << fractionOutput.denominator << std::endl;
  }
  return output;
}