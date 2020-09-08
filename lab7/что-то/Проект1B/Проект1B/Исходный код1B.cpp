#include <windows.h>
#include <tchar.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
	DWORD processID;
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	TCHAR buf[] = TEXT("mspaint.exe");

	processID = CreateProcess(NULL, buf, NULL, NULL, FALSE, NULL,
		NULL, NULL, &cif, &pi);

	_tprintf_s(TEXT("Running with PID: %d.\n"), pi.dwProcessId);

	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}
