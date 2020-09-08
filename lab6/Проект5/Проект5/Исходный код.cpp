#include <windows.h>
#include <tchar.h>
#include <locale>

INT _tmain(INT argc, _TCHAR* argv[])
{
	_tsetlocale(LC_ALL, TEXT("Rus"));
	TCHAR Buffer[256];
	HANDLE hIn;
	DWORD dwNumberOfBytes;

	TCHAR stdPath[] = TEXT("C:\\Users\\Admin\\Documents\\my_api2.txt");

	hIn = CreateFile(stdPath, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hIn == INVALID_HANDLE_VALUE) {
		_tprintf_s(TEXT("Error: %x.\n"), GetLastError());
		return EXIT_FAILURE;
	}
	else
	{
		ReadFile(hIn, Buffer, sizeof(Buffer), &dwNumberOfBytes, NULL);
		_tprintf_s(TEXT("Data read: %s\n"), Buffer);
		_tsystem(TEXT("pause"));
		CloseHandle(hIn);
	}

	return EXIT_SUCCESS;
}
