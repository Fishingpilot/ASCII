#include <iostream>
#include <thread>

#define BUFFER_SIZE 4096U
#define BUFFER_DIMENSIONS 64U
#define SPACE 32U

void get_input(bool *_arg, unsigned char *_input)
{
	while (*_arg)
	{
		std::cin >> *_input;
	}
}

void main()
{
	bool running = true;
	unsigned char input = 0U;
	unsigned char buffer[BUFFER_SIZE];

	std::thread inputThread(&get_input, &running, &input);
	inputThread.detach();

	while (running)
	{
		for (unsigned int c = 0U; c < BUFFER_DIMENSIONS; ++c)
		{
			for (unsigned int i = 0U; i < BUFFER_DIMENSIONS; ++i)
			{
				if (c == 64U)
				{
					if (i = 64U)
						buffer[c * i] = 0U;
					else
						buffer[c * i] = '\n';
				}
				else
				{
					buffer[c * i] = 'A';
				}
			}
		}
		system("CLS");
		std::cout << buffer;
	}

	system("pause");
}