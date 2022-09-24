//fractionclass.h
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 15, 2022

#ifndef FRACTIONCLASS_H
#define FRACTIONCLASS_H

#include <iostream>
#include <string>

class Fraction
{
  private:
    //attributes of a fraction
    int numerator, denominator;
    int in_num;
    int in_den;
    std::string variable;

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
    friend std::ostream& operator<<(std::ostream& output, Fraction& fractionOutput);

    friend std::istream& operator>>(std::istream& in, Fraction& f);

    std::string get_variable()
    {
        return variable;
    };

    int get_num()
    {
        return in_num;
    };

    int get_den()
    {
        return in_den;
    };

  };

#endif