/********************************************************************************
**Program: pp8_2.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Project 8.2. Has a class for 
rational number and allows for overloaded operators to deal with objects of
the Rational class.
**Input: I couldn't quite figure out getting the input >> overload to work with
someone inputting a fraction as "4/5" and not as the integers 4 and 5.
**Output: An overloaded << function outputs the numerator and denominator of an
object in the form: "numerator/denominator"
********************************************************************************/
/*2. Define a class for rational numbers. A rational number is a number that can be
represented as the quotient of two integers. For example, 1/2, 3/4, 64/2, and so
forth are all rational numbers. (By 1/2 and so on we mean the everyday fraction, not
the integer division this expression would produce in a C++ program.) Represent
rational numbers as two values of type int , one for the numerator and one for
the denominator. Call the class Rational . Include a constructor with two arguments
that can be used to set the member variables of an object to any legitimate
values. Also include a constructor that has only a single parameter of type int ;
call this single parameter wholeNumber and define the constructor so that the
object will be initialized to the rational number wholeNumber /1. Include a default
constructor that initializes an object to 0 (that is, to 0/1). Overload the input and
output operators >> and << . Numbers are to be input and output in the form
1/2 , 15/32 , 300/401 , and so forth. Note that the numerator, the denominator, or
both may contain a minus sign, so -1/2 , 15/-32 , and -300/-401 are also possible
inputs. Overload all the following operators so that they correctly apply to the type
Rational : == , < , <= , > , >= , + , - , * , and / . Write a test program to test your class.
Hints: Two rational numbers a/b and c/d are equal if a*d equals c*b. If b and d are
positive rational numbers, a/b is less than c/d provided a*d is less than c*b . You
should include a function to normalize the values stored so that, after normalization,
the denominator is positive and the numerator and denominator are as small
as possible. For example, after normalization 4/-8 would be represented the same
as -1/2.*/

#include <iostream>
#include <string>

using namespace std;

class Rational
{
public:
	Rational (int num1, int den1);
	Rational (int wholeNumber);
	Rational ( );

	friend const Rational operator+(const Rational&, const Rational&);
	friend const Rational operator-(const Rational&, const Rational&);
	friend bool operator==(const Rational&, const Rational&);
	friend bool operator<(const Rational&, const Rational&);
	friend bool operator>(const Rational&, const Rational&);
	friend bool operator>=(const Rational&, const Rational&);
	friend bool operator<=(const Rational&, const Rational&);
	friend const Rational operator*(const Rational&, const Rational&);
	friend const Rational operator/(const Rational&, const Rational&);
	friend ostream& operator<<(ostream &outs, const Rational&);
	// friend istream& getline(istream &in, Rational&, char delim);

private:
	int numerator;
	int denominator;

	string snumerator;
	string sdenominator;
};

int main( )
{
	Rational test(3, 4);
	Rational test2(3, 6);
	cout << "Frac1 = " << test << endl;
	cout << "Frac2 = " << test2 << endl;
	cout << test << " + " << test2 << " = " << (test + test2) << endl;
	cout << test << " - " << test2 << " = " << (test - test2) << endl;
	cout << test << " * " << test2 << " = " << (test * test2) << endl;
	cout << test << " / " << test2 << " = " << (test / test2) << endl;

	if(test == test2)
	{
		cout << test << " and " << test2 << " are equal.\n";
	}
	else {
		cout << test << " and " << test2 << " are not equal.\n";
	}

	if(test > test2)
	{
		cout << test << " is greater than " << test2 << endl;
	}
	else
	{
		cout << test << " is not greater than " << test2 << endl;	
	}

	if(test < test2)
	{
		cout << test << " is less than " << test2 << endl;
	}
	else {
		cout << test << " is not less than " << test2 << endl;
	}

	if(test >= test2)
	{
		cout << test << " is greater than or equal to " << test2 << endl;
	}
	else {
		cout << test << " is not greater than or equal to " << test2 << endl;
	}

	if(test <= test2)
	{
		cout << test << " is less than or equal to " << test2 << endl;
	}
	else {
		cout << test << " is not less than or equal to " << test2 << endl;
	}
	return 0;
}


Rational::Rational (int num1, int den1)
{
	if(den1 == 0) {
		cout << "The denominator cannot be equal to 0.";
	}
	else {
		numerator = num1;
		denominator = den1;
	}
}

Rational::Rational (int wholeNumber)
{
	numerator = wholeNumber;
	denominator = 1;
}

Rational::Rational( )
{
	snumerator = "0";
	sdenominator = "1";
	numerator = 0;
	denominator = 1;
}

const Rational operator+(const Rational& LHS, const Rational& RHS)
{
	return Rational(((LHS.numerator*RHS.denominator) + (LHS.denominator*RHS.numerator)),
		(LHS.denominator * RHS.denominator));
}

const Rational operator-(const Rational& LHS, const Rational& RHS)
{
	if(LHS.denominator == RHS.denominator) {
		if (LHS.numerator >= RHS.numerator) {
			return Rational((LHS.numerator - RHS.numerator), LHS.numerator);
		}
		else {
			return Rational((RHS.numerator - LHS.numerator), LHS.numerator);
		}
	}
	else {
		return Rational(((LHS.numerator*RHS.denominator)-(LHS.denominator*RHS.numerator)), 
			(LHS.denominator*RHS.denominator));
	}
}

bool operator==(const Rational& LHS, const Rational& RHS)
{
	//Two rational numbers a/b and c/d are equal if a*d equals c*b.
	return ((LHS.numerator*RHS.denominator) == (RHS.numerator*LHS.denominator));

}

bool operator<(const Rational& LHS, const Rational& RHS)
{
	//If b and d are positive rational numbers, a/b is less than c/d provided a*d is less than c*b
	return ((LHS.numerator*RHS.denominator) < (RHS.numerator*LHS.denominator));
}

bool operator>(const Rational& LHS, const Rational& RHS)
{
	return ((LHS.numerator*RHS.denominator) > (RHS.numerator*LHS.denominator));	
}

bool operator>=(const Rational& LHS, const Rational& RHS)
{
	return (((LHS.numerator*RHS.denominator) == (RHS.numerator*LHS.denominator)) ||
		((LHS.numerator*RHS.denominator) > (RHS.numerator*LHS.denominator)));
}

bool operator<=(const Rational& LHS, const Rational& RHS)
{
	return (((LHS.numerator*RHS.denominator) == (RHS.numerator*LHS.denominator)) ||
		((LHS.numerator*RHS.denominator) < (RHS.numerator*LHS.denominator)));
}

const Rational operator*(const Rational& LHS, const Rational& RHS)
{
	return Rational((LHS.numerator*RHS.denominator), (LHS.denominator*RHS.numerator));
}

const Rational operator/(const Rational& LHS, const Rational& RHS)
{
	return Rational((LHS.numerator*RHS.numerator), (LHS.denominator*RHS.denominator));
}

ostream& operator<<(ostream &outs, const Rational& outRational)
{
	outs << outRational.numerator << "/" << outRational.denominator;
	return outs;
}

// istream& operator>>(istream &in, Rational& inRational)
// {

// }

// istream& getline(istream &in, Rational& inRational, char delim)
// {
// 	getline(in, inRational.snumerator, '/');
// 	//getline(in, inRational.denominator);

// 	return in;
// }