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
#include <fstream>
#include <stack>
#include <queue>
using namespace std;

bool isPossible(int len, queue<int> cars) {
    stack<int> station;
    int right = 1, target;
    for (int i = 0; i < len; i++) {
        target = cars.front();
        cars.pop();
    START:
        if (!station.empty() && target == station.top()) {
            station.pop();
        }
        else if (right <= len && right == target) {
            right++;
        }
        else if (right > len) {
            return false;
        }
        else {
            station.push(right);
            right++;
            goto START;
        }
    }
    return true;
}


int main() {
    ifstream input;
    input.open ("A7in3.txt");
    ofstream output;
    output.open ("A7output.txt");
    int length;
    input >> length;
    while (length > 0) {
        queue<int> trains;
        int car;
        input >> car;
        if (car == 0) {
            input >> length;
            continue;
        }
        trains.push(car);
        for (int i = 1; i < length; i++) {
            input >> car;
            trains.push(car);
        }
        output << (isPossible(length, trains) ? "Yes" : "No") << endl;
    }
    input.close();
    output.close();
    return 0;
}

/*
No
Yes
No
No
No
Yes
Yes
*/