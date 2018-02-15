#pragma once

template<typename T>
struct Vector
{
	unsigned int length;
	unsigned int count;
	T* vector;

	Vector(unsigned int _array_size = 25U)
	{
		vector = new T[_array_size];
		count = 0U;
		length = _array_size;
	}

	T* Push(T _object)
	{
		if (count == length)
			Resize();

		vector[count] = _object;
		++count;

		return &vector[count - 1];
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
		for (int i = 0; i < count; ++i)
			if (vector[i] == object)
				return i;
		return -1U;
	}

	void Resize()
	{
		T* new_vector = new T[length * 2];
		for (unsigned int i = 0U; i < length; ++i)
		{
			new_vector[i] = vector[i];
		}
		delete vector;
		vector = new_vector;
		length *= 2U;
	}

	T& operator[](unsigned int _index)
	{
		return vector[_index];
	}
};