//1.	Изменение приоритета потока.
//
//В качестве программы, демонстрирующей изменение приоритета потока, рассмотреть следующую
//

#include <windows.h>
#include <tchar.h>

DWORD WINAPI myThread(LPVOID lpParameter)
{
	LPINT counterp = new INT();
	counterp = (LPINT)lpParameter;
	INT counter = *counterp;

	while (counter < 20)
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
	if (hMyHandle == INVALID_HANDLE_VALUE || hMyHandle == NULL) {
		_tprintf_s(TEXT("Error while creating thread: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	INT iCurrentPriority = GetPriorityClass(GetCurrentProcess());
	_tprintf_s(TEXT("Priority class of current process is: %d\n"), iCurrentPriority);

	INT iPriority = GetThreadPriority(hMyHandle);// + CurPr;
	_tprintf_s(TEXT("Priority is: %d\n"), iPriority);

	SetThreadPriority(hMyHandle, THREAD_PRIORITY_ABOVE_NORMAL);
	iPriority = GetThreadPriority(hMyHandle);// + CurPr;
	_tprintf_s(TEXT("After changes priority is: %d\n"), iPriority);

	SetThreadPriority(hMyHandle, THREAD_PRIORITY_HIGHEST);
	iPriority = GetThreadPriority(hMyHandle);// + CurPr;
	_tprintf_s(TEXT("The highest priority is: %d\n"), iPriority);

	SetThreadPriority(hMyHandle, THREAD_PRIORITY_LOWEST);
	iPriority = GetThreadPriority(hMyHandle);// + CurPr;
	_tprintf_s(TEXT("The lowest priority is: %d\n"), iPriority);

	Sleep(5000);
	_tprintf_s(TEXT("Main Process sagt\n"));
	TerminateThread(hMyHandle, EXIT_SUCCESS);

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}

