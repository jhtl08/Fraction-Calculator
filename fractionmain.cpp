//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 15, 2022

#include <iostream>
#include "fractionclass.h"

using namespace std;

int main()
{
    // default value for a and b
    int a_num = 0;
    int a_den = 1;
    int b_num = 0;
    int b_den = 1;

while(true)
{
  Fraction userInput;
  Fraction a = Fraction(a_num, a_den);
  Fraction b = Fraction(b_num, b_den);

  cout<<"\na = "<<a<<"   " <<"b = "<<b<<endl;

  Fraction fSum, fDifference, fProduct, fQuotient; //f for fraction

  fSum=a+b;
  fDifference=a-b;
  fProduct=a*b;
  fQuotient=a/b;

  cout<<"a + b = "<<fSum << "   " << "a - b = "<<fDifference<< "   " << "a * b = "<<fProduct<< "   " << "a / b = "<<fQuotient<< "   ";

  cout <<"\n> ";
  cin >> userInput; // ask for which variable the new value will be inserted

  if(userInput.get_variable() == "a") // if the variable is a, a will have a new value
  {
      a_num = userInput.get_num();
      a_den = userInput.get_den();
  }
  if(userInput.get_variable() == "b") // if the variable is b, b will have a new value
  {
      b_num = userInput.get_num();
      b_den = userInput.get_den();
  }
    cin.clear();
}
  //system("pause");
  return 0;
}
