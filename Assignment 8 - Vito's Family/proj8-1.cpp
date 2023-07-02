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
#include <stack>
using namespace std;


int getSumDist(stack<int> houses, int vitoHouse) {
    int dist = 0;
        while (!houses.empty()) {
            dist += abs(houses.top() - vitoHouse);
            houses.pop();
        }
        return dist;
}

int main() {
    stack<int> houses;
    int j, inputs, total, vitoHouse, dist, count = 1, temp;
    cout << "Number of test case(s): ";
    cin >> inputs;
    for (; inputs; inputs--, count++) {
        temp = 0;
        houses = stack<int>();
        cout << endl << endl << "Test case #" << count ;
        cout << endl << "Number of relatives: " ;
        cin >> total;
        cout << "Street numbers: ";
        for (int i = 1; i <= total; i++) {
            cin >> j;
            houses.push(j);
            temp += j;
        }
        vitoHouse = int(temp / float(total) + .5);
        cout << "Optimal Vito's house number: " << vitoHouse << endl;
        dist = getSumDist(houses, vitoHouse);
        cout << "The minimum sum of distances: " << dist << endl;
    }
    return 0;
}


/*
Number of test case(s): 2


Test case #1
Number of relatives: 2
Street numbers: 2 4
Optimal Vito's house number: 3
The minimum sum of distances: 2


Test case #2
Number of relatives: 3
Street numbers: 2 4 6
Optimal Vito's house number: 4
The minimum sum of distances: 4

*/



