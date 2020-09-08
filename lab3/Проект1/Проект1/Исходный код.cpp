#include <Windows.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

void main()
{
	//HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hConsoleHandle, FOREGROUND_BLUE | BACKGROUND_RED);
	//cout << "Hello world!" << endl;

	//int x = 5; int y = 6;
	//COORD pos = { x, y };
	//HANDLE hConsole_c = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	//SetConsoleActiveScreenBuffer(hConsole_c);
	//char *str = "Some Text\r\n";
	//DWORD len = strlen(str);
	//DWORD dwBytesWritten = 0;
	//WriteConsoleOutputCharacter(hConsole_c, str, len, pos, &dwBytesWritten);
	//CloseHandle(hConsole_c);
	HANDLE consoleOutput;
	COORD cursorPos;
	consoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);


	cursorPos.X = 30;
	for (int i = 3; i < 15; i++)
	{
		cursorPos.Y = i;
		SetConsoleCursorPosition(consoleOutput, cursorPos);
		SetConsoleTextAttribute(consoleOutput, 0x2F);
		printf("        ");
	}
	/*
	cout << endl;
	printf("        ");
	cout << endl;
	printf("        ");
	cout << endl;
	printf("        ");
	cout << endl;
	printf("        ");*/
	SetConsoleTextAttribute(consoleOutput, 0x0F);
	cout << endl;
	system("pause");
}