#include <iostream>
#include <fstream>

void main()
{
	short string[64] =
	  { 'A', 'A', 'A', 'A', '\n',
		'A', 'a', 'a', 'A', '\n',
		'A', 'a', 'a', 'A', '\n',
		'A', 'A', 'A', 'A', '\0' };
	char modifier[64] = 
	  { 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1 };

	std::ofstream file;
	file.open("./test2.st", std::ios::out | std::ios::trunc | std::ios::binary);
	for(int i = 0;;++i)
	{
		if (string[i] == 0x0000)
		{
			file << std::hex << (char)0x00;
			file << std::hex << (char)0x00;
			file << std::hex << (char)0x00;
			break;
		}
		else
		{
			file << std::hex << *((char*)string + (i * 2));
			file << std::hex << *((char*)string + (i * 2 + 1));
			file << std::hex << modifier[i];
		}
	}
	file.close();
}