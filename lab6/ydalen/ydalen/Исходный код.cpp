#include <windows.h>
#include <tchar.h>
#include <fstream>

INT _tmain(INT argc, _TCHAR* argv[])
{
	TCHAR stdPathA[] = TEXT("C:\\Users\\Admin\\Documents\\my_api3a.txt");

	BOOL pr = DeleteFile(stdPathA);
	if (pr)
	{
		_tprintf_s(TEXT("Deleted.\n"));
	}
	else
	{
		_tprintf_s(TEXT("Not deleted.\n"));
	}

	_tsystem(TEXT("pause"));
	return EXIT_SUCCESS;
}
