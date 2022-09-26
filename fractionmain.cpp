//fractionmain.cpp
//Members: Kyle Coloma, Jason Lorenzo, Paolo Ong
//Project 1 Fraction Calculator
//ENGG 31-N
//September 26, 2022

#include "fractionclass.h"

using namespace std;

int main()
{
  Fraction a = Fraction();
  Fraction b = Fraction();
  
  Fraction fSum, fDifference, fProduct, fQuotient, //f for fraction 
  userInput; //user input variable and value
  
  cout << "\n----------------------------------------------" << endl;
  cout << "        This is a Fraction Calculator!          " << endl;
  cout << "\nFormat for Input:" << endl;
  cout << "[Variable] = [Whole Number/Fraction]" << endl;
  cout << "\nExample: " << endl;
  cout << "a = 1/2 or b = 2" << endl;
  cout << "\n       Type 'stop' else to stop. Enjoy!     " << endl;
  cout << "----------------------------------------------" << endl;

  int *fInput = new int(2);

  while(true) 
  { //continously asks for a new input until the user wants to stop
    //prints the value of "a" and "b"
    cout << "\na = " << a <<"   ";
    cout << "b = "<< b << endl;
  
    fSum = a + b; //addition operation
    fDifference = a - b; //difference operation
    fProduct = a * b; //multiplication operation
    fQuotient = a / b; // division operation

    cout << "a + b = " << fSum << "   ";
    cout << "a - b = " << fDifference << "   ";
    cout << "a * b = " << fProduct << "   ";
    cout << "a / b = " << fQuotient << "   ";

    cout <<"\n> ";

    //asks for a user input in this format
    //Extraction operator is overloaded to extract the following
    //(1) Variable
    //(2) Equal Sign
    //(3) Numerator
    //(4) Vinculum
    //(5) Denominator
    cin >> userInput;

    //Access the new fraction or whole number value
    fInput = userInput.fractionAttributes();

    //user wants to stop using the fraction calculator
    if (userInput.get_variable_or_end() == "stop")
    {
      break;
    }
    if (userInput.get_variable_or_end() == "a" 
    || userInput.get_variable_or_end() == "b")
    { //sets the new value to their respective variable

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
    { // Invalid Input are input that does not follow the format
      cout << "Invalid Input!" << endl;
    }
    cin.clear(); // prevent while loop from going crazy
  }
  cout << "\n----------------------------------------------" << endl;
  cout << "  Thanks for using our Fraction Calculator!  "<<endl;
  cout << "----------------------------------------------\n" << endl;
  return 0;
}