#include <windows.h>
#include <tchar.h>
#include <fstream>
INT _tmain(INT argc, _TCHAR* argv[])
{
	TCHAR stdPathA[] = TEXT("C:\\Users\\Admin\\Documents\\my_api3.txt");
	TCHAR stdPathB[] = TEXT("C:\\Users\\Admin\\Documents\\my_api3a.txt");

	BOOL pr = MoveFile(stdPathA, stdPathB);
	if (pr)
	{
		_tprintf_s(TEXT("Moved.\n"));
	}
	else
	{
		_tprintf_s(TEXT("Not moved.\n"));
	}

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}

