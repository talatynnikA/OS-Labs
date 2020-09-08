#include <windows.h> 
#include <iostream> 
	using namespace std;
	CONSOLE_SCREEN_BUFFER_INFO csbi;// для сохр первичн настр и возввр по надобности
void main()
{
	setlocale(LC_ALL, "rus");
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// подкл дескриптора для работы со строковым вводом
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
		WORD wOldColorAttrs;
	wOldColorAttrs = csbi.wAttributes; //сохраняем старые атрибуты 
	//SetConsoleTextAttribute(hStdOut, BACKGROUND_GREEN);
		COORD cursorPos = { 1,1 }; // координаты левого верхнего угла 

	//печать данных таблицы 
	cursorPos = { 7, 6 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	printf("_______________________________________________________________________");
	cursorPos = { 7,7 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("Фамилия");
	cursorPos = { 23,7 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("Группа");
		cursorPos = { 7, 8 };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("_______________________________________________________________________");
	cursorPos = { 7,9 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("Петров");
	cursorPos = { 23,9 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("23");
		cursorPos = { 7, 10 };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("_______________________________________________________________________\n");
		// Возвращаем исходные цвета 
	SetConsoleTextAttribute(hStdOut, wOldColorAttrs);

	system("pause");
}
