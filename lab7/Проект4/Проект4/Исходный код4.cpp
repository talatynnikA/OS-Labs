
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
#include <tchar.h>


#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)


bool AreEqual(const TCHAR *a, const TCHAR *b)
{
	while (*a == *b)
	{
		if (*a == _TEXT('\0'))return true;
		a++; b++;
	}
	return false;
}



bool IsProcessRun()
{
	bool RUN;
	TCHAR buf[] = TEXT("chrome.exe");


	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	Process32First(hSnapshot, &pe);

	if (AreEqual(pe.szExeFile, buf))
	{
		RUN = true;
		return RUN;
	}
	else
		RUN = false;
	while (Process32Next(hSnapshot, &pe))
	{
		if (AreEqual(pe.szExeFile, buf))
		{
			RUN = true;
			return RUN;
		}
		else
			RUN = false;
	}
	return RUN;
}

int _tmain(int argc, _TCHAR* argv[])
{

	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);



	if (IsProcessRun())
	{

		std::wcout << "Running" << '\n';
	}
	else

	{
		std::wcout << "NOT Running" << '\n';
	}

	getchar();

	return 0;
}
