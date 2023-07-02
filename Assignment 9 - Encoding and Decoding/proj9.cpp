/**

*File Name: proj7.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brainstorming, debugging, and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual it could also result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural GuidelinesLinks to an external site. at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelinesLinks to an external site.

*Assisted by and Assisted line numbers:

*Your Name: jacob harkins
*Your PSU user ID:  jah6863
*Course title (e.g. CMPSC122 Summer 2023)
*Due Time: Time, Day-of-week, Month Day, Year
*Time of Last Modification: Time, Day-of-week, Month Day, Year
*Description:
*/
//File: proj7.cpp
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>

using namespace std;

const int cinTerminator = -1;

ostream& operator<<(ostream& out, const vector<int>& number) {
	size_t size = number.size();
	for (size_t i = 0; i < size; i++) {
		out << number[i];
	}
	return out;
}

int main() {
	vector<int> oseq, sseq, useq;
	int count = 0, input, x = 0;
	bool compare = 0;
	while (cin >> input && input == 1 || input == 0) {
		oseq.push_back(input);
	}
	cout << "Original bit sequence:" << endl;
	for (auto i = oseq.begin(); i != oseq.end(); i++) {
		if (count == 5) {
			sseq.push_back(0);
			count = 0;
			x++;
		}
		if (count != 5 && *i) {
			count++;
		}
		else if (!*i) {
			count = 0;
		}
		sseq.push_back(*i);
		cout << *i;
	}
	cout << endl << "Bit-stuffed sequence:" << endl;
	for (auto i = sseq.begin(); i != sseq.end(); i++) {
		cout << *i;
	}
	cout << endl << "Relative expansion: " << int(float(x)/oseq.size()*100 + .5) << "%" << endl;
	cout << "Absolute expansion: " << x << " bit(s)" << endl;
	count = 0;
	for (auto i = sseq.begin(); i != sseq.end(); i++) {
		useq.push_back(*i);
		count++;
		if (count == 6) {
			useq.pop_back();
			count = 0;
		}
		if (count != 6 && useq.back() == 0) {
			count = 0;
		}
	}
	cout << "Unstuffed sequence:" << endl;
	for (auto i = useq.begin(); i != useq.end(); i++) {
		cout << *i;
	}
	cout << endl << "After bit-unstuffing: sequences are ";
	while (!oseq.empty() && !useq.empty()) {
		compare += oseq.back() - useq.back();
		oseq.pop_back();
		useq.pop_back();
	}
	cout << (compare ? "not equal" : "equal");
	return 0;
}