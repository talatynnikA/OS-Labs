#include <windows.h> 
#include <iostream> 
	using namespace std;
	CONSOLE_SCREEN_BUFFER_INFO csbi;// ��� ���� ������� ����� � ������ �� ����������
void main()
{
	setlocale(LC_ALL, "rus");
			HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);// ����� ����������� ��� ������ �� ��������� ������
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
		WORD wOldColorAttrs;
	wOldColorAttrs = csbi.wAttributes; //��������� ������ �������� 
	//SetConsoleTextAttribute(hStdOut, BACKGROUND_GREEN);
		COORD cursorPos = { 1,1 }; // ���������� ������ �������� ���� 

	//������ ������ ������� 
	cursorPos = { 7, 6 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
	printf("_______________________________________________________________________");
	cursorPos = { 7,7 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("�������");
	cursorPos = { 23,7 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("������");
		cursorPos = { 7, 8 };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("_______________________________________________________________________");
	cursorPos = { 7,9 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("������");
	cursorPos = { 23,9 };
	SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("23");
		cursorPos = { 7, 10 };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("_______________________________________________________________________\n");
		// ���������� �������� ����� 
	SetConsoleTextAttribute(hStdOut, wOldColorAttrs);

	system("pause");
}
