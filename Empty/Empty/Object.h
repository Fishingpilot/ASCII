#pragma once

#include <TxCoord.h>

class Resource;
class Player;

template<typename T>
struct Vector2D
{
	T x, y;
};

class Object
{
	friend Player;
protected:
	COORD position;
	unsigned int texture;

	Vector2D<float> velocity;
	Vector2D<float> velocityTimer;

public:
	Object(COORD _position = COORD{ 0,0 }, unsigned int _texture_id = 0xFFFFFFFF);

	void Update(float _delta_time);
	void Draw(Resource* _resource);
};