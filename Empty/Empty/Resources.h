#pragma once

#include "Array.h"
#include <TxCoord.h>

struct UTFImage
{
	unsigned int id;
	_CHAR_INFO* text;
	_COORD size;
};

enum ROT_STATE : unsigned char
{
	D0 = 0U,
	D90 = 1U,
	D180 = 2U,
	D270 = 3U,
};

class Resource
{
public:
	enum T_ID : unsigned int
	{
		NOTHING = 0xFFFFFFFF,
		WHITE_SQUARE = 0,
	};
private:
	static Resource* instance;

	_CHAR_INFO* buffer;

	Vector<UTFImage> utfImages;

public:
	Resource(CHAR_INFO* _buffer);
	~Resource();

	static Resource* GetInstance();

	void AddImage(const char* _file_path, unsigned int _id);
	void* GetImage(unsigned int _id, _COORD& length);

	void Draw(unsigned int _id, _COORD _position, unsigned char _rotation_state = 0U, bool _center = true);
};