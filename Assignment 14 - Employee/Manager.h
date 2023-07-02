/*
* File: manager.h
* Manager class definition. Manager inherits from Employee.
* In its class definition, we must list those things that
* are new in Manager (i.e., that are not inherited from
* Employee) and those things which we will redefine for a
* Manager.
*/


#ifndef _MANAGER_H
#define _MANAGER_H
#include "Employee.h"
class Manager : public Employee {
public:
	Manager(string theName, float thePayRate, bool isSalaried);							// Redefine how pay is calculated.
	virtual float pay(float hoursWorked) const;
	void setPayRate(float thePayRate);
	void setName(string theName);
	virtual void print() const;
protected:
	bool salaried;
};

Manager::Manager(string theName, float thePayRate, bool isSalaried) : Employee(theName, thePayRate){
	salaried = isSalaried;
}

float Manager::pay(float hoursWorked) const {
	return (salaried ? payRate : Employee::pay(hoursWorked));
}

inline void Manager::setPayRate(float thePayRate) { 
	payRate = thePayRate;
}

inline void Manager::setName(string theName) {
	name = theName;
}

inline void Manager::print() const {
	cout << "Name: " << name << endl
		<< "Pay Rate: " << payRate << endl
		<< "Is salaried? " << (salaried ? "Yes" : "No") << endl;
}

#endif																					/* not defined _MANAGER_H */
