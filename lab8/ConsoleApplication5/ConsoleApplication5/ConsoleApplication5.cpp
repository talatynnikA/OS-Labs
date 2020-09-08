// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"													//ЗАДАНИЕ1
#include <windows.h>
#include <iostream>
#include <string>
#include <tchar.h>

using namespace std;

DWORD WINAPI newThread1(PVOID lpParameter)
{
	setlocale(LC_CTYPE, "Russian");
	int count1 = 1;
	while (count1 < 15 && count1 >= 0)
	{
		Sleep(1000);
		count1++;
		_tprintf_s(TEXT(" 1 Поток: %d\n"), count1);

	}
	return EXIT_SUCCESS;
}

DWORD WINAPI newThread2(PVOID IpParameter)
{
	setlocale(LC_CTYPE, "Russian");

	int count2 = 10;
	while ( count2 > 0)
	{

		Sleep(1000);
		count2--;
		_tprintf_s(TEXT(" 2 Поток: %d\n"), count2);

	}

	return EXIT_SUCCESS;
}


int main(int argc, TCHAR* argv[])
{

	int count1 = 0;
	int count2 = 1;
	DWORD hThreadID;
	HANDLE hThread1 = CreateThread(NULL, 0, newThread1, &count1, 0, &hThreadID);
	HANDLE hThread2 = CreateThread(NULL, 0, newThread2, &count2, 0, &hThreadID);
	getchar();
	TerminateThread(hThread1, 0);
	TerminateThread(hThread2, 0);
	return 0;
}