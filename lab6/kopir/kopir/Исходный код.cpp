#include <windows.h>
#include <tchar.h>
#include <fstream>
#include <locale>

INT _tmain(INT argc, _TCHAR* argv[])
{
	TCHAR stdPathA[] = TEXT("C:\\Users\\Admin\\Documents\\my_api2.txt");
	TCHAR stdPathB[] = TEXT("C:\\Users\\Admin\\Documents\\my_api3.txt");

	BOOL pr = CopyFile(stdPathA, stdPathB, 0);
	if (pr)
	{
		_tprintf_s(TEXT("Copied.\n"));
	}
	else
	{
		_tprintf_s(TEXT("Not copied.\n"));
	}

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}
