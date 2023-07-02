// Program Description: The complexno class provides an abstract data type
// to deal with complex numbers. The program I have
// written simply demonstrates the functionality of
// the class. The class allows the user to add, subtract,
// multiply and divide complex numbers, as well as
// compute the value of a complex number to the power
// of a positive integer.
// You can paste your header part of the documentation and sample outputs in complexnum.h file
#include "complexnum.h" // please use this new header file name instead of complexno.h for assignment 4.
int main() {
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(1);
	Complexno n1 = Complexno(), n2 = Complexno(), n3 = Complexno();			//They weren't initialized ;)
	cout << "Welcome to the complex number calculator.\n";
	// Display menu options and read in the user's choice.
	int choice;
	while (true) {
		cout << "\n Would you like to\n";
		cout << "1. Add 2 complex numbers.\n";
		cout << "2. Subtract 2 complex numbers.\n";
		cout << "3. Multiply 2 complex numbers.\n";
		cout << "4. Divide 2 complex numbers.\n";
		cout << "5. Find the magnitude of a complex number.\n";
		cout << "6. Negate a complex number\n";
		cout << "7. Quit\n\n";
		cin >> choice;
		if (choice == 7) {
			cout << "You quit the calculator.\n";
			return (0);
		}
		// Read in the necessary complex numbers from the user.
		cout << "Enter the first complex number : \n" << n1;
		n1.enternum();
		if (choice < 5) {
			cout << "Enter the second complex number : \n";
			n2.enternum();
		}
		// Execute the appropriate choice.
		if (choice == 1) {
			n3 = n1 + n2;
			cout << n1 << " + " << n2 << " = " << n3 << endl;
		}
		else if (choice == 2) {
			n3 = n1 - n2;
			cout << n1 << " - " << n2 << " = " << n3 << endl;
		}
		else if (choice == 3) {
			n3 = n1 * n2;
			cout << n1 << " * " << n2 << " = " << n3 << endl;
		}
		else if (choice == 4) {
			n3 = n1 / n2;
			cout << n1 << " / " << n2 << " = " << n3 << endl;
		}
		else if (choice == 5) {
			cout << "|" << n1 << "| = " << n1.magnitude() << endl;
		}
		else if (choice == 6) {
			n3 = -n1;
			cout << "-" << n1 << " = " << n3 << endl;
		}
		else
			cout << "Sorry, that was not a valid choice. Please try it again:\n";
	}
	return 0;
}