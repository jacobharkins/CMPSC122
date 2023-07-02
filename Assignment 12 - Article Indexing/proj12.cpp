/* File Name : proj7.cpp
* Academic Integrity Statement : I certify that, while others may have assisted me in
brainstorming, debugging, and validating this program, the program itself is my own
work.I understand that submitting code which is the work of other individuals is a
violation of the course Academic Integrity Policy and may result in zero credit for
the assignment, or course failure and a report to the Academic Dishonesty Board.I
also understand that if I knowingly give my original work to another individual it
could also result in zero credit for the assignment, or course failure and a report
to the Academic Dishonesty Board.See Academic Integrity Procedural GuidelinesLinks
to an external site.at:
https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-
integrity - procedural - guidelinesLinks to an external site.
* Assisted by and Assisted line numbers :
*Your Name : jacob harkins
* Your PSU user ID : jah6863
* Course title(e.g.CMPSC122 Summer 2023)
* Due Time : Time, Day - of - week, Month Day, Year
* Time of Last Modification : Time, Day - of - week, Month Day, Year
* Description :
*/
//File: proj12.cpp
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "tree.h"
using namespace std;



int main() {
    string line, str, ifilename, ofilename;
    Tree tree;
    ifstream inputfile;
    ofstream outputfile;
    cout << "Please type the text file name: ";
    cin >> ifilename;
    cout << endl << "Please give the output text file name: ";
    cin >> ofilename;
    inputfile.open(ifilename);
    while (getline(inputfile, line)) {
        istringstream line_stream(line);
        while (line_stream >> str) {
            if (ispunct(str[str.length() - 1])) {
                str.erase(str.length() - 1, 1);
            }
            if (str.length() >= 3) {
                tree.Insert(str);
            }
        }
    }
    inputfile.close();
    outputfile.open(ofilename);
    tree.PrintTree(outputfile);
    outputfile.close();
    return 0;
}

/*
                Word               Count
                1863                   1
             Address                   1
                 But                   1
                Four                   1
          Gettysburg                   2
                 God                   1
             Liberty                   1
            November                   1
                 Now                   1
        Pennsylvania                   1
                 The                   3
               above                   1
                 add                   1
            advanced                   1
                 ago                   1
                 all                   1
          altogether                   1
                 and                   6
                 any                   1
                 are                   3
        battle-field                   1
              before                   1
               birth                   1
               brave                   1
             brought                   1
                 but                   1
                 can                   5
               cause                   1
               civil                   1
                come                   1
           conceived                   2
          consecrate                   1
         consecrated                   1
           continent                   1
             created                   1
                dead                   3
            dedicate                   2
           dedicated                   4
             detract                   1
            devotion                   2
                 did                   1
                died                   1
               earth                   1
              endure                   1
             engaged                   1
               equal                   1
                 far                   2
             fathers                   1
               field                   1
               final                   1
             fitting                   1
                 for                   5
              forget                   1
               forth                   1
              fought                   1
             freedom                   1
                from                   2
                full                   1
                gave                   2
          government                   1
               great                   3
              ground                   1
              hallow                   1
                have                   5
                here                   8
              highly                   1
             honored                   1
           increased                   1
              larger                   1
                last                   1
              little                   1
                live                   1
               lives                   1
              living                   2
                long                   2
             measure                   1
                 men                   2
                 met                   1
               might                   1
              nation                   5
               never                   1
                 new                   2
               nobly                   1
                 nor                   1
                 not                   5
                note                   1
                 our                   2
              people                   3
              perish                   1
               place                   1
                poor                   1
             portion                   1
               power                   1
              proper                   1
         proposition                   1
              rather                   2
           remaining                   1
            remember                   1
             resolve                   1
             resting                   1
                 say                   1
               score                   1
               sense                   1
               seven                   1
               shall                   3
              should                   1
           struggled                   1
                take                   1
                task                   1
             testing                   1
                that                  13
                 the                   9
               their                   1
               these                   2
                they                   3
                this                   4
               those                   1
                thus                   1
               under                   1
          unfinished                   1
                vain                   1
                 war                   2
                what                   2
             whether                   1
               which                   2
                 who                   3
                will                   1
                work                   1
               world                   1
               years                   1

*/