#pragma once

template<typename T>
struct Queue
{
	T* vector;
	unsigned int back, front;
	unsigned int length;

	Queue(unsigned int _array_size = 25U)
	{
		vector = new T[_array_size];
		back = 0U;
		front = 0U;
		length = 0U;
	}

	T* Push(T _object)
	{
		if (back == length)
			back = 0U;
		vector[back] = _object;
		++back;

		return &vector[back];
	}

	void Pop()
	{
		if (front == back)
			throw;

		++front;

		if (front == length)
			front = 0U;
	}

	T* Front()
	{
		return &vector[front];
	}
};