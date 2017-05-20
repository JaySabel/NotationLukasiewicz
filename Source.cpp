#include<iostream>
#include<iomanip>
#include"Pile.h"

using std::cout;
using std::cin;
using std::endl;

void printCode(code);
void DoOperator(char, Pile &);

int main()
{

	char choice, l_operator;
	double value;
	Pile theStack;

	do {

		cout << "************Welcome************" << endl;
		cout << "The Stack contains => "<<theStack.GetHowMuchElements()<<" elements" << endl;
		cout << "-1-Enter a number" << endl;
		cout << "-2-Enter a operator" << endl;
		cout << "-3- Remove the last insert value" << endl;
		cout << "-4- Remove all value in the Stack" << endl;
		cout << "-q-Exit" << endl;
		cout << "Yours choice => ";
		cin >> choice;

		switch (choice)
		{
		case '1':
			
			cout << endl << "Enter a value" << endl;
			cin >> value;
			cout << endl;

			printCode(theStack.push(value));

			theStack.printStack();

			break;
		case '2':
			
			cout << endl << "Enter a operator (+ - * /) => ";
			cin >> l_operator;
			cout << endl;

			if (theStack.GetHowMuchElements() >= 2)
				DoOperator(l_operator, theStack);
			else
				cout << "We need at least two numbers" << endl;

			theStack.printStack();

			break;
		case '3':

			printCode(theStack.pop());

			theStack.printStack();

			break;
		case '4':
				
			printCode(theStack.trashStack());

			theStack.printStack();

				break;
		case 'q':
			exit(0);
			break;
		default:
			break;

		}
	} while (choice != 'q');

	system("pause");
	return 0;
}

void DoOperator(char theOperator, Pile &thePile)
{
	double A, B, result = 0;

	// we call the function top and secondTop for have access to value becaus they are passed in reference
	thePile.top(A);
	thePile.secondTop(B);

	switch (theOperator)
	{
	case'+':

		result = A + B;
		cout << A << " + " << B << " = " << result << endl;
		printCode(thePile.push(result));

		break;
	case '-':

		result = A - B;
		cout << A << " - " << B << " = " << result << endl;
		printCode(thePile.push(result));

		break;
	case '*':

		result = A * B;
		cout << A << " * " << B << " = " << result << endl;
		printCode(thePile.push(result));

		break;
	case'/':

		if(B!=0)
		{
			result = A / B;
			cout << A << " / " << B << " = " << result << endl;
			printCode(thePile.push(result));
		}
		else
		{
			cout << "Error you can't divide by 0" << endl;
		}
		break;
	default:
		cout << "Wrong keyboard key" << endl;
		break;
	}

}

void printCode(code theCode)
{
	switch (theCode)
	{
	case Success:
		cout << endl << "******* Success **********" << endl << endl;
		break;
	case Empty:
		cout << endl << "******* Stack Empty **********" << endl << endl;
		break;
	case overload:
		cout << endl << "******* Stack Full **********" << endl << endl;
		break;
	}
}