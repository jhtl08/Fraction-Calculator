//Kyle Coloma, Jason Lorenzo, Paolo Ong
//ENGG 31-N
//September 26, 2022

#include "fractionclass.h"

using namespace std;

int main()
{
  Fraction a = Fraction();
  Fraction b = Fraction();
  
  Fraction fSum, fDifference, fProduct, fQuotient, //f for fraction 
  userInput; 

  //list that will contain extracted numerator and denominator
  int *fInput = new int(2);

  char a_or_b;

  cout<<"\nThis is a fraction calculator. Use the format:"<<endl
  <<"<a or b> = <fraction> (e.g. a = 1/2, b = 2)"<<endl<<
  "Type anything else to stop. Have fun!"<<endl;

  while(true)
  {
    cout<<"\na = "<<a<<"   " <<"b = "<<b<<endl;
  
    fSum=a+b;
    fDifference=a-b;
    fProduct=a*b;
    fQuotient=a/b;

    cout<<"a + b = "<<fSum << "   " << "a - b = "<<fDifference<< "   " << "a * b = "<<fProduct<< "   " << "a / b = "<<fQuotient<< "   ";

    cout <<"\n> ";

    //extracts which fraction to change value
    cin >> a_or_b;

    //extracts the value of the inputted function
    fInput = (cin>>userInput);

    //puts the values to the specified fraction 
    if (a_or_b=='a')
    {
      a=Fraction(fInput[0], fInput[1]);
    }
    else if (a_or_b=='b')
    {
      b=Fraction(fInput[0], fInput[1]);
    }
  }
  cout<<"Thanks for using our fraction calculator!"<<endl;
  return 0;
}
