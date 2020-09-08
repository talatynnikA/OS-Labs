//6.	Наконец, сделаем синхронизированный доступ к одному и тому же файлу через 
//механизм критических секций со стороны двух потоков.

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
			_tprintf_s(TEXT("Writing file done successfully 1!\n"));
			CloseHandle(hOut);
		}

	}
	LeaveCriticalSection(&cs);
	return EXIT_SUCCESS;
}

DWORD WINAPI myThread2(LPVOID lpParameter)
{
	EnterCriticalSection(&cs);
	HANDLE hOut = CreateFile(TEXT("C:\\Users\\Admin\\Documents\\учебные штуки\\ос\\моя работа\\lab9\\примеры\\test.txt"), GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
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
			_tprintf_s(TEXT("Writing file done successfully 2!\n"));
			CloseHandle(hOut);
		}

	}
	LeaveCriticalSection(&cs);
	return EXIT_SUCCESS;
}

INT _tmain(INT argc, _TCHAR* argv[])
{
	DWORD
		dwMyThreadID,
		dwMyThread2ID;
	TCHAR
		Buffer[] = TEXT("Hello!"),
		Buffer2[] = TEXT("Students!");
	threadParam
		parameter,
		parameter2;

	parameter.string = Buffer;
	parameter.size = sizeof(Buffer);

	parameter2.string = Buffer2;
	parameter2.size = sizeof(Buffer2);

	InitializeCriticalSection(&cs);
	HANDLE hMyHandle = CreateThread(NULL, 0, myThread, (LPVOID)(&parameter), CREATE_SUSPENDED, &dwMyThreadID);
	if (hMyHandle == INVALID_HANDLE_VALUE || hMyHandle == NULL) {
		_tprintf_s(TEXT("Error while creating thread: %d\n"), GetLastError());
		_tsystem(TEXT("pause"));
		return EXIT_FAILURE;
	}

	HANDLE hMyHandle2 = CreateThread(NULL, 0, myThread2, (LPVOID)(&parameter2), CREATE_SUSPENDED, &dwMyThread2ID);
	if (hMyHandle2 == INVALID_HANDLE_VALUE || hMyHandle2 == NULL) {
		_tprintf_s(TEXT("Error while creating thread: %d\n"), GetLastError());
		CloseHandle(hMyHandle);
		_tsystem(TEXT("pause"));
		return EXIT_FAILURE;
	}
	if (SetThreadPriorityBoost(hMyHandle, FALSE)) {
		SetThreadPriority(hMyHandle, THREAD_PRIORITY_HIGHEST);
	}

	ResumeThread(hMyHandle);
	ResumeThread(hMyHandle2);
	WaitForSingleObject(hMyHandle2, 10000);

	_tprintf_s(TEXT("Main Process sagt Das ist Alles\n"));
	CloseHandle(hMyHandle);
	CloseHandle(hMyHandle2);
	DeleteCriticalSection(&cs);
	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}

