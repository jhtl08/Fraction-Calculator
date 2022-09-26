//fractionclass.h
//Members: Kyle Coloma, Jason Lorenzo, Paolo Ong
//Project 1 Fraction Calculator
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

    //access which input variable is to have a new
    //value, relies on the user input
    std::string get_variable_or_end();

    //stores the input numerator and denominator in an array
    //which the frctionmain.cpp can access to the updated
    //numerator or denominator of a "a" or "b"
    int* fractionAttributes();
  };

#endif