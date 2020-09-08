// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <tchar.h>

DWORD WINAPI myThread(LPVOID lpParameter)
{
	UINT counter = 0;

	while (counter < 20)
	{
		Sleep(1000);
		counter++;
		_tprintf_s(TEXT("Counter = %d\n"), counter);
	}

	return EXIT_SUCCESS;
}



int _tmain(int argc, _TCHAR* argv[])
{
	DWORD dwMyThreadID;
	HANDLE hMyHandle = CreateThread(0, 0, myThread, NULL, 0, &dwMyThreadID);
	if (hMyHandle == INVALID_HANDLE_VALUE || hMyHandle == NULL) {
		_tprintf_s(TEXT("Error while creating thread: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	Sleep(5000);
	_tprintf_s(TEXT("Main Process sagt\n"));
	TerminateThread(hMyHandle, EXIT_SUCCESS);

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;

	return 0;
}

