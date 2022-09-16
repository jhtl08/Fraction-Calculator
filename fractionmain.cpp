//fractionmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 15, 2022

#include <iostream>
#include "fractionclass.h"

using namespace std;

int main()
{
  Fraction a = Fraction();
  Fraction b = Fraction(1,2);

  cout<<"a= "<< a;
  cout<<"b= "<<b;

  system("pause"); //I put this here bc Visual Studio keeps closing the terminal immediately. -Paolo
}
