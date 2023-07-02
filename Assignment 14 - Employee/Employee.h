/*
* File: Employee.h
* Skeleton codes for Employee class definition.
*/
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include <string>
#include <iomanip>
using namespace std;

class Employee {
public:
	Employee(string theName, float thePayRate);
	string getName() const;
	float getPayRate() const;
	void setName(string theName);
	void setPayRate(float thePayRate);
	virtual float pay(float hoursWorked) const;
	virtual void print() const;
protected:
	string name;
	float payRate;
};

Employee::Employee(string theName, float thePayRate) {
	name = theName;
	payRate = thePayRate;
}

string Employee::getName() const {
	return name;
}

float Employee::getPayRate() const {
	return payRate;
}

inline void Employee::setName(string theName){
	name = theName;
}

inline void Employee::setPayRate(float thePayRate) {
	payRate = thePayRate;
}

float Employee::pay(float hoursWorked) const {
	return hoursWorked * payRate;
}

inline void Employee::print() const {
	cout << "Name: " << name << endl
		<< "Pay Rate: " << payRate << endl;
}
#endif /* not defined _EMPLOYEE_H */

/*
Their information and payments:
Name: Alex
Pay Rate: 25
Pay: 1000

Name: Beth
Pay Rate: 1200
Is salaried? Yes
Pay: 1200

Name: Cassie
Pay Rate: 1000
Is salaried? Yes
Department: Accounting
Compensation: 250
Pay: 1250

The employee information and payments after the updates:

Name: Alexander
Pay Rate: 50
Pay: 3000

Name: Elizabeth
Pay Rate: 1500
Is salaried? Yes
Pay: 1500

Name: Cassandra
Pay Rate: 1500
Is salaried? Yes
Department: Accounting
Compensation: 250
Pay: 1750

*/