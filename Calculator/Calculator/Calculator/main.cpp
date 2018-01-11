#include "stdafx.h"
#include "Calculator.h"
#include <iostream>
#include <string>

using namespace std;

void intro();
void getOperator(char &Operator); // Using references here for practice purposes. 
void getNum(float &a, float &b); // I probably wouldn't use references in a real calculator program.
void displayResult(float a, float b, float result, char Operator);

bool isRepeat();
bool isValidOperator(char Operation);
bool isValidNum(string num);


int main()
{
	float a, b;
	float result;
	char Operator;

	bool Repeat = false;
	
	intro();
	do {
	    getOperator(Operator);
		getNum(a, b);
		Calculator calculator(a, b, Operator);
		result = calculator.getResult();
		displayResult(a, b, result, Operator);
		Repeat = isRepeat();
	} while (Repeat);

	return 0;
}

void intro()
{
	cout << "Welcome to the C++ Calculator program!\n"
		<< "This program will ask for an operator like +,-,*, or /\n"
		<< "As well as ask for two numbers for the operation.\n"
		<< endl;
	return;
}

void getOperator(char &Operator)
{
	// Using strings to account for user error, I.E. if the user entered "asdf"
	string Operation;

	do {
		cout << "Enter an operator I.E. ( +  -  *  /):   ";
		getline(cin, Operation);
	} while (!isValidOperator(Operation[0]));	
	Operator = Operation[0];
	return;
}

void getNum(float &a, float &b)
{
	string num1, num2;

	do {
		cout << "\nEnter the first number:  ";
		getline(cin, num1);
		cout << "\nEnter the second number:  ";
		getline(cin, num2);
	} while (!isValidNum(num1) || !isValidNum(num2));
	a = strtof((num1).c_str(), 0); // converts string to float
	b = strtof((num2).c_str(), 0);
	return;
}

void displayResult(float a, float b, float result, char Operator)
{
	cout << '\n' << a << ' ' << Operator << ' ' << b << " = " << result << endl;
}

bool isRepeat()
{
	string Response = "";
	std::cout << "\nDo you want to make another calculation (y/n)?  ";
	std::getline(std::cin, Response);
	std::cout << std::endl;
	return (tolower(Response[0]) == 'y');
}

bool isValidOperator(char Operation)
{
	if (Operation == '+' || Operation == '-' || Operation == '*' || Operation == '/')
	{
		return true;
	}
	else
	{
		cout << "\nERROR: Invalid input. Valid operators are: +, -, *, /\n" << endl;
		return false;
	}
}

bool isValidNum(string num)
{
	for (auto digit : num)
	{
		if (isalpha(digit))
		{
			cout << "ERROR: " << num << " is invalid." << endl;
			return false;
		}
	}
	return true;
}
