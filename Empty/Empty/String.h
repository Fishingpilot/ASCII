#pragma once

#include "Array.h"

class String
{
	char* string;
public:
	String(unsigned int _size = 64U);
	~String();

	void ToLower();
	void ToUpper();

	char* Chr();

	//Takes a number and converts it to a string
	void NumberToString(int _value);

	//Does this string contain
	bool Contains(const String&);
	bool Contains(const char*);

	String& operator=(const String&);
	String& operator+(const String&);
	String& operator=(const char*);
	String& operator+(const char*);

	bool operator==(const String& _rhs);
	bool operator==(const char* _rhs);
	//Debug
	bool EqualTo(const char*);
};