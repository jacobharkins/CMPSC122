#pragma once
//File: mystring3.h
// Declaration file for user-defined String class.
#ifndef _MYSTRING_H
#define _MYSTRING_H
#define Zero 0
#include<iostream>
#include <cstring>
using namespace std;
struct String {
public:
	String();
	String(const char s[]);										// a conversion constructor
	String(const String& str);
	~String();
	void append(const String& str);
	bool operator >(const String& str) const;					// Relational operators
	bool operator <(const String& str) const;
	String operator +=(const String& str);
	String operator =(String str);
	void print(ostream& out) const;
	int length() const;
	char operator [](int i) const;								// subscript operator
private:
	char *contents;
	int len;
};
ostream& operator<<(ostream& out, const String& r);				// overload ostream operator "<<" - External!
#endif															/* not defined _MYSTRING_H */
