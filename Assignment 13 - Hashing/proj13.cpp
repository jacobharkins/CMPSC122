/**
*File Name: proj13.cpp
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
#include <iostream>
#include <string>
#include <bitset>
using namespace std;



unsigned Hash1(const string& key, const int h_size){
    unsigned int value = 0;
    for (int i = 0; i < key.length(); i++)
        value = value*31 + key[i];
    return value % h_size;
}

unsigned Hash2(const string& key, const int h_size) {
    unsigned int value = 0;
    for (int i = 0; i < key.length(); i++)
        value = value * 31 + key[i];
    return value % h_size;
}

int main() {
    string str[5] = { "Hello" , "Goodbye", "World", "Yes", "No"};
    int size1 = 64, size2 = 71;
    for (int i = 0; i < 5; i++) {
        cout << bitset<6>{Hash1(str[i], size1)} << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << bitset<6>{Hash2(str[i], size2)} << endl;
    }
    return 0;
}



/*
a) SUM_(i=0)^(key.length()-1) (16*(value + key[i]) % h_size)
b) code:
#include <iostream>
#include <string>
#include <bitset>
using namespace std;



unsigned Hash(const string& key, const int h_size){
    unsigned int value = 0;
    for (int i = 0; i < key.length(); i++)
        value = (value + key[i]) * 16;
    return value % h_size;
}

int main() {
    string str[5] = { "Hello" , "Goodbye", "World", "Yes", "No"};
    int size = 64;
    for (int i = 0; i < 5; i++) {
        cout << bitset<6>{Hash(str[i], size)} << endl;
    }
    return 0;
}

output: 
110000
010000
000000
110000
110000

This is not a good hash function as multiplying by 16 ensures the output hash is a multiple of 16 and hence the last 4 digits will be 0.

c)SUM_(i=0)^(key.length()-1) (value*31 + key[i]) % h_size)
d)code:
#include <iostream>
#include <string>
#include <bitset>
using namespace std;



unsigned Hash(const string& key, const int h_size){
    unsigned int value = 0;
    for (int i = 0; i < key.length(); i++)
        value = value*31 + key[i];
    return value % h_size;
}

int main() {
    string str[5] = { "Hello" , "Goodbye", "World", "Yes", "No"};
    int size = 71;
    for (int i = 0; i < 5; i++) {
        cout << bitset<6>{Hash(str[i], size)} << endl;
    }
    return 0;
}

output:
101011
101101
101110
011001
101100

This function is better because it multiplies by 31 hence the function has an even distribution and is more fully mapped.
*/