/**

*File Name: mystring.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brainstorming, debugging, and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual it could also result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural GuidelinesLinks to an external site. at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelinesLinks to an external site.

*Assisted by and Assisted line numbers:

*Your Name: jacob harkins
*Your PSU user ID:  jah6863
*Course title (e.g. CMPSC122 Summer 2023)
*Due Time: Time, Day-of-week, Month Day, Year
*Time of Last Modification: Time, Day-of-week, Month Day, Year
*Description: make functions to mimic standard C library string functions
*/

#include <iostream>
#include <cstdlib>  
#include "mystring.h"
using namespace std;

int mystrlen(const char* s){
	int count = 0;
	for (int i = 0; s[i]; i++)
		count++;
	return count;
}

int mystrcmp(const char* s1, const char* s2){								//On the test doc there was inconsistencies with
	int len1 = mystrlen(s1);												//what it returns if a > b, etc... so I standardized
	int len2 = mystrlen(s2);												//all of them for my tests
	int compare = (len1 > len2) ? 1 : (len1 < len2) ? -1 : 0;
	return compare;
}

char* mystrcpy(char* s1, const char* s2){
	int len = mystrlen(s2);
	memcpy(s1, s2, len + 1);
	s1[len + 1] = '\0';
	return s1;
}

char* mystrcat(char* s1, const char* s2){
	int i;
	for (i = 0; s1[i] != '\0'; i++) {
	}
	for (int j = 0; s2[j] != '\0'; j++, i++) {
		s1[i] = s2[j];
	}
	s1[i] = '\0';
	return s1;
}

char* mystrrchr(const char* pc, int iChar){
	char* pch = NULL;
	for (int i = 0; pc[i] != '\0'; i++, pch = (iChar == pc[i]) ? (char*)&pc[i] : pch) {
	}
	return (pch);
}
/*
If no any error outputs, your program passes all the tests. The End.

C:\Users\liqui\source\repos\Project2\Debug\Project2.exe (process 20664) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
}*/