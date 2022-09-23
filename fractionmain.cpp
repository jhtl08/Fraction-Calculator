//fractionmain.cpp
//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 15, 2022

#include <iostream>
#include "fractionclass.h"

using namespace std;

int main()
{
  Fraction a = Fraction(49,1001);
  Fraction b = Fraction(100,50);
  Fraction fSum, fDifference, fProduct, fQuotient; //f for fraction

  cout<<"a= "<<a<<endl;
  cout<<"b= "<<b<<endl;

  fSum=a+b;
  cout<<"a + b = "<<fSum << "\t";

  fDifference=a-b;
  cout<<"a - b = "<<fDifference<<endl;

  fProduct=a*b;
  cout<<"a * b = "<<fProduct<<"\t";

  fQuotient=a/b;
  cout<<"a / b = "<<fQuotient<<endl;

  system("pause");
}
