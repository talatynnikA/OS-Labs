#include "stdafx.h"
#include "windows.h"
#include <iostream>
#include <tlhelp32.h>
#include "string.h"


const WORD colors[] =
{
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
};

int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE consoleOutput;
	COORD cursorPos;

	// Получаем хэндл консоли 
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	WORD   index = 0;

	// Remember how things were when we started
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleOutput, &csbi);

	// Задаем координаты курсора и перемещаем курсор
	cursorPos.X = 30;
	cursorPos.Y = 3;
	SetConsoleCursorPosition(consoleOutput, cursorPos);
	SetConsoleTextAttribute(consoleOutput, 0xEC);
	// Выводим строку
	printf("Test string at position (30, 3)");

	// Повторяем с другими координатами...
	cursorPos.X = 15;
	cursorPos.Y = 8;
	SetConsoleCursorPosition(consoleOutput, cursorPos);
	index++;
	SetConsoleTextAttribute(consoleOutput, colors[index]);
	printf("Test string at position (15, 8)");

	getchar();

	return 0;
}
