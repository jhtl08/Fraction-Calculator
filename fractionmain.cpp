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

  cout <<"\nThis is a fraction calculator." << endl;
  cout <<"Format for Input" << endl;
  cout <<"<a or b> = <whole numeber/fraction>" << endl;
  cout <<"(e.g. a = 1/2, b = 2)" << endl;
  cout <<"Type anything else to stop. Have fun!"<<endl;

  int *fInput = new int(2);

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
    cin >> userInput;

    fInput = userInput.fraction();

    // cout << "variable or end: " << userInput.get_variable_or_end() << endl; 
    // cout << "numerator input: " << fInput[0] << endl;; //for testing, remove before submission
    // cout << "numerator input: " << fInput[1] << endl;; //for testing, remove before submission

    //sets the new value to their respective variable

    if (userInput.get_variable_or_end() == "stop")
    {
      break;
    }
    if (userInput.get_variable_or_end() == "a" || userInput.get_variable_or_end() == "b")
    {
      if (userInput.get_variable_or_end() == "a") 
      { //new value for a
        a = Fraction(fInput[0], fInput[1]);
      }
      if (userInput.get_variable_or_end() == "b")
      { //new value for b
        b = Fraction(fInput[0], fInput[1]);
      }
    }
    else
    {
      cout << "Invalid Input!" << endl;
    }
    cin.clear(); // prevent while loop from going crazy
  }
  cout<<"\nThanks for using our fraction calculator!"<<endl;
  return 0;
}