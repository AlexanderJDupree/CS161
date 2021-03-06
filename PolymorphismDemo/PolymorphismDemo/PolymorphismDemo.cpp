// PolymorphismDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int GetSize(int x)
{
	return x;
}

int GetSize(std::string x) // Overloads the Getsize to also deal with string type
{
	return x.length();
}

class Animal // parent animal class
{
public:
	virtual void makeNoise() // use virtual so the child classes to override the function
	{
		std::cout << "Animal Noise" << std::endl;
	}
};

class Dog : public Animal // child Dog class, inherits from animal
{
public:
	void makeNoise() override
	{
		std::cout << "Woof" << std::endl;
	}
};

class Cat : public Animal // child cat class inherits from animal
{
public:
	void makeNoise() override
	{
		std::cout << "Meow" << std::endl;
	}
};

void Stroke(Animal* animal) // this function will also word to for dog and cat classes because of inheritence
{
	animal->makeNoise();
}

int main()
{
	std::cout << GetSize(5) << std::endl;
	std::cout << GetSize("hello world") << std::endl;
	Dog dog;
	Cat cat;
	Stroke(&dog); // need reference to memory  because stroke is a pointer to animal class
	Stroke(&cat);
    return 0;
}

