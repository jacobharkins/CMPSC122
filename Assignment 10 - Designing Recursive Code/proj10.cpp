#include <iostream>
#include <unordered_map>
#include <string>
#include "Timer.h"
using namespace std;
typedef unsigned long long big;

struct Point {
	big x;
	big y;
};

unordered_map<big, big> hashmap;

bool operator==(Point& A, Point& B) {
	return (A.x == B.x && A.y == B.y);
}

big cantorPair(big x, big y) {											//Cantor pairing function
	return (x + y) * (x + y + 1) / 2 + x;
}

big rec(Point& start, Point& end) {
	if (start == end) {
		return 1;
	}
	if (start.y > end.y || start.x > end.x) {
		return 0;
	}
	big h = cantorPair(start.x, start.y);
	if (hashmap.find(h) != hashmap.end()) {
		return hashmap[h];
	}
	Point north = { start.x, start.y + 1 };
	Point east = { start.x + 1, start.y };
	hashmap[h] = rec(north, end) + rec(east, end);
	return hashmap[h];
}

int main() {
	Point start = { 0, 0 }, end;
	Timer timer;
	cout << "How many points north of A is B? ";
	cin >> end.y;
	cout << "How many points east of A is B? ";
	cin >> end.x;
	timer.start();
	cout << "There are " << rec(start, end) << " northeast paths between A and B." << endl;
	timer.stop();
	timer.show(); 
	return 0;
}