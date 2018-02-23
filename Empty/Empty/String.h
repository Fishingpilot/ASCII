#pragma once

#include "Array.h"

class String
{
	unsigned int count;

	char* string;
public:
	String(unsigned int _size = 64U);
	~String();

	void ToLower();
	void ToUpper();

	//Output the string as a raw char*
	char* Chr();

	//Takes a number and converts it to a string
	void NumberToString(int _value);
	//Takes the string and returns it as a number
	int StringToNumber();

	//Does this string contain
	bool Contains(const String&);
	bool Contains(const char*);

	//If we need more room for a big string
	void Resize(unsigned int _required_size);

	//Time for some operator overloads
	String& operator=(const String&);
	String& operator+(const String&);
	String& operator=(const char*);
	String& operator+(const char*);

	bool operator==(const String& _rhs);
	bool operator==(const char* _rhs);
};