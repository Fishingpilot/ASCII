#pragma once

template<typename T>
struct Vector
{
	unsigned int length;
	unsigned int count;
	T* vector;

	Vector(unsigned int _array_size)
	{
		vector = new T[_array_size];
		count = 0U;
		length = _array_size;
	}

	void Delete(unsigned int _index)
	{
		if (_index != (count - 1U))
		{
			vector[_index] = vector[count - 1U];
			--count;
		}
		else
		{
			--count;
		}
	}

	unsigned int Find(T &_object)
	{
		return -1U;
	}

	T& operator[](unsigned int _index)
	{
		return vector[_index];
	}
};