#include <consoleapi.h>
#include <chrono>
#include "Array.h"
#include "Resources.h"
#include "Globals.h"
#include "Object.h"
#include "gainput\gainput.h"

void main()
{
	//Create a console buffer
	HANDLE consoleBuffer = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleMode(consoleBuffer, ENABLE_INSERT_MODE);
	//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	//Set it to active
	SetConsoleActiveScreenBuffer(consoleBuffer);
	//Define a few attributes for our buffer
	SMALL_RECT windowSize = { 0,0,BUFFER_DIMENSION - 1, BUFFER_DIMENSION - 1 };
	CONSOLE_FONT_INFOEX font = { sizeof(CONSOLE_FONT_INFOEX), 3, COORD{8,8}};
	CONSOLE_CURSOR_INFO cursor = { 1, FALSE };
	//Set those attributes
	SetCurrentConsoleFontEx(consoleBuffer, TRUE, &font);
	SetConsoleScreenBufferSize(consoleBuffer, COORD{ BUFFER_DIMENSION, BUFFER_DIMENSION });
	SetConsoleWindowInfo(consoleBuffer, TRUE, &windowSize);

	SetConsoleCursorInfo(consoleBuffer, &cursor);
	//The Title of our console
	SetConsoleTitle("OH HEY WOW");
	//Create a character buffer to use for 'drawing' characters to screen
	CHAR_INFO* buffer = new CHAR_INFO[BUFFER_SIZE];
	SMALL_RECT bufferSize = { 0, 0, BUFFER_DIMENSION, BUFFER_DIMENSION };
	//Fill it with + characters and random colors
	for (int y = 0; y < BUFFER_DIMENSION; ++y)
	{
		for (int x = 0; x < BUFFER_DIMENSION; ++x)
		{
			buffer[x + (BUFFER_DIMENSION * y)].Attributes = y*x;
			buffer[x + (BUFFER_DIMENSION * y)].Char.AsciiChar = '+';
		}
	}
	//Write it out
	WriteConsoleOutput(consoleBuffer, buffer, COORD{ BUFFER_DIMENSION,BUFFER_DIMENSION }, COORD{ 0,0 }, &bufferSize);
	//Chrono library for getting delta time
	std::chrono::time_point<std::chrono::high_resolution_clock> curtime, prevtime;
	std::chrono::high_resolution_clock time;
	float deltaTime;
	curtime = time.now();
	prevtime = curtime;
	//Resource manager
	Resource* resource = new Resource(buffer);
	resource->AddImage("./test.st", Resource::T_ID::WHITE_SQUARE);
	//Input library
	//input::InputManager* inputManager = new gainput::InputManager();
	//putManager->SetDisplaySize(8 * BUFFER_DIMENSION, 8 * BUFFER_DIMENSION);
	//nst gainput::DeviceId keyboardID = inputManager->CreateDevice<gainput::InputDeviceKeyboard>();

	//Test object
	Object testing(COORD{ 32,32 }, Resource::T_ID::WHITE_SQUARE);

	while (true)
	{
		curtime = time.now();
		deltaTime = (std::chrono::duration_cast<std::chrono::duration<float, std::milli>>(curtime - prevtime).count() / 1000.f);
		prevtime = curtime;

		//inputManager->Update();
		//Dostuff here

		//This here clears the screen
		for (int y = 0; y < BUFFER_DIMENSION; ++y)
		{
			for (int x = 0; x < BUFFER_DIMENSION; ++x)
			{
				buffer[x + (BUFFER_DIMENSION * y)].Attributes = y*x;
				buffer[x + (BUFFER_DIMENSION * y)].Char.UnicodeChar = (char16_t)'+';
			}
		}

		testing.Update(deltaTime);

		testing.Draw(resource);

		//Final draw command
		WriteConsoleOutput(consoleBuffer, buffer, COORD{ BUFFER_DIMENSION,BUFFER_DIMENSION }, COORD{ 0,0 }, &bufferSize);
	}
	//Cleanup
	delete[] buffer;
	delete resource;

	system("pause");
}