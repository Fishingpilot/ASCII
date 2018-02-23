#include "Object.h"
#include "Resources.h"

Object::Object(COORD _position, unsigned int _texture_id)
{
	position = _position;
	texture = _texture_id;
	velocity.x = 10.f;
	velocity.y = 20.f;
	velocityTimer.x = 0.f;
	velocityTimer.y = 0.f;
}

void Object::Update(float _delta_time)
{
	//Increase the velocity timer by deltatime * speed(velocity)
	velocityTimer.x += velocity.x * _delta_time;
	velocityTimer.y += velocity.y * _delta_time;
	//Move its X coord on the grid by 1 if the timer exceeds 1f or -1f
	while (velocityTimer.x > 1.f || velocityTimer.x < -1.f)
	{
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
	}
	//Same for Y coord
	while (velocityTimer.y > 1.f || velocityTimer.y < -1.f)
	{
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

	//Just for fun
	if (position.X >= 62 && velocity.x > 0.f)
	{
		velocity.x *= -1;
		velocityTimer.x = 0;
	}
	else if (position.X <= 1 && velocity.x < 0.f)
	{
		velocity.x *= -1;
		velocityTimer.x = 0;
	}
	if (position.Y >= 62 && velocity.y > 0.f)
	{
		velocity.y *= -1;
		velocityTimer.y = 0;
	}
	else if (position.Y <= 1 && velocity.y < 0.f)
	{
		velocity.y *= -1;
		velocityTimer.y = 0;
	}
}

void Object::Draw(Resource* _resource)
{
	_resource->Draw(texture, position);
}