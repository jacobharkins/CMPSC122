#pragma once
// Program Description: This program makes use of a complex number class to
// execute several complex number operations. The user
// enters either one or two complex numbers, and the
// output of the appropriate mathematical function is
// shown in a readable format.
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>
using namespace std;
struct Complexno {
	double real;												// Stores real component of complex number
	double complex;												// Stores complex component of complex number
	Complexno();												// Default constructor
	Complexno(double r);										// Second constructor - creates a complex number of equal value to a real.
	Complexno(double r, double c);								// Standard constructor - sets both of the real and complex components based on parameters.
	Complexno add(const Complexno& num2);						// Adds two complex numbers and returns the answer.
	Complexno sub(const Complexno& num2);						// Subtracts two complex numbers and returns the answer.
	Complexno mult(const Complexno& num2);						// Multiplies two complex numbers and returns the answer.
	Complexno div(const Complexno& num2);						// Divides two complex numbers and returns the answer.
	Complexno negate();											// Negates a complex number
	Complexno operator+ (const Complexno& num2);				// Addition Operator
	Complexno operator- (const Complexno& num2);				// Subtraction Operator
	Complexno operator- ();										// Negation Operator
	Complexno operator* (const Complexno& num2);				// Multiplication Operator
	Complexno operator/ (const Complexno& num2);				// Division Operator
	double magnitude();											// Computes and returns the magnitude of a complex number.
	void shownum();												// Prints out a complex number in a readable format.
	void enternum();											// Reads in a complex number from the user.							
};
void display(Complexno n1, Complexno n2, Complexno n3, char op);// Displays the answer to a complex number operation.
ostream& operator<< (ostream& out, Complexno& num2);			// Output Operator
#endif

