//#include "stdafx.h"
#include "windows.h"
#include <tlhelp32.h>
#include "string.h"
#include <iostream>
#include <tchar.h>



int _tmain(int argc, _TCHAR* argv[])
{

	//-----------------1Á-----------------
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");
	if (!(CreateProcess(NULL, buf, NULL, NULL, FALSE, 0,
		NULL, NULL, &cif, &pi)))
		std::wcout << "Error " << '\n';
	getchar();
	//------------------------------------


	//------------1A-----------------------
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind = INVALID_HANDLE_VALUE;

	TCHAR directorySearch[] = TEXT("C:\\work\\*");
	TCHAR filesearch[] = TEXT("C:\\work\\dat*.txt");
	// Find the first file in the directory.
	hFind = FindFirstFile(filesearch, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf("Invalid file handle. Error is %u.\n", GetLastError());
	}
	else
	{
		std::wcout << "Found: " << FindFileData.cFileName << '\n';

		// List all the other files in the directory.
		while (FindNextFile(hFind, &FindFileData) != 0)
		{
			std::wcout << "Found: " << FindFileData.cFileName << '\n';
		}
		FindClose(hFind);

	}

	getchar();
	//------------------------------------

	return 0;
}
