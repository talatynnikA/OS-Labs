//2.	Запуск потока на запись в файл.

#include <windows.h>
#include <tchar.h>

DWORD WINAPI myThread(LPVOID lpParameter)
{
	HANDLE hOut = CreateFile(TEXT("C:\\Users\\Admin\\Documents\\учебные штуки\\ос\\моя работа\\lab9\\примеры\\test.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hOut == INVALID_HANDLE_VALUE || hOut == NULL) {
		_tprintf_s(TEXT("Error while creating file: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else {
		DWORD dwBytes;
		TCHAR Buffer[] = TEXT("HELLO!");
		if (!WriteFile(hOut, Buffer, sizeof(Buffer), &dwBytes, NULL)) {
			_tprintf_s(TEXT("Error while writing in file: %d\n"), GetLastError());
			CloseHandle(hOut);
			return EXIT_FAILURE;
		}
		else {
			_tprintf_s(TEXT("Writing file done successfully!\n"));
			CloseHandle(hOut);
		}

	}
	return EXIT_SUCCESS;
}

INT _tmain(INT argc, _TCHAR* argv[])
{
	DWORD dwMyThreadID;
	HANDLE hMyHandle = CreateThread(NULL, 0, myThread, NULL, CREATE_SUSPENDED, &dwMyThreadID);
	if (hMyHandle == INVALID_HANDLE_VALUE || hMyHandle == NULL) {
		_tprintf_s(TEXT("Error while creating thread: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}

	if (SetThreadPriorityBoost(hMyHandle, FALSE)) {
		SetThreadPriority(hMyHandle, THREAD_PRIORITY_HIGHEST);
	}

	ResumeThread(hMyHandle);
	Sleep(2000);

	_tprintf_s(TEXT("Main Process sagt Das ist Alles\n"));
	CloseHandle(hMyHandle);

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}
