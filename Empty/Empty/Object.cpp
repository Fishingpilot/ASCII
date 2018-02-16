#include "Object.h"
#include "Resources.h"

Object::Object(COORD _position, unsigned int _texture_id)
{
	position = _position;
	texture = _texture_id;
}

void Object::Update(float _delta_time)
{
	//Increase the velocity timer by deltatime * speed(velocity)
	velocityTimer.x += velocity.x * _delta_time;
	velocityTimer.y += velocity.y * _delta_time;
	//Move its X coord on the grid by 1 if the timer exceeds 1f or -1f
	if (velocityTimer.x > 1.f)
	{
		++position.X;
		velocityTimer.x -= 1.f;
	}
	else if (velocityTimer.x < -1.f)
	{
		--position.X;
		velocityTimer.x += 1.f;
	}
	//Same for Y coord
	if (velocityTimer.y > 1.f)
	{
		++position.Y;
		velocityTimer.y -= 1.f;
	}
	else if (velocityTimer.y < -1.f)
	{
		--position.Y;
		velocityTimer.y += 1.f;
	}
}

void Object::Draw(Resource* _resource)
{
	_resource->Draw(texture, position);
}