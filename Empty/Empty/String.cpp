#include "String.h"

String::String(unsigned int _size)
{
	string = new char[_size];
	string[0] = 0;

	count = 0;
}

String::~String()
{
	delete[] string;
}

char* String::Chr()
{
	return string;
}

void String::ToLower()
{
	//Sets all 'letter' characters to their uppercase counterparts
	for (int i = 0; ; ++i)
	{
		if (string[i] == 0)
			break;

		if (string[i] >= 65 && string[i] <= 90)
			string[i] += 32;
	}
}

void String::ToUpper()
{
	//Sets all 'letter' characters to their lowercase counterparts
	for (int i = 0; ; ++i)
	{
		if (string[i] == 0)
			break;

		if (string[i] >= 97 && string[i] <= 122)
			string[i] -= 32;
	}
}

void String::NumberToString(int _value)
{
	unsigned int temp = 0;
	int otherValue = _value;
	//Find the numbers length in digits
	for (; otherValue != 0; ++temp)
	{
		otherValue /= 10;
	}
	//set the end of the number string to 0
	string[temp] = 0;
	//Then loop through and set each digit to a char in reverse order
	for (unsigned int i = temp - 1;; --i)
	{
		string[i] = (_value % 10) + 48;
		_value /= 10;
		if (_value == 0)
			break;
	}
	count = temp;
}

int String::StringToNumber()
{
	int temp = 0;
	int multi = 1;
	//We are counting backwards
	for (int i = count; i >= 0; --i)
	{
		//We drop all characters that aren't numbers
		if (string[i] >= 48 && string[i] <= 57)
		{
			//Convert the remaining string to a number
			temp += (string[i] - 48) * multi;
			multi *= 10;
		}
	}

	return temp;
}

bool String::Contains(const String& _other)
{
	return Contains(_other.string);
}

bool String::Contains(const char* _other)
{
	int y = 0;
	for (int i = 0; ; ++i)
	{
		//if the string ends before we find what we want we break out
		if (string[i] == 0)
			break;
		//the first character of the string we want to find has been found
		if (_other[y] == string[i])
		{
			++y;
			//now loop to check the rest of the characters
			for (;; ++y)
			{
				if (_other[y] == 0)
					return true;	//All characters are contained within the string
				else if (_other[y] != string[i + y])
				{
					y = 0;
					break;	//Try again with the next character in our main string
				}
			}
		}
	}
	return false;
}

String& String::operator=(const String& _rhs)
{
	for (int i = 0; ; ++i)
	{
		string[i] = _rhs.string[i];

		if (_rhs.string[i] == 0)
		{
			count = i;
			break;
		}
	}
	return *this;
}

String& String::operator+(const String& _rhs)
{
	for (unsigned int i = count;; ++i)
	{
		string[i] = _rhs.string[i - count];

		if (_rhs.string[i - count] == 0)
		{
			count = i;
			break;
		}
	}

	return *this;
}

String& String::operator=(const char* _rhs)
{
	for (int i = 0; ; ++i)
	{
		string[i] = _rhs[i];

		if (_rhs[i] == 0)
		{
			count = i;
			break;
		}
	}
	return *this;
}

String& String::operator+(const char* _rhs)
{
	for (unsigned int i = count;; ++i)
	{
		string[i] = _rhs[i - count];

		if (_rhs[i - count] == 0)
		{
			count = i;
			break;
		}
	}

	return *this;
}

bool String::operator==(const String& _rhs)
{
	for (int i = 0; ; ++i)
	{
		if (string[i] != _rhs.string[i])
			return false;
		else if (string[i] == 0 && _rhs.string[i] == 0)
			return true;
		else if (string[i] == 0 || _rhs.string[i] == 0)
			return false;
	}
	throw;
}

bool String::operator==(const char* _rhs)
{
	for (int i = 0; ; ++i)
	{
		if (string[i] != _rhs[i])
			return false;
		else if (string[i] == 0 && _rhs[i] == 0)
			return true;
		else if (string[i] == 0 || _rhs[i] == 0)
			return false;
	}
	throw;
}