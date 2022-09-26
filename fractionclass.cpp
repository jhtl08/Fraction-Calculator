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
        if (fractionOutput.denominator < 0)
        {
        fractionOutput.denominator = -1 * fractionOutput.denominator;
        fractionOutput.numerator = -1 * fractionOutput.numerator;
        }

      output << fractionOutput.numerator << "/" <<
      fractionOutput.denominator;
    }
    }
  return output;
}

std::istream& operator>>(std::istream& input, Fraction& fractionInput)
{
  char equalSign;
  char vinculum;

  //parses contents of istream to recognize input as valid fraction
  input >> fractionInput.variable_or_end;
  
  //checks if the user input is variable is valid or want to end
  if (fractionInput.variable_or_end == "a" || fractionInput.variable_or_end == "b")
  { //user enters a variable
    input >> equalSign >> fractionInput.numerator;

    //checks if istream input still has contents
    //it also checks if the input is a fraction
    if (input.peek()=='/') 
    { //fraction
        input >> vinculum >> fractionInput.denominator;
        if (fractionInput.denominator < 0)
        {//negative sign in the denominator
            fractionInput.denominator = -1 * fractionInput.denominator;
            fractionInput.numerator = -1 * fractionInput.numerator;
        }
    }
    else
    {//whole number
        fractionInput.denominator = 1;
    }
  }

  return input;
}

std::string Fraction::get_variable_or_end()
{
    return variable_or_end;
}

int* Fraction::fraction()
{
    int* fractionAttributes = new int(2);

    fractionAttributes[0] = numerator;
    fractionAttributes[1] = denominator;

    return fractionAttributes;
}
