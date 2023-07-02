#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
using namespace std;

struct WordInfo {
    string word;
    int count;
};

struct Tree {
    vector<WordInfo*> items;
    Tree();
    void Insert(string);
    void PrintTree(ofstream&);
private:
    void PrintRec(ofstream&, int);
};