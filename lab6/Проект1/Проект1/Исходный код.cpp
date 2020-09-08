#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <locale.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
	_tsetlocale(LC_ALL, TEXT("Rus"));
	FILE* fp;
	TCHAR str[80];
	if ((fp = _tfopen(TEXT("C:\\Users\\Admin\\Documents\\c_api.txt"), TEXT("rt"))) == NULL)
	{
		_tprintf_s(TEXT("Opening failed\n"), str);
	}
	else
	{
		_fgetts(str, sizeof(str) / sizeof(TCHAR), fp);
		_tprintf_s(TEXT("read: %s\n"), str);
		INT z = fclose(fp);
	}
	system("pause");
	return EXIT_SUCCESS;
}
