#include <windows.h>
#include <tchar.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
	HANDLE hOut;
	TCHAR stdPath[] = TEXT("C:\\Users\\Admin\\Documents\\my_api2.txt");

	hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE) {
		_tprintf_s(TEXT("Error: %x.\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
	{
		_tprintf_s(TEXT("Created.\n"));
		_tsystem(TEXT("pause"));
		CloseHandle(hOut);
	}

	return EXIT_SUCCESS;
}
