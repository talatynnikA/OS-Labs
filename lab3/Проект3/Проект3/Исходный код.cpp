//#include "windows.h"
//#include <iostream>
//#include <tchar.h>
//
//INT _tmain(INT argc, _TCHAR* argv[])
//{
//
//	HANDLE consoleOutput;
//	COORD cursorPos;
//
//	// Получаем хэндл консоли 
//	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	// Задаем координаты курсора и перемещаем курсор
//	cursorPos.X = 30;
//	cursorPos.Y = 3;
//	SetConsoleCursorPosition(consoleOutput, cursorPos);
//
//	// Выводим строку
//	_tprintf_s(TEXT("Test string at position (30, 3)"));
//
//	// Повторяем с другими координатами...
//	cursorPos.X = 15;
//	cursorPos.Y = 8;
//	SetConsoleCursorPosition(consoleOutput, cursorPos);
//
//	_tprintf_s(TEXT("Test string at position (15, 8)"));
//
//	_tsystem(TEXT("pause"));
//	return EXIT_SUCCESS;
//}


//пример 2
#include <windows.h>
#include <iostream>
#include <tchar.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
	HANDLE consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleOutput, &csbi);
	COORD cursorPos;
	LPINT xs = new INT[3]{ 5, 10, 15 };
	LPINT ys = new INT[3]{ 6, 8, 10 };
	LPINT bs = new INT[3]{0x4D, 0x5E, 0x6F };
	CONSOLE_FONT_INFOEX info = { 0 };

	info.cbSize = sizeof(info);
	info.dwFontSize.Y = 14; // leave X as zero
	info.FontWeight = FW_BOLD;

	_tcscpy_s(info.FaceName, TEXT("White Rabbit"));
	SetCurrentConsoleFontEx(consoleOutput, NULL, &info);
	SetConsoleTextAttribute(consoleOutput, FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	for (INT i = 0; i < 3; i++) {
		cursorPos.X = xs[i];
		cursorPos.Y = ys[i];
		SetConsoleTextAttribute(consoleOutput, bs[i]);
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		_tprintf_s(TEXT("Test string at position (%d,%d)"), xs[i], ys[i]);
	}

	SetConsoleTextAttribute(consoleOutput, csbi.wAttributes);
	CloseHandle(consoleOutput);

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}


//пример 3
//#include <windows.h>
//#include <iostream>
//#include <tchar.h>
//
//CONST WORD colors[] =
//{
//	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
//	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
//};
//
//INT _tmain(INT argc, _TCHAR* argv[])
//{
//
//	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
//	WORD index = 0;
//
//	// Remember how things were when we started
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	GetConsoleScreenBufferInfo(hstdout, &csbi);
//
//	while (index < 13)
//	{
//		SetConsoleTextAttribute(hstdout, colors[index]);
//		_tprintf_s(TEXT("\t\t\t\t Hello World \t\t\t\t\n"));
//		if (++index > sizeof(colors) / sizeof(colors[0]))
//			break;
//	}
//
//	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
//
//	_tsystem(TEXT("pause"));
//	return EXIT_SUCCESS;
//}

//пример 4
//#include <windows.h>
//#include <iostream>
//#include <tchar.h>
//
//CONST WORD colors[] =
//{
//	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
//	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
//};
//
//INT _tmain(INT argc, _TCHAR* argv[])
//{
//
//	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD cursorPos;
//	WORD index = 0;
//
//	// Remember how things were when we started
//	CONSOLE_SCREEN_BUFFER_INFO csbi;
//	GetConsoleScreenBufferInfo(hstdout, &csbi);
//
//	// Задаем координаты курсора и перемещаем курсор
//	cursorPos.X = 30;
//	cursorPos.Y = 3;
//	SetConsoleCursorPosition(hstdout, cursorPos);
//	SetConsoleTextAttribute(hstdout, 0xEC);
//	// Выводим строку
//	_tprintf_s(TEXT("Test string at position (30, 3)"));
//	// Повторяем с другими координатами...
//	cursorPos.X = 15;
//	cursorPos.Y = 8;
//	SetConsoleCursorPosition(hstdout, cursorPos);
//	index += 1;
//	SetConsoleTextAttribute(hstdout, colors[index]);
//	_tprintf_s(TEXT("Test string at position (15, 8)"));
//
//	SetConsoleTextAttribute(hstdout, csbi.wAttributes);
//
//	cursorPos.X = 0;
//	cursorPos.Y = 9;
//	SetConsoleCursorPosition(hstdout, cursorPos);
//
//	_tsystem(TEXT("pause"));
//	return EXIT_SUCCESS;
//}


