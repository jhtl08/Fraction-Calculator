//fractionclass.cpp
//Members: Kyle Coloma, Jason Lorenzo, Paolo Ong
//Project 1 Fraction Calculator
//ENGG 31-N
//September 26, 2022

#include "fractionclass.h"

Fraction::Fraction()
{
  numerator = 0; //default numerator value for "a" and "b"
  denominator = 1; //default numerator value for "a" and "b"
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
  else 
  {//both denominators are not equal
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
  { //both denominators are equal
    difference.numerator = numerator - secondFraction.numerator;
    difference.denominator = denominator;
  }
  else 
  { //both denominators are not equal
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

  //checks first if denominator is equal to 0. If yes,
  //immediately return undefined value. if not, proceed as follows.
  if (y == 0) 
  { 
    output << "undefined";
  }
  else
  {
    //simplification process: 
    // (1) get GCF 
    // (2) divide fraction
    while (y != 0) 
    {
      gcf = y;
      y = x % y;
      x = gcf;
    }

      fractionOutput.numerator = fractionOutput.numerator / x;
      fractionOutput.denominator = fractionOutput.denominator / x;

      // special outcome for if denominator is equal to 1, in
      // which case it can just be expressed as a whole number
      if (fractionOutput.denominator == 1)
      { 
        output << fractionOutput.numerator;
      }
      else
      {
        // checks if denominator is negative, it turns the  
        // fraction into a negative fraction. Unless if the   
        // numerator is also negative the fraction becomes 
        // positive.
        if (fractionOutput.denominator < 0)
        {
          fractionOutput.denominator = 
          -1 * fractionOutput.denominator;

          fractionOutput.numerator = 
          -1 * fractionOutput.numerator;
        }

        output << fractionOutput.numerator << "/" <<
        fractionOutput.denominator;
      }
  }
  return output;
}

std::istream& operator>>(std::istream& input, Fraction& 
fractionInput)
{
  char equalSign, vinculum;

  //parses contents of istream to recognize input as valid fraction
  input >> fractionInput.inputVariable;
  
  //checks if the user input is variable is valid or want to end
  if (fractionInput.variable_or_end == "a" 
  || fractionInput.variable_or_end == "b")
  { //user enters a variable
    input >> equalSign >> fractionInput.numerator;

      //checks if istream input still has contents
      //it also checks if the input is a fraction
      if (input.peek()=='/') 
      { //input value is a fraction
        input >> vinculum >> fractionInput.denominator;

          if (fractionInput.denominator < 0) //if denominator is
          { //negative
            fractionInput.denominator = 
            -1 * fractionInput.denominator;

            fractionInput.numerator = 
            -1 * fractionInput.numerator;
          }

    }
    else
    {//input value is a whole number
      fractionInput.denominator = 1;
    }
  }

  return input;
}

std::string Fraction::get_variable_or_end()
{
  return inputVariable;
}

int* Fraction::fractionAttributes()
{
  int* fractionAttributes = new int(2);

  //stores new user input numerator
  fractionAttributes[0] = numerator;

  //stores new user input denominator
  fractionAttributes[1] = denominator;

  return fractionAttributes;
}
