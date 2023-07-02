/**

*File Name: Begin with "proj" and then the assignment number, for example, proj1.cpp, or proj1.h. You must have the extension .cpp or .h

*Academic Integrity Statement: I certify that, while others may have assisted me in brainstorming, debugging, and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual it could also result in zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural GuidelinesLinks to an external site. at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelinesLinks to an external site.

*Assisted by and Assisted line numbers:

*Your Name: jacob harkins
*Your PSU user ID:  jah6863
*Course title (e.g. CMPSC122 Summer 2023)
*Due Time: Time, Day-of-week, Month Day, Year
*Time of Last Modification: Time, Day-of-week, Month Day, Year
*Description: The code runs a guessing game in which either a player or computer can guess numbers between 101 and 200.
*/

#include <iostream>
#include <cstdlib>  
#include <ctime>    
using namespace std;

bool checker(int cnumber, int cguess);

int main()
{
    int targetnum, newguess, guess;
    string mode;                                                                                
    cout << "Would you like to (p)lay or watch the (c)omputer play?" << endl;
    cin >> mode;
    START:
    int bounds[2] = { 101, 200 };
    srand(unsigned(time(0)));
    guess = bounds[0] + (rand() % (bounds[1] - bounds[0]));
    targetnum = bounds[0] + (rand() % (bounds[1]-bounds[0]));
    cout << targetnum << endl;
    do {
        if (mode == "p") {
            cout << "Enter your guess in between " << bounds[0] << " and " << bounds[1] << "." << endl;
            cin >> guess;
        }
        else if (mode == "c") {
            newguess = (targetnum > guess) ? (bounds[1] + guess)/2: (bounds[0] + guess)/2;
            if (targetnum > guess) { bounds[0] = guess; }
            if (targetnum < guess) { bounds[1] = guess; }
            guess = newguess;
            cout << "The computer's guess is " << guess << endl;
        }
        string result = (checker(targetnum, guess) ? "Congrats, you guessed the correct number, " : (targetnum > guess) ? "Sorry, your guess is too low, try again." : "Sorry, your guess is too high, try again.");
        cout << result << endl;
    } while (!checker(targetnum, guess));
    cout << "Would you like to (p)lay, watch the (c)omputer play, or (q)uit?" << endl;
    cin >> mode;
    if (mode == "q") {
        return 0;
    }
    else {
        goto START;
    }
}

bool checker(int ctarget, int cguess) {
    return (ctarget == cguess);
}

/*
Would you like to (p)lay or watch the (c)omputer play?
p
183
Enter your guess in between 101 and 200.
150
Sorry, your guess is too low, try again.
Enter your guess in between 101 and 200.
190
Sorry, your guess is too high, try again.
Enter your guess in between 101 and 200.
183
Congrats, you guessed the correct number,
Would you like to (p)lay, watch the (c)omputer play, or (q)uit?
c
142
The computer's guess is 142
Congrats, you guessed the correct number,
Would you like to (p)lay, watch the (c)omputer play, or (q)uit?
c
157
The computer's guess is 146
Sorry, your guess is too low, try again.
The computer's guess is 168
Sorry, your guess is too high, try again.
The computer's guess is 157
Congrats, you guessed the correct number,
Would you like to (p)lay, watch the (c)omputer play, or (q)uit?
q

C:\Users\liqui\source\repos\Project1\Debug\Project1.exe (process 10624) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/