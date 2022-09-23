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

Fraction& Fraction::operator=(const Fraction& resultFraction)
{
  numerator = resultFraction.numerator;
  denominator = resultFraction.denominator;
  return *this;
}

Fraction Fraction::operator+(const Fraction& secondFraction)const
{
    Fraction sum;
    if (numerator == secondFraction.numerator) 
    //both denominators are equal
    {
        sum.numerator = numerator + secondFraction.numerator;
        sum.denominator = numerator;
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
    if (numerator == secondFraction.numerator) 
    //both denominators are equal
    {
        difference.numerator = numerator - secondFraction.numerator;
        difference.denominator = numerator;
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
