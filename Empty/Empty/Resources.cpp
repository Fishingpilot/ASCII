#include "Resources.h"
#include "Globals.h"
#include <fstream>

Resource* Resource::instance = nullptr;

Resource* Resource::GetInstance()
{
	return instance;
}

Resource::Resource(CHAR_INFO* _buffer)
{
	if (instance == nullptr)
		instance = this;
	else
		throw;

	buffer = _buffer;
}

Resource::~Resource()
{
	for (unsigned int i = 0; i < utfImages.count; ++i)
	{
		delete utfImages[i].text;
	}
}

void Resource::AddImage(const char* _file_path, unsigned int _id)
{
	CHAR_INFO* temp;
	COORD size = { 0,1 };
	char first, last, state;

	std::fstream file;
	file.open(_file_path, std::ios::in | std::ios::binary);
	file.seekg(0, std::ios::end);
	//every character is 3 bytes, so divide the width by 3
	size.X = file.tellg();
	size.X /= 3;
	//Its slighty oversized, worst case we are wasting (189) bytes
	temp = new CHAR_INFO[size.X];
	//Go back to the beginning
	file.seekg(0, std::ios::beg);
	for (int i = 0;; ++i)
	{
		//Read 3 bytes (first half of the char / second half of the char / attributes - foreground and background color)
		file >> std::noskipws >> first;
		file >> std::noskipws >> last;
		file >> std::noskipws >> state;
		if (first == 0 && last == 0)
			break;
		//Turn those 2 bytes into a 16bit Character
		short char16 = last;
		char16 = char16 << 8;
		char16 += first;
		//See if we hit a newline
		if (char16 == 0x0A)
		{
			--size.X;
			++size.Y;
			--i;
			continue;
		}
		//Finally put that character in our array
		temp[i].Char.UnicodeChar = char16;
		temp[i].Attributes = state;
	}
	//divide the width by the height to get the real width
	size.X /= size.Y;

	file.close();

	utfImages.Push(UTFImage{ _id, temp, size });
}

void Resource::Draw(unsigned int _id, _COORD _position, unsigned char _rotation_state, bool _center)
{
	unsigned int index = 0xFFFFFFFF;
	//Find the AscII art we loaded earler
	for (unsigned int i = 0; i < utfImages.count; ++i)
	{
		if (utfImages[i].id == _id)
		{
			index = i;
			break;
		}
	}
	//we didnt find the ascII art
	if (index == 0xFFFFFFFF)
		return;
	//Some things that are useful to have calculated
	SHORT totalsize = utfImages[index].size.X * utfImages[index].size.X;
	COORD halfsize;
	COORD charPosition;
	halfsize.X = utfImages[index].size.X / 2;
	halfsize.Y = utfImages[index].size.Y / 2;
	//Try to draw it from the center, wont work perfectly for even numbered sizes
	if (_center)
	{
		//X Loop
		for (SHORT i = 0; i < utfImages[index].size.X; ++i)
		{
			charPosition.X = (i - halfsize.X + _position.X);
			//If the object is out of the buffers dimensions dont draw it
			if (charPosition.X > BUFFER_DIMENSION)
				continue;
			else if (charPosition.X < 0)
				continue;
			//Y Loop
			for (SHORT y = 0; y < utfImages[index].size.Y; ++y)
			{
				charPosition.Y = (y - halfsize.Y + _position.Y);
				//Same for the Y
				if (charPosition.Y > BUFFER_DIMENSION)
					continue;
				else if (charPosition.Y < 0)
					continue;
				buffer[charPosition.X + (BUFFER_DIMENSION * charPosition.Y)] = (*utfImages[index].text);
			}
		}
	}
	else
	{
		for (SHORT i = 0; i < utfImages[index].size.X; ++i)
		{
			for (SHORT y = 0; y < utfImages[index].size.Y; ++y)
			{
				buffer[i + _position.X + ((BUFFER_DIMENSION * y) + _position.Y)];
			}
		}
	}
}