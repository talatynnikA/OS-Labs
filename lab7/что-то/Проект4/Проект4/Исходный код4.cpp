#include "windows.h"
#include <tlhelp32.h>
#include <tchar.h>

#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)

bool AreEqual(const TCHAR* a, const TCHAR* b)
{
	while (*a == *b)
	{
		if (*a == _TEXT('\0'))
			return true;
		a++;
		b++;
	}
	return false;
}

bool IsProcessRun(const TCHAR* procName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &pe);

	if (AreEqual(pe.szExeFile, procName))
	{
		return true;
	}

	while (Process32Next(hSnapshot, &pe))
	{
		if (AreEqual(pe.szExeFile, procName))
		{
			return true;
		}
	}
	return false;
}

INT _tmain(INT argc, _TCHAR* argv[])
{

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);

	if (IsProcessRun(TEXT("mspaint.exe")))
		_tprintf_s(TEXT("Running.\n"));
	else
		_tprintf_s(TEXT("Not running.\n"));

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}

