// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"									//задание2

#include <windows.h>
#include <iostream>
#include <string>
#include <tchar.h>

using namespace std;

DWORD WINAPI reader(void* lpParameter)
{
	int* readNumber = new int();
	readNumber = (int*)lpParameter;
	_tprintf_s(L"%s %i %s", L"прочитано: ", *readNumber, "\n");
	return 0;
}

DWORD WINAPI writer(LPVOID lpParameter)
{
	int* pcount = new int();
	pcount = (int*)lpParameter;
	int count = *pcount;
	while (count < 40)
	{
		count++;
		DWORD dwWriterID;
		HANDLE myHandle2 = CreateThread(0, 0, reader, (void*)&count, 0, &dwWriterID);
		_tprintf_s(TEXT("записано\n"));
		Sleep(300);
	
	}
	return EXIT_SUCCESS;
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian");
	int z = 0;
	DWORD dwReaderID;
	HANDLE hMyHandle = CreateThread(0, 0, writer, (void*)&z, 0, &dwReaderID);
	if (hMyHandle == INVALID_HANDLE_VALUE || hMyHandle == NULL)
	{
		_tprintf_s(TEXT("ошибка при создании потока "));
		return EXIT_FAILURE;
	}
	Sleep(6000);
	_tprintf_s(TEXT("выполнено"));

	TerminateThread(hMyHandle, EXIT_SUCCESS);
	return EXIT_SUCCESS;
	return 0;
}

