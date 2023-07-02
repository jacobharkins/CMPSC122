#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "tree.h"
using namespace std;

#define left(x) ((x * 2) + 1)
#define right(x) ((x * 2) + 2)

Tree::Tree() {
    items.push_back(NULL);
}

void Tree::Insert(string str) {
    int current = 0;
    while (items[current]) {
        if (items.size() < right(current)) {
            items.resize(items.size() * 3);
        }
        if (items[current]->word == str) {
            items[current]->count++;
            return;
        }
        current = (str < items[current]->word ? left(current) : right(current));
    }
    items[current] = new WordInfo{ str, 1 };
}

void Tree::PrintTree(ofstream& out) {
    out << setw(20) << "Word" << setw(20) << "Count" << endl;
    PrintRec(out, 0);
}

void Tree::PrintRec(ofstream& out, int index) {
    if (items.size() <= index || !items[index]) {
        return;
    }
    PrintRec(out, left(index));
    out << setw(20) << items[index]->word << setw(20) << items[index]->count << endl;
    PrintRec(out, right(index));
}