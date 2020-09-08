#include <windows.h>
#include <tchar.h>
#include <locale>

INT _tmain(INT argc, _TCHAR* argv[])
{
	_tsetlocale(LC_ALL, TEXT("Rus"));
	TCHAR Buffer[] = TEXT("C:\\Users\\Admin\\Documents\\newText");

	if (CreateDirectory(Buffer, NULL)) {
		_tprintf_s(TEXT("Directory created.\n"));
	}
	else {
		_tprintf_s(TEXT("Directory didn't created.\n"));
	}

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}

