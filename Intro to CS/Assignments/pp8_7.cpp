/*7. Define a class named PrimeNumber that stores a prime number. The default constructor
should set the prime number to 1. Add another constructor that allows
the caller to set the prime number. Also, add a function to get the prime number.
Finally, overload the prefix and postfix ++ and -- operators so they return a
PrimeNumber object that is the next largest prime number (for ++) and the next
smallest prime number (for --). For example, if the object's prime number is set
to 13, then invoking ++ should return a PrimeNumber object whose prime number
is set to 17. Create an appropriate test program for the class.*/
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class PrimeNumber
{
public:
	PrimeNumber( );
	PrimeNumber(int prime1);

	int primeCheck(int prime1);
	int getPrime( );
	bool nextPrime( );

	PrimeNumber& operator++()
	{
		++(this->primeVar);
		return *this;
		// do {
		// 	int k = 0;
		// 	for(int i = 1; i <= *this; i++) {
		// 		if(*this % i == 0) {
		// 		k++;
		// 		}
		// 	}
		// 	if(k == 2) {
	 //    		return *this;
	 //    	}
	 //    	else
	 //    	{
		// 		++(this->primeVar);
		// 		int a = 0;
		// 	}
		// } while(a == 0);
	}

	// friend const  operator==(const Rational&, const Rational&);
	// friend const Rational operator<(const Rational&, const Rational&);
	// friend const Rational operator>(const Rational&, const Rational&);
	// friend const Rational operator>=(const Rational&, const Rational&);
	// friend const Rational operator<=(const Rational&, const Rational&);
	// friend const PrimeNumber operator++(const PrimeNumber&);
	// friend const PrimeNumber operator--(const PrimeNumber&);

private:
	int primeVar;
};

int main ( )
{
	int userPrime;

	cout << "What prime number would you like to start with? ";
	cin >> userPrime;
	
	PrimeNumber userVariable(userPrime);
	cout << userVariable.getPrime() << endl;

	++userVariable;
	int a = 0;
	do {
		
		int k = 0;
		for(int i = 1; i <= userVariable.getPrime(); i++) {
			if(userVariable.getPrime() % i == 0) {
				k++;
			}
		}
		if(k == 2) {
	   		return userVariable.getPrime();
	   	}
	   	else
	   	{
			++userVariable;
			a = 0;
		}
	} while(a == 0);

	cout << "The next Highest Prime is " << userVariable.getPrime();

	return 0;
}

// const PrimeNumber operator++(const PrimeNumber &nextPrime)
// {
// 	return PrimeNumber(++nextPrime.getPrime( ));
// }

PrimeNumber::PrimeNumber( )
{
	primeVar = 1;
}

PrimeNumber::PrimeNumber(int prime1)
{
	primeVar = primeCheck(prime1);
}

int PrimeNumber::getPrime( )
{
	return primeVar;
}

int PrimeNumber::primeCheck(int prime2)
{
	int a = 0;
	do {
		int k = 0;
		for(int i = 1; i <= prime2; i++) {
			if(prime2 % i == 0) {
				k++;
			}
		}
		if(k == 2) {
	    	return prime2;
	    }
	    else
	    {
			cout << "That is not a prime number, try again: ";
			cin >> prime2;
			a = 0;
		}
	}while(a == 0);
}
