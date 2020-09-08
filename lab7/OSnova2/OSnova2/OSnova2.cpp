// OSnova2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

//
//#include "windows.h"
//#include <tlhelp32.h>
//#include "string.h"
//#include <iostream>
//#include <tchar.h>
//#include "sdkddkver.h"
//
//
//
//using namespace std;
//int _tmain(int argc, _TCHAR* argv[])
//{
//	WIN32_FIND_DATA FindFileData;
//	HANDLE hFind = INVALID_HANDLE_VALUE;
//	TCHAR directorySearch[100] = TEXT("C:\\Windows\\");
//	TCHAR filesearch[] = TEXT("C:\\Windows\\notepad.exe");
//	hFind = FindFirstFile(filesearch, &FindFileData);
//	if (hFind == INVALID_HANDLE_VALUE)
//	{
//		printf("invalid file handle. Error is %u.\n", GetLastError());
//	}
//	else
//	{
//		wcout << "Found: " << FindFileData.cFileName << "\n";
//		while (FindNextFile(hFind, &FindFileData) != 0) //���������� ����� ����� �� ����������� ������ ������� FindFirstFile
//		{
//			wcout << "Found: " << FindFileData.cFileName << "\n";
//
//		}
//		STARTUPINFO cif; // ����� ���������� ������� �������� , ������� ����, ����������� ���������� � ��. ��� ��������� ���� ��� ������ ��������
//		PROCESS_INFORMATION pi; //���������� ���������� ������ ��������
//		GetStartupInfo(&cif); //����� ������� ��������� STARTUPINFO ������������ ����� ����� ������� ��� ������
//		wcscat_s(directorySearch, FindFileData.cFileName);
//		if (!(CreateProcessW(NULL, directorySearch, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi)))
//			std::wcout << "Error: " << '\n';
//	}
//	FindClose(hFind);
//	return 0;
//}




#include <tchar.h>
#include "sdkddkver.h"
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
using namespace std;
#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)


bool AreEqual(const TCHAR* a, const TCHAR* b)
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
	TCHAR buf[] = TEXT("write.exe");


	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); // ������� ������� ���������� ���������, �������, ����� � ��� �����

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
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE); //��������� ������ �������

	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE); //������� �������

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	TCHAR directorySearch[100] = TEXT("C:\\Windows\\");
	TCHAR filesearch[] = TEXT("C:\\Windows\\write.exe");
	hFind = FindFirstFile(filesearch, &FindFileData); //��������� ���������� ������ � ���������� ���������� � ������ ����� , ��� �������� ���������� ���������� �������
	// ��� ���� � ������� � �������� ����� �����
	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("invalid file handle. Error is %u.\n", GetLastError());
	}
	else
	{
		wcout << "Found: " << FindFileData.cFileName << '\n';
		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			wcout << "Found: " << FindFileData.cFileName << '\n';
		}
		STARTUPINFO cif;
		PROCESS_INFORMATION pi;
		GetStartupInfo(&cif);
		wcscat_s(directorySearch, FindFileData.cFileName);
		if (!(CreateProcessW(NULL, directorySearch, NULL, NULL, FALSE, 0, NULL, NULL, &cif, &pi)))
			std::wcout << "Error " << '\n';
	}

	if (IsProcessRun())
	{
		std::wcout << "Running" << '\n';
	}
	else

	{
		std::wcout << "NOT Running" << '\n';
	}

	getchar();
	FindClose(hFind);
	return 0;
}