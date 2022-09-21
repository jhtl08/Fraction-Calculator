//fractionmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 15, 2022

#include <iostream>
#include "fractionclass.h"

using namespace std;

int main()
{
  Fraction a = Fraction(1000,500);
  Fraction b = Fraction(2,4);

  cout<<"a= "<< a;
  cout<<"b= "<<b;

  cout << "a + b = " << a + b << endl;
  cout << "a - b = " << a - b << endl;


  system("pause"); //I put this here bc Visual Studio keeps closing the terminal immediately. -Paolo
}
