#include <consoleapi.h>
#include <chrono>
#include "Array.h"

#define BUFFER_SIZE 4096U
#define BUFFER_DIMENSION 64U

void main()
{
	DWORD bytesWritten;
	HANDLE consoleBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleMode(consoleBuffer, ENABLE_INSERT_MODE);
	//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleActiveScreenBuffer(consoleBuffer);

	SMALL_RECT windowSize = { 0,0,BUFFER_DIMENSION - 1, BUFFER_DIMENSION - 1 };
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX), 3, COORD{8,8}};
	CONSOLE_CURSOR_INFO cursor = { 1, FALSE };

	SetCurrentConsoleFontEx(consoleBuffer, TRUE, &font);
	SetConsoleScreenBufferSize(consoleBuffer, COORD{ BUFFER_DIMENSION, BUFFER_DIMENSION });
	SetConsoleWindowInfo(consoleBuffer, TRUE, &windowSize);

	SetConsoleCursorInfo(consoleBuffer, &cursor);

	SetConsoleTextAttribute(consoleBuffer, FOREGROUND_GREEN);

	SetConsoleTitle("OH HEY WOW");
	// its 64 x 64
	CHAR_INFO buffer[BUFFER_SIZE];
	SMALL_RECT bufferSize = { 0, 0, BUFFER_DIMENSION, BUFFER_DIMENSION };
	for (int y = 0; y < BUFFER_DIMENSION; ++y)
	{
		for (int x = 0; x < BUFFER_DIMENSION; ++x)
		{
			if (x == BUFFER_DIMENSION - 1)
			{
				if (y == BUFFER_DIMENSION - 1)
					buffer[x + (BUFFER_DIMENSION * y)].Char.AsciiChar = 0;
				else
					buffer[x + (BUFFER_DIMENSION * y)].Char.AsciiChar = '\n';
			}
			else
				buffer[x + (BUFFER_DIMENSION * y)].Char.AsciiChar = '.';
		}
	}
	WriteConsoleOutput(consoleBuffer, buffer, COORD{ BUFFER_DIMENSION,BUFFER_DIMENSION }, COORD{ 0,0 }, &bufferSize);
	////TESTING
	//CHAR_INFO test3[25];
	//for(int i = 0; i < 25; ++i)
	//{
	//	test3[i].Attributes = FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
	//	test3[i].Char.AsciiChar = '0';
	//}
	//SMALL_RECT test2 = { 30,30,34,34 };
	//WriteConsoleOutput(consoleBuffer, test, COORD{ 5,5 }, COORD{ 0,0 }, &test2);

	std::chrono::time_point<std::chrono::high_resolution_clock> curtime, prevtime;
	std::chrono::high_resolution_clock time;
	float deltaTime;
	curtime = time.now();

	float letssee = 0.f;

	while (true)
	{
		prevtime = curtime;
		float deltaTime = std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(curtime - prevtime).count();
		curtime = time.now();

		letssee += deltaTime;
	}

	system("pause");
}