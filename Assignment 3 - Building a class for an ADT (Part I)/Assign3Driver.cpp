// Meng Su
// 9/7/22
// Program Description: This program makes use of a complex number class to
// execute several complex number operations. The user
// enters either one or two complex numbers, and the
// output of the appropriate mathematical function is
// shown in a readable format.
// You can paste your header part of the documentation and sample outputs in complexnum.h file
#include "complexno.h" // please use this new header file name instead of complexno.h for assignment 4.
void display(Complexno, Complexno, Complexno, char);
int main() {
	// Sets up output format.
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	Complexno n1, n2, n3;
	cout << "Welcome to the complex number calculator.\n";
	// Reads in user's menu choice.
	int choice;
	while (true) {
		cout << "Would you like to\n";
		cout << "1. Add 2 complex numbers.\n";
		cout << "2. Subtract 2 complex numbers.\n";
		cout << "3. Multiply 2 complex numbers.\n";
		cout << "4. Find the magnitude of a complex number.\n";
		cout << "5. Negate a complex number\n";
		cout << "6. Quit\n";
		cin >> choice;
		if (choice == 6) {
			cout << "You quit the calculator.\n";
			return (0);
		}
		// Reads in necessary complex numbers
		cout << "Enter the first complex number : \n";
		n1.enternum();
		if (choice < 4) {
			cout << "Enter the second complex number : \n";
			n2.enternum();
		}
		// Executes appropriate choice.
		if (choice == 1) {
			n3 = n1.add(n2);
			display(n1, n2, n3, '+');
		}
		else if (choice == 2) {
			// Must add negative of second number to first for subtraction.
			n3 = n1.sub(n2);
			display(n1, n2, n3, '-');
		}
		else if (choice == 3) {
			n3 = n1.mult(n2);
			display(n1, n2, n3, '*');
		}
		else if (choice == 4) {
			cout << "|";
			n1.shownum();
			cout << "| = " << n1.magnitude() << endl;
		}
		else if (choice == 5) {
			n3 = n1.negate();
			// Displays result.
			cout << "-";
			n1.shownum();
			cout << " = ";
			n3.shownum();
			cout << endl;
		}
		else
			cout << "Sorry, that was not a valid choice. Please try it again:\n";
	}
	return 0;
}
/* Please copy and paste your sample run as comments here:
* Welcome to the complex number calculator.
Would you like to
1. Add 2 complex numbers.
2. Subtract 2 complex numbers.
3. Multiply 2 complex numbers.
4. Find the magnitude of a complex number.
5. Negate a complex number
6. Quit
1
Enter the first complex number :
Enter the real part of the complex number : 2
Enter the imaginary part of the complex number : 3
Enter the second complex number :
Enter the real part of the complex number : 4
Enter the imaginary part of the complex number : 5
2.0+3.0i + 4.0+5.0i = 6.0+8.0i
*/