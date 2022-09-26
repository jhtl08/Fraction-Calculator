//fractionclass.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 26, 2022

#ifndef FRACTIONCLASS_H
#define FRACTIONCLASS_H

#include <iostream>

class Fraction
{
  private:
    //attributes of a fraction
    int numerator, denominator;
    std::string variable_or_end;

  public:
    //constructors of the class
    //empty constructor
    Fraction();

    //non-empty constructor
    Fraction(int num, int den);

    //Overloading assignment operator=
    Fraction& operator=(const Fraction& resultFraction);

    //overloading the + operator
    Fraction operator+(const Fraction& secondFraction)const;

    //overloading the - operator
    Fraction operator-(const Fraction& secondFraction)const;

    //overloading the * operator
    Fraction operator*(const Fraction& secondFraction)const;

    //overloading the / operator
    Fraction operator/(const Fraction& secondFraction)const;

    //overloading the insertion operator
    friend std::ostream& operator<<(std::ostream& output, 
    Fraction& fractionOutput);

    //overloading the extraction operator to recognize
    //integers as valid fraction values
    friend std::istream& operator>>(std::istream& input, 
    Fraction& fractionInput);

    //accessing the input variable from the private class
    std::string get_variable_or_end();

    //produces the list of input numerator and denominator
    int* fraction();
  };

#endif