/**
*File Name: mystring.cpp
*Academic Integrity Statement: I certify that, while others may have assisted me in
brainstorming, debugging, and validating this program, the program itself is my own
work. I understand that submitting code which is the work of other individuals is a
violation of the course Academic Integrity Policy and may result in zero credit for
the assignment, or course failure and a report to the Academic Dishonesty Board. I
also understand that if I knowingly give my original work to another individual it
could also result in zero credit for the assignment, or course failure and a report
to the Academic Dishonesty Board. See Academic Integrity Procedural GuidelinesLinks
to an external site. at: https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-
integrity-procedural-guidelinesLinks to an external site.
*Assisted by and Assisted line numbers:
*Your Name: jacob harkins
*Your PSU user ID: jah6863
*Course title (e.g. CMPSC122 Summer 2023)
*Due Time: Time, Day-of-week, Month Day, Year
*Time of Last Modification: Time, Day-of-week, Month Day, Year
*Description: make functions to mimic standard C library string functions
*/

/******************************************************************************
 CMPSC122 Su Assignment: Project #11 -- sample driver
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "timer.h"
#include "Algorithms.h"
#include <functional>
#include <cmath>
#include <iomanip>
#include <format>
#define OS "Elementary OS"
#define Processor "Pentium 4"
#define Memory "1024mb DDR2"
#define ColorArgs(COLOR) Max_Subsequence_Sum_##COLOR, #COLOR " Algorithm"
#define Row(A, B , C) cout << setw(10) << A << " |" << setw(18) << B << " |"<< setw(12) << C << endl;
#define HR cout << " ===========================================" << endl;
#define Header Row("-Size-", "-Big O Estimate-", "-Runtime-")
#define SystemInfo cout << "System Information: " << endl << OS << endl << Processor << endl << Memory << endl;
#define FunHeader(A) cout << endl << setw(20) << "Analyzing " << A << endl; HR
using namespace std;


int getBigO(float ratio) {
	return round(log2(ratio));
}

void analyze(int (*foo)(const int A[], const int N), string color) {
	FunHeader(color)
	int size = 64, runtime = 0, result, mintime = 2, numruns = 0;
	int* vec;
	while ((runtime < mintime || numruns < 6) && runtime < 4000) {
		Timer T;
		vec = new int[size];
		srand((unsigned)time(0));
		for (int i = 0; i < size; i++) {
			vec[i] = rand() % 100 - 50;
		}
		T.start();
		result = foo(vec, size);
		T.stop();
		size = 2 * size;
		if (runtime > mintime) {
			if (numruns == 0) {
				Header
			}
			int bigOEstimate = getBigO(float(T.gettime())/float(runtime));
			Row(size, bigOEstimate, float(T.gettime())/1000)
			numruns++;
		}
		runtime = T.gettime();
	}
}

int main(){
	SystemInfo
	analyze(ColorArgs(Blue));
	analyze(ColorArgs(Green));
	analyze(ColorArgs(Red));
}

