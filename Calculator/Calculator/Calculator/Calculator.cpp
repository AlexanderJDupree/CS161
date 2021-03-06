

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include "Calculator.h"

// Initialize class members from constructor arguments by using a member initializer list
Calculator::Calculator(float Num1, float Num2, char Operation) 
	: m_Num1(Num1), m_Num2(Num2), m_Operator(Operation)  {}

float Calculator::getResult()
{
	switch (m_Operator)
	{
	case '+': return add(); break;
	case '-': return subtract(); break;
	case '*': return multiply(); break;
	case '/': try { return divide(); }
			  catch (const char* msg) {
				  std::cout << msg << std::endl;
				  return 0.0;
			  }; break; // catches division by zero error.
	default:
		// TODO report error
		break;
	}
}

float Calculator::add()
{
	return m_Num1 + m_Num2;
}

float Calculator::subtract()
{
	return m_Num1 - m_Num2;
}

float Calculator::multiply()
{
	return m_Num1 * m_Num2;
}

float Calculator::divide()
{
	if (m_Num2 == 0)
	{
		throw "Division by zero condition!";
	}
	return (m_Num1 / m_Num2);
}



