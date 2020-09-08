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
		_tprintf_s(TEXT("Error.\n"));
	}
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}

