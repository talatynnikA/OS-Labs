#include <windows.h>
#include <tchar.h>
#include <locale>

INT _tmain(INT argc, _TCHAR* argv[])
{
	_tsetlocale(LC_ALL, TEXT("Rus"));
	TCHAR Buffer[MAX_PATH];
	TCHAR Buffer2[] = TEXT("C:\\Users\\Admin\\Documents\\text");

	DWORD dwResult = GetCurrentDirectory(MAX_PATH, Buffer);
	_tprintf_s(TEXT("Dir: %s.\n"), Buffer);

	BOOL b = SetCurrentDirectory(Buffer2);

	dwResult = GetCurrentDirectory(MAX_PATH, Buffer);
	_tprintf_s(TEXT("Dir: %s.\n"), Buffer);
	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}

