#include "String.h"

String::String(unsigned int _size)
{
	string = new char[_size];
	string[0] = 0;
}

String::~String()
{
	delete string;
}

char* String::Chr()
{
	return string;
}

void String::ToLower()
{
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
	for (int i = 0; ; ++i)
	{
		if (string[i] == 0)
			break;

		if (string[i] >= 97 && string[i] <= 122)
			string[i] -= 32;
	}
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
		if (_other[y] == 0)
			return true;
		else if (string[i] == 0)
			break;

		if (_other[y] == string[i])
		{
			++y;
		}
		else if (y != 0)
		{
			y = 0;
		}
	}
	return false;
}

bool String::operator==(const String& _rhs)
{
	for (int i = 0; ; ++i)
	{
		if (this->string[i] != _rhs.string[i])
			return false;
		else if (this->string[i] == 0 && _rhs.string[i] == 0)
			return true;
		else if (this->string[i] == 0 || _rhs.string[i] == 0)
			return false;
	}
	throw;
}

bool String::operator==(const char* _rhs)
{
	for (int i = 0; ; ++i)
	{
		if (this->string[i] != _rhs[i])
			return false;
		else if (this->string[i] == 0 && _rhs[i] == 0)
			return true;
		else if (this->string[i] == 0 || _rhs[i] == 0)
			return false;
	}
	throw;
}

bool String::EqualTo(const char* _rhs)
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