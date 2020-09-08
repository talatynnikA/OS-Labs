//#include <Windows.h>
//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <ctime>
//#include <fstream>
//using namespace std;
//
//void main()
//{
//	setlocale(LC_CTYPE, "Russian");
//	cout << "_______________________________________________________________________";
//	cout << endl;
//	cout << "|ФАМИЛИЯ                          |                              ГРУППА|";
//	cout << endl;
//	cout << "_______________________________________________________________________";
//	cout << endl;
//	cout << "|ПЕТРОВ                           |                              23    |";
//	cout << endl;
//	cout << "_______________________________________________________________________";
//	cout << endl;
//	cout << "|ВАСИЛЬЕВ                         |                              13    |";
//	cout << endl;
//	cout << "_______________________________________________________________________";
//	cout << endl;
//	cout << "|ТАЛАТЫННИК                       |                              14    |";
//	cout << endl;
//	cout << "_______________________________________________________________________";
//	cout << endl;
//	cout << "|АЛЕКСИЕВИЧ                       |                              15    |";
//	cout << endl;
//	cout << "_______________________________________________________________________";
//	cout << endl;
//	cout << endl << 0xB6;
//	system("pause");
//}
#include <windows.h>
#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
void drawBox(HANDLE hStdOut, COORD Pos);
void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleTitle("TABLE"); //заголовок окна
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hStdOut, &csbiInfo);
	WORD wOldColorAttrs;
	wOldColorAttrs = csbiInfo.wAttributes; //сохраняем старые атрибуты
	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE);
	COORD cursorPos = { 1, 1 }; // координаты левого верхнего угла
	drawBox(hStdOut, cursorPos); // Печать линий

	//печать данных таблицы
	cursorPos = { 1, 2 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	printf("Фамилия");
	cursorPos = { 20, 2 };
	SetConsoleCursorPosition(hStdOut, cursorPos);

	printf("Группа");
	cursorPos = { 1, 4 };

	SetConsoleCursorPosition(hStdOut, cursorPos);
	printf("Петров");
	cursorPos = { 20, 4 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	printf("23");
	cursorPos = { 1, 20 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	// Возвращаем исходные цвета
	SetConsoleTextAttribute(hStdOut, wOldColorAttrs);

	system("pause");
}
void drawBox(HANDLE hStdOut, COORD Pos)
{
	for (int i = 0; i < 3; i++) {
		SetConsoleCursorPosition(hStdOut, Pos);
		for (int j = 0; j < 50; j++) cout « char(95);
		Pos.Y += 2;
	}
}