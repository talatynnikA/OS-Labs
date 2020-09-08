
#include "windows.h"
#include <tlhelp32.h>
#include <tchar.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
		FOREGROUND_INTENSITY | BACKGROUND_BLUE);

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot) {
		PROCESSENTRY32 pe32;
		pe32.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hSnapshot, &pe32)) {
			do {
				_tprintf_s(TEXT("Running ProcName: %s.\n"), pe32.szExeFile);
			} while (Process32Next(hSnapshot, &pe32));
		}
		CloseHandle(hSnapshot);
	}

	CloseHandle(hStdout);
	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}
