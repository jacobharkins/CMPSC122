/*
* File: Supervisor.h
* Manager class definition. Supervisor inherits from Employee and Manager.
* In its class definition, we must list those things that
* are new in Manager (i.e., that are not inherited from
* Employee) and those things which we will redefine for a
* Manager.
*/
#ifndef _SUPERVISOR_H
#define _SUPERVISOR_H
#include <string>
#include "Employee.h"
#include "Manager.h"
using namespace std;

struct Supervisor : public Manager {
public:
	Supervisor(string theName, float thePayRate, bool isSalaried, string theDepartment, float theBonus);
	void setName(string theName);
	float pay(float hoursWorked) const;
	float getBonus();
	void setPayRate(float thePayRate);
	void print() const;
protected:
	string department;
	float bonus;
};

Supervisor::Supervisor(string theName, float thePayRate, bool isSalaried, string theDepartment, float theBonus) : Manager(theName, thePayRate, isSalaried) {
	department = theDepartment;
	bonus = theBonus;
}

inline void Supervisor::setName(string theName) {
	name = theName;
}

inline float Supervisor::pay(float hoursWorked) const {
	return ((salaried ? payRate : Employee::pay(hoursWorked)) + bonus);
}

void Supervisor::setPayRate(float thePayRate) {
	payRate = thePayRate;
}

float Supervisor::getBonus() {
	return bonus;
}

inline void Supervisor::print() const {
	cout << "Name: " << name << endl
		<< "Pay Rate: " << payRate << endl
		<< "Is salaried? " << (salaried ? "Yes" : "No") << endl
		<< "Department: " << department << endl
		<< "Compensation: " << bonus << endl;
}
#endif