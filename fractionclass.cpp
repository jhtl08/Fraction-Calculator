//fractionclass.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 26, 2022

#include "fractionclass.h"

Fraction::Fraction()
  {
    numerator = 0;
    denominator = 1;
  }

Fraction::Fraction(int num, int den)
  {
    numerator = num;
    denominator = den;
  }

Fraction& Fraction::operator=(const Fraction& resultFraction)
{
  numerator = resultFraction.numerator;
  denominator = resultFraction.denominator;
  return *this;
}

Fraction Fraction::operator+(const Fraction& secondFraction)const
{
  Fraction sum;

  if (denominator == secondFraction.denominator)
  //both denominators are equal
  {
    sum.numerator = numerator + secondFraction.numerator;
    sum.denominator = denominator;
  }
  else //both are not equal
  {
    sum.numerator = numerator*secondFraction.denominator + 
    secondFraction.numerator*denominator;

    sum.denominator = denominator*secondFraction.denominator;
  }
  return sum;
}

Fraction Fraction::operator-(const Fraction& secondFraction)const
{
  Fraction difference;
  if (denominator == secondFraction.denominator)
  //both denominators are equal
  {
    difference.numerator = numerator - secondFraction.numerator;
    difference.denominator = denominator;
  }
  else //both are not equal
  {
    difference.numerator = numerator*secondFraction.denominator
    - secondFraction.numerator*denominator;

    difference.denominator = denominator*
    secondFraction.denominator;
  }
  return difference;
}

Fraction Fraction::operator*(const Fraction& secondFraction) const
{
  Fraction product;
  product.numerator=numerator*secondFraction.numerator;
  product.denominator=denominator*secondFraction.denominator;
  return product;
}

Fraction Fraction::operator/(const Fraction& secondFraction) const
{
  Fraction quotient;
  quotient.numerator=numerator*secondFraction.denominator;
  quotient.denominator=denominator*secondFraction.numerator;
  return quotient;
}

std::ostream& operator<<(std::ostream& output, Fraction& 
fractionOutput)
{
  int gcf;
  int x = fractionOutput.numerator;
  int y = fractionOutput.denominator;

  if (y == 0) //checks first if denominator is equal to 0. if yes,
  //immediately return undefined value. if not, proceed as follows.
  {
    output << "undefined";
  }
  else
  {
    while (y != 0) //simplification process: 1.) get GCF 2.)
    //divide fraction by GCF
  {
    gcf = y;
    y = x % y;
    x = gcf;
  }
    fractionOutput.numerator = fractionOutput.numerator / x;
    fractionOutput.denominator = fractionOutput.denominator / x;

    if (fractionOutput.denominator == 1)
    { // special outcome for if denominator is equal to 1, in
      //which case it can just be expressed as a whole number
      output << fractionOutput.numerator;
    }
    else
    {
      output << fractionOutput.numerator << "/" <<
      fractionOutput.denominator;
    }
    }
  return output;
}

int* operator>>(std::istream& input, Fraction& fractionInput)
{
  char equalSign;
  char vinculum;
  int *fractionAttributes = new int(2);

  //parses contents of istream
  input >> equalSign >> fractionInput.numerator;

  //checks if istream input still has contents
  if (input.peek()=='/')
  {
    input >> vinculum >> fractionInput.denominator;
  }
  //if it doesn't, ends extraction and makes fraction whole
  else
  {
    fractionInput.denominator=1;
  }

  //returns an array of the fraction's attributes
  fractionAttributes[0]=fractionInput.numerator;
  fractionAttributes[1]=fractionInput.denominator;
  return fractionAttributes;
}
