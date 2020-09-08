#include <windows.h>
#include <tchar.h>
#include <locale>

INT _tmain(INT argc, _TCHAR* argv[])
{
	_tsetlocale(LC_ALL, TEXT("Rus"));
	TCHAR Buffer[] = TEXT("Glad to hear from You! Привет Мир!");
	HANDLE hOut;
	DWORD dwNumberOfBytes;

	TCHAR stdPath[] = TEXT("C:\\Users\\Admin\\Documents\\my_api2.txt");
	hOut = CreateFile(stdPath, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hOut == INVALID_HANDLE_VALUE) {
		_tprintf_s(TEXT("Error: %x.\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
	{
		WriteFile(hOut, Buffer, sizeof(Buffer), &dwNumberOfBytes, NULL);
		_tprintf_s(TEXT("Created and Written!\n"));
		_tsystem(TEXT("pause"));
		CloseHandle(hOut);
	}

	return EXIT_SUCCESS;

}
