/*********************************************************************************
**Program: pp14_1.cpp
**Author: Holly Harmon
**Description: For Absolute C++ Programming Projects 14.1. Uses the Salaried-
Employee class from chapter 14 as the base class for the new class Administrator.
**Input: User can input the title, responsibility, and supervisor name of new
administrator objects, as well as their name, ssn, and salary.
**Output: Can call functions to print the administrator's information or print an
admin check, which includes their employee information as well as their admin
information.
*********************************************************************************/
#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//Combined the Employee class with the SalariedEmployee class so there
//only needed to be one base class for this program.
class SalariedEmployee
{
public:
	SalariedEmployee( ); //Sets name to "No name yet," ssn to "No number yet,"
	//salary = 0 and netPay = 0.
	SalariedEmployee (const string& theName, const string& theSsn,
								double theWeeklySalary);
	//Sets everything accordingly, netPay = 0.

	double getSalary( ) const;
	string getName( ) const;
	string getSsn( ) const;
	double getNetPay( ) const;
	
	void setSalary(double newSalary);
	void setName(const string& newName);
	void setSsn(const string& newSsn);
	void setNetPay(double newNetPay);
	
	void printCheck( );

protected:
	double salary; //weekly
	string name;
	string ssn;
	double netPay;

private:
	//empty
};

class Administrator : public SalariedEmployee
{
public:
	Administrator( );

	void setSupervisor(string newSuperName);
	void setAdminInfo();
	void print(); //Prints the admin information
	void printCheck();

private:
	string title; //Job title
	string responsibility; //Area of responsibility
	string superName; //Supervisor's name

};

int main()
{
	//Test code:
	// class Administrator holly;
	// holly.setAdminInfo();
	// holly.printCheck();
}

SalariedEmployee::SalariedEmployee( )
{
	name = "No name yet";
	ssn = "No number yet";
	netPay = 0;
	salary = 0;
}

SalariedEmployee::SalariedEmployee(const string& theName, const string& theNumber,
									 double theWeeklySalary)
{
	name = theName;
	ssn = theNumber;
	netPay = 0;
	salary = theWeeklySalary;
}

double SalariedEmployee::getSalary( ) const
{
	return salary;
}

void SalariedEmployee::setSalary(double newSalary)
{
	salary = newSalary;
}

string SalariedEmployee::getName( ) const
{
	return name;
}

string SalariedEmployee::getSsn( ) const
{
	return ssn;
}

double SalariedEmployee::getNetPay( ) const
{
	return netPay;
}

void SalariedEmployee::setName(const string& newName)
{
	name = newName;
}

void SalariedEmployee::setSsn(const string& newSsn)
{
	ssn = newSsn;
}

void SalariedEmployee::setNetPay(double newNetPay)
{
	netPay = newNetPay;
}

void SalariedEmployee::printCheck( )
{
	setNetPay(salary);
	cout << "\n________________________________________________\n";
	cout << "Pay to the order of " << getName( ) << endl;
	cout << "The sum of " << getNetPay( ) << " Dollars\n";
	cout << "_________________________________________________\n";
	cout << "Check Stub NOT NEGOTIABLE \n";
	cout << "Employee Number: " << getSsn( ) << endl;
	cout << "Salaried Employee. Regular Pay: " << salary << endl;
	cout << "_________________________________________________\n";

}

Administrator::Administrator( ) : SalariedEmployee( )
{
	title = "No title yet";
	responsibility = "No responsibility yet";
	superName = "No Supervisor name yet";
}

void Administrator::setSupervisor(string newSuperName)
{
	superName = newSuperName;
}

void Administrator::setAdminInfo()
{
	cout << "What is the Administrator's title? ";
	cin >> title;
	cout<< "What is the Administrator's area of responsibility? ";
	cin >> responsibility;
	cout << "Who is the Administrator's immediate Supervisor? ";
	cin >> superName;
}

void Administrator::print()
{
	cout << "Title: " << title << endl;
	cout << "Responsibility: " << responsibility << endl;
	cout << "Supervisor: " << superName << endl; 
}

void Administrator::printCheck()
{
	setNetPay(salary);
	cout << "\n________________________________________________\n";
	cout << "Pay to the order of " << getName( ) << endl;
	cout << "The sum of " << getNetPay( ) << " Dollars\n";
	cout << "_________________________________________________\n";
	cout << "Check Stub NOT NEGOTIABLE \n";
	cout << "Administrator Number: " << getSsn( ) << endl;
	print();
	cout << "Salaried Administrator. Regular Pay: " << salary << endl;
	cout << "_________________________________________________\n";
}