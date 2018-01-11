#pragma once


class Calculator
{
public:

	Calculator(float Num1, float Num2, char Operator); // Constuctor

	float getResult();
	float add();
	float subtract();
	float multiply();
	float divide();

private:

	float m_Num1;
	float m_Num2;

	char m_Operator;

};