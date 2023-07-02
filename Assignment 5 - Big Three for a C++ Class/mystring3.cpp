/**

*File Name: mystring3.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brainstorming, debugging, and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual it could also result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural GuidelinesLinks to an external site. at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelinesLinks to an external site.

*Assisted by and Assisted line numbers:

*Your Name: jacob harkins
*Your PSU user ID:  jah6863
*Course title (e.g. CMPSC122 Summer 2023)
*Due Time: Time, Day-of-week, Month Day, Year
*Time of Last Modification: Time, Day-of-week, Month Day, Year
*Description:
*/
//File: mystring3.h
// Implementation file for user-defined String class.
#include "mystring3.h"

String::String(){
	contents = new char[1];
	contents[0] = '\0';
	len = 0;
}

String::String(const char s[]){
	int i;
	for (i = 0; s[i] != '\0'; i++);
	contents = new char[i+1];
	len = i;
	for (; i >= 0; i--) {
		contents[i] = s[i];
	}
}

String::String(const String& str) {
	contents = new char[str.len + 1];
	len = str.len;
	for (int i = 0; i <= str.len; i++) {
		contents[i] = str.contents[i];
	}
}

String::~String() {
	delete[] contents;
}

void String::append(const String& str){
	int i;
	char* temp = new char[len + str.len + 1];
	for (i = 0; i < len; i++) {
		temp[i] = contents[i];
	}
	delete[] contents;
	contents = temp;
	for (i = 0; i < str.len; i++) {
		contents[len + i] = str[i];
	}
	contents[len + i] = '\0';
	len += i;
}

bool String::operator >(const String& str) const{
	for (int i = 0; i <= str.len; i++) {
		if(contents[i] != str[i]){
			return (contents[i] > str[i] ? 1 : -1);
		}
	}
	return 0;
}

bool String::operator <(const String& str) const{
	for (int i = 0; i <= str.len; i++) {
		if (contents[i] != str[i]) {
			return (contents[i] < str[i] ? 1 : -1);
		}
	}
	return 0;
}

String String::operator +=(const String& str){
	append(str);
	return *this;
}

String String::operator =(String str) {
	if (this != &str) {
		delete[] contents;
		contents = new char[str.len + 1];
		len = str.len;
		for (int i = 0; i <= str.len; i++) {
			contents[i] = str.contents[i];
		}
	}
	return *this;
}

void String::print(ostream& out) const{
	out << contents;
}

int String::length() const{
	return len;
}

char String::operator [](int i) const{
	if (i < 0 || i >= len) {
		cerr << "can't access location " << i << " of string \"" << contents << "\"" << endl;
		return '\0';
	}
	return contents[i];
}

ostream& operator<<(ostream& out, const String& s) {	// overload ostream operator "<<" - External!
	s.print(out);
	return out;
}

