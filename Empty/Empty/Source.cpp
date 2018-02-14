#include "Array.h"
#include <iostream>

int BinarySearch(Vector<int>& , int, int&);

void main()
{
	Vector<int> intlist(2500);
	
	for (int i = 0; i < intlist.length; ++i)
	{
		intlist[i] = i * i;
		printf("%d ", intlist[i]);
	}
	intlist.count = intlist.length;
	
	int input;
	
	std::cout << "\n\nEnter number to find\n";
	std::cin >> input;
	
	int index, cycles;

	index = BinarySearch(intlist, input, cycles);
	if (index != -1)
	{
		std::cout << "Index: " << index << std::endl;
		std::cout << "Number: " << intlist[index] << std::endl;
		std::cout << "Iterations: " << cycles << std::endl;
	}
	else
	{
		std::cout << "Number was not found in the array.\nIterations: " << cycles << std::endl;
	}

	system("pause");
	//Error testing
	for (int i = 0; i < intlist.length; ++i)
	{
		index = BinarySearch(intlist, intlist[i], cycles);
		printf("Index: %d Number: %d Iterations: %d\n", index, intlist[index], cycles);
	}
	system("pause");
}

//Should return -1 if it wasnt found
int BinarySearch(Vector<int>& _array, int _to_find, int &_out_cycles)
{
	float min = 0;
	float max = _array.count - 1;
	float mid = (min + max) / 2;

	_out_cycles = 0;

	while (true)
	{
		++_out_cycles;

		if (_array[mid] == _to_find)
		{
			return mid;
		}
		else if (_array[mid] < _to_find)
		{
			min = mid;
			mid = (min + max) / 2;
			roundf(mid);
		}
		else
		{
			max = mid;
			mid = (min + max) / 2;
			roundf(mid);
		}
		if (_out_cycles > 100)
		{
			break;
		}
	}

	return -1;
}