// ConsoleApplication3.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <windows.h>
#include <tchar.h>

DWORD WINAPI myThread2(LPVOID lpParameter)
{
	LPHANDLE h = new HANDLE();
	h = (LPHANDLE)lpParameter;
	HANDLE hh = *h;

	_tprintf_s(TEXT("Thread 2 tries to suspend thread1\n"));
	SuspendThread(hh);

	_tprintf_s(TEXT("Thread1 is suspended for 3 seconds\n"));
	Sleep(3000);

	ResumeThread(hh);
	_tprintf_s(TEXT("Thread is resumed\n"));

	return EXIT_SUCCESS;
}

DWORD WINAPI myThread(LPVOID lpParameter)
{
	LPINT counterp = new INT();
	counterp = (LPINT)lpParameter;
	INT counter = *counterp;

	while (counter < 30)
	{
		Sleep(500);
		counter++;

		_tprintf_s(TEXT("Counter = %d\n"), counter);
	}

	return EXIT_SUCCESS;
}

INT _tmain(INT argc, _TCHAR* argv[])
{
	INT z = 5;
	DWORD dwMyThreadID;
	HANDLE hMyHandle = CreateThread(NULL, 0, myThread, (LPVOID)&z, 0, &dwMyThreadID);
	Sleep(5000);
	DWORD dwMyThreadID2;
	HANDLE hMyHandle2 = CreateThread(NULL, 0, myThread2, (LPVOID)&hMyHandle, 0, &dwMyThreadID2);

	Sleep(15000);
	_tprintf_s(TEXT("Main Process sagt\n"));
	TerminateThread(hMyHandle2, 0);
	TerminateThread(hMyHandle, 0);

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}

