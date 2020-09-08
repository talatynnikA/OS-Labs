#include <windows.h>
#include <tchar.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");

	if (!CreateProcess(NULL, buf, NULL, NULL, FALSE, NULL,
		NULL, NULL, &cif, &pi)) {
		_tprintf_s(TEXT("Not running.\n"));
	}
	_tprintf_s(TEXT("Running.\n"));

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	HANDLE hProcess = GetCurrentProcess(); //получаем pID консольного приложен.

	if (NULL != hProcess)
	{
		Sleep(200);
		BOOL result = TerminateProcess(hProcess, EXIT_SUCCESS);

		CloseHandle(hProcess);
	}
	else
	{
		_tprintf_s(TEXT("Error when terminating.\n"));
	}

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}






