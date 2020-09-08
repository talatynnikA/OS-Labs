//5.	Теперь синхронизируем работу потока с файлом с помощью механизма семафоров(критических зон).Обратить внимание на использование команд

//EnterCriticalSection(&cs);  -вход в критическую секцию
//LeaveCriticalSection(&cs);  -выход из критической секции


#include <windows.h>
#include <tchar.h>

struct threadParam {
	PTCHAR string;
	INT size;
};

CRITICAL_SECTION cs;

DWORD WINAPI myThread(LPVOID lpParameter)
{
	EnterCriticalSection(&cs);
	HANDLE hOut = CreateFile(TEXT("C:\\Users\\Admin\\Documents\\учебные штуки\\ос\\моя работа\\lab9\\примеры\\test.txt"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hOut == INVALID_HANDLE_VALUE || hOut == NULL) {
		_tprintf_s(TEXT("Error while creating file: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else {
		DWORD dwBytes;
		threadParam* b = (threadParam*)lpParameter;
		if (!WriteFile(hOut, b->string, b->size, &dwBytes, NULL)) {
			_tprintf_s(TEXT("Error while writing in file: %d\n"), GetLastError());
			CloseHandle(hOut);
			LeaveCriticalSection(&cs);
			return EXIT_FAILURE;
		}
		else {
			_tprintf_s(TEXT("Writing file done successfully!\n"));
			CloseHandle(hOut);
		}

	}
	LeaveCriticalSection(&cs);
	return EXIT_SUCCESS;
}

INT _tmain(INT argc, _TCHAR* argv[])
{
	DWORD dwMyThreadID;
	TCHAR Buffer[] = TEXT("Hello! Students!");
	threadParam parameter;
	parameter.string = Buffer;
	parameter.size = sizeof(Buffer);
	InitializeCriticalSection(&cs);
	HANDLE hMyHandle = CreateThread(NULL, 0, myThread, (LPVOID)(&parameter), CREATE_SUSPENDED, &dwMyThreadID);
	if (hMyHandle == INVALID_HANDLE_VALUE || hMyHandle == NULL) {
		_tprintf_s(TEXT("Error while creating thread: %d\n"), GetLastError());
		return EXIT_FAILURE;
	}

	if (SetThreadPriorityBoost(hMyHandle, FALSE)) {
		SetThreadPriority(hMyHandle, THREAD_PRIORITY_HIGHEST);
	}

	ResumeThread(hMyHandle);
	WaitForSingleObject(hMyHandle, 10000);

	_tprintf_s(TEXT("Main Process sagt Das ist Alles\n"));
	CloseHandle(hMyHandle);
	DeleteCriticalSection(&cs);
	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}

