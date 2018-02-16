#include "Array.h"
#include "String.h"
#include <iostream>

#pragma region __CLASS__
struct Vector2D
{
	float x, y;
};

struct Inventory
{
	int guns;
	int ammo;
	int medikits;
};

struct Player
{
	char name[64];
	int health;
	int score;
	Vector2D position;
	Vector2D velocity;
	Inventory inventory;
};

struct Shop
{
	int gold;
	Inventory stock;
	Inventory price;
};

struct Polygon
{
	Vector<Vector2D> point;
	int color;
};

void main001()
{
	//Player input stuff
	Player p1;
	
	printf("Input name: ");
	std::cin.getline(p1.name, 63);
	p1.health = 100;
	printf("Input score: ");
	std::cin >> p1.score;

	printf("\n\nName: %s\nHP: %d  Score: %d\n", p1.name, p1.health, p1.score);

	//A Polygon class with the points of a square
	Polygon square;
	square.color = 0xFFFFFFFF;
	square.point.Push(Vector2D{ -1, 1 });
	square.point.Push(Vector2D{ -1,-1 });
	square.point.Push(Vector2D{  1,-1 });
	square.point.Push(Vector2D{  1, 1 });

	printf("\n\nSquare color: %X\n", square.color);
	for (unsigned int i = 0U; i < square.point.count; ++i)
	{
		printf("%d - %6.2f,%6.2f\n",i, square.point[i].x, square.point[i].y);
	}
	system("pause");
	system("CLS");
	//Shopping time
	//---------------------------------------------------
	Shop shop;
	shop.gold = 1000;
	shop.stock.guns = 1;
	shop.stock.ammo = 100;
	shop.stock.medikits = 5;
	shop.price.guns = 20;
	shop.price.ammo = 2;
	shop.price.medikits = 10;
	printf("\n-=SHOP=-\nSpend your score on items!\n");
	
	String input(64);
	while (true)
	{
		std::cin.getline(input.Chr(), 63);
		//Sets all letters in the string to lowercase
		input.ToLower();
		//Self Explanatory QUIT
		if (input == "quit")
			break;
		else if (input.Contains("buy"))
		{
			//If the player wants to buy a gun
			if (input.Contains(" gun"))
			{
				//Shop has 0 stock of the item you want
				if (shop.stock.guns <= 0)
				{
					printf("There are none left!\n");
					continue;
				}
				//Can the player afford it?
				if (p1.score >= shop.price.guns)
				{
					printf("You bought a gun\n");
					p1.score -= shop.price.guns;
					shop.gold += shop.price.guns;
					--shop.stock.guns;
				}
				else
					printf("You cannot afford a gun\n");
			}
			//If the player wants some ammo
			else if (input.Contains(" ammo"))
			{
				//Shop has 0 stock of the item you want
				if (shop.stock.ammo <= 0)
				{
					printf("There are none left!\n");
					continue;
				}
				//Can the player afford it?
				if (p1.score >= shop.price.ammo)
				{
					printf("You bought some ammo\n");
					p1.score -= shop.price.ammo;
					shop.gold += shop.price.ammo;
					--shop.stock.ammo;
				}
				else
					printf("You cannot afford ammo\n");
			}
			//If the player wants a medikit
			else if (input.Contains(" medikit"))
			{
				//Shop has 0 stock of the item you want
				if (shop.stock.medikits <= 0)
				{
					printf("There are none left!\n");
					continue;
				}
				//Can the player afford it?
				if (p1.score >= shop.price.medikits)
				{
					printf("You bought a medikit\n");
					p1.score -= shop.price.medikits;
					shop.gold += shop.price.medikits;
					--shop.stock.medikits;
				}
				else
					printf("You cannot afford a medikit\n");
			}
			//Stuff the player cant buy
			else if (input.Contains(" gold"))
				printf("You cannot buy the shops gold!\n");
			else
				printf("You cannot buy this\n");
		}
		//Check the shops stock of items
		else if (input == "stock")
			printf("-=Shop stocks=-\nGun - %d\nAmmo - %d\nMediKit - %d\nGold: %d\n", shop.stock.guns, shop.stock.ammo, shop.stock.medikits, shop.gold);
		//Check your score (gold)
		else if (input == "score")
			printf("-=Score=-\nYou have: %d\n", p1.score);
		//Get some help
		else if (input == "help")
			printf("-=Help=-\nhelp - displays this\nbuy <item_name> - Buys item if you have enough score\nstock - shows items for purchase\nscore - shows your score\nquit - quits\n");
		//Invalid command
		else
			printf("Thats not an option\n");
	}

	system("pause");
}
#pragma endregion
#pragma region __BINARY__
//Theres a binary sort in here
//----------------------------
int BinarySearch(Vector<int>&, int, int&);
//This is main() remove the 0's and add them to the other main in __CLASS__
void main000()
{
	Vector<int> intlist(2500);
	
	for (unsigned int i = 0U; i < intlist.length; ++i)
	{
		intlist.Push(i * i);
		printf("%d ", intlist[i]);
	}
	
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
	for (unsigned int i = 0U; i < intlist.length; ++i)
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
#pragma endregion
