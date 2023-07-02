/**

*File Name: complexno.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brainstorming, debugging, and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual it could also result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural GuidelinesLinks to an external site. at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelinesLinks to an external site.

*Assisted by and Assisted line numbers:

*Your Name: jacob harkins
*Your PSU user ID:  jah6863
*Course title (e.g. CMPSC122 Summer 2023)
*Due Time: Time, Day-of-week, Month Day, Year
*Time of Last Modification: Time, Day-of-week, Month Day, Year
*Description: 
*/

#include <iostream>
#include <cstdlib>  
#include "complexnum.h"
using namespace std;

// Default constructor sets both components to 0.
Complexno::Complexno() {
	real = 0.0;
	complex = 0.0;
}
// Second constructor - creates a complex number of equal value to a real.
Complexno::Complexno(double r) {
	real = r;
	complex = 0.0;
}
// (1) --------------------------------- standard constructor ------------------
//Define standard constructor - sets both of the real and complex components based
Complexno::Complexno(double r, double c) {
	real = r;
	complex = c;
}
// Adds two complex numbers and returns the answer.
Complexno Complexno::add(const Complexno& num2) {
	Complexno answer;
	answer.real = real + num2.real;
	answer.complex = complex + num2.complex;
	return answer;
}
// (2) --------------------------------- subtract------------------
// Define sub to subtracts two complex numbers and returns the answer.
Complexno Complexno::sub(const Complexno& num2) {
	Complexno answer;
	answer.real = real - num2.real;
	answer.complex = complex - num2.complex;
	return answer;
}
// (3) --------------------------------- Multiply------------------
// Multiplies two complex numbers and returns this answer.
Complexno Complexno::mult(const Complexno& num2) {
	Complexno answer;
	answer.real = (real * num2.real) - (complex * num2.complex);
	answer.complex = (real * num2.complex) + (num2.real * complex);
	return answer;
}
// Negates a complex number.
Complexno Complexno::negate() {
	Complexno answer;
	answer.real = -real;
	answer.complex = -complex;
	return answer;
}
Complexno Complexno::div(const Complexno& num2) {
	Complexno answer;
	double a = real, b = complex, c = num2.real, d = num2.complex;
	answer.real = (a * c + b * d) / (c * c + d * d);
	answer.complex = (b * c - a * d) / (c * c + d * d);
	return answer;
}
Complexno Complexno::operator+ (const Complexno& num2) {
	return add(num2);
}
Complexno Complexno::operator- (const Complexno& num2) {
	return sub(num2);
}
Complexno Complexno::operator- () {
	return negate();
}
Complexno Complexno::operator* (const Complexno& num2) {
	return mult(num2);
}
Complexno Complexno::operator/ (const Complexno& num2) {
	return 1;
}
ostream& operator<<(ostream& out, Complexno& num2) {
	num2.shownum();
	return out;
}
// (4) --------------------------------- Magnitude ------------------
// Computes and returns the magnitude of a complex number.
double Complexno::magnitude() {
	return sqrt(real * real + complex * complex);
}
// (5) --------------------------------- Print ------------------
// Prints out a complex number in a readable format.
void Complexno::shownum() {
	cout << real << "+" << complex << "i";
}
// Reads in a complex number from the user.
void Complexno::enternum() {
	cout << "Enter the real part of the complex number : ";
	cin >> real;
	cout << "Enter the imaginary part of the complex number : ";
	cin >> complex;
}
// Displays the answer to a complex number operation.
void display(Complexno n1, Complexno n2, Complexno n3, char op) {
	n1.shownum();
	cout << " " << op << " ";
	n2.shownum();
	cout << " = ";
	n3.shownum();
	cout << endl;
}

/*
Welcome to the complex number calculator.

 Would you like to
1. Add 2 complex numbers.
2. Subtract 2 complex numbers.
3. Multiply 2 complex numbers.
4. Divide 2 complex numbers.
5. Find the magnitude of a complex number.
6. Negate a complex number
7. Quit

1
Enter the first complex number :
0.0+0.0iEnter the real part of the complex number : 1
Enter the imaginary part of the complex number : 1
Enter the second complex number :
Enter the real part of the complex number : 1
Enter the imaginary part of the complex number : 1
1.0+1.0i + 1.0+1.0i = 2.0+2.0i

 Would you like to
1. Add 2 complex numbers.
2. Subtract 2 complex numbers.
3. Multiply 2 complex numbers.
4. Divide 2 complex numbers.
5. Find the magnitude of a complex number.
6. Negate a complex number
7. Quit

1
Enter the first complex number :
1.0+1.0iEnter the real part of the complex number : 1
Enter the imaginary part of the complex number : 1
Enter the second complex number :
Enter the real part of the complex number : 1
Enter the imaginary part of the complex number : 1
1.0+1.0i + 1.0+1.0i = 2.0+2.0i

 Would you like to
1. Add 2 complex numbers.
2. Subtract 2 complex numbers.
3. Multiply 2 complex numbers.
4. Divide 2 complex numbers.
5. Find the magnitude of a complex number.
6. Negate a complex number
7. Quit

1
Enter the first complex number :
1.0+1.0iEnter the real part of the complex number : 1
Enter the imaginary part of the complex number : 1
Enter the second complex number :
Enter the real part of the complex number : 1
Enter the imaginary part of the complex number : 1
1.0+1.0i + 1.0+1.0i = 2.0+2.0i

 Would you like to
1. Add 2 complex numbers.
2. Subtract 2 complex numbers.
3. Multiply 2 complex numbers.
4. Divide 2 complex numbers.
5. Find the magnitude of a complex number.
6. Negate a complex number
7. Quit

7
You quit the calculator.

C:\Users\liqui\source\repos\Project4\Debug\Project4.exe (process 21660) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/