#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <locale.h>

INT _tmain(INT argc, _TCHAR* argv[])
{
	_tsetlocale(LC_ALL, TEXT("Rus"));
	FILE* fp;
	TCHAR str[] = TEXT("Hello World! Привет Мир!");
	TCHAR str2[80];
	if ((fp = _tfopen(TEXT("C:\\Users\\Admin\\Documents\\c_api.txt"), TEXT("wt"))) == NULL)
	{
		_putts(TEXT("Opening failed"));
	}
	else
	{
		_fputts(str, fp);
		INT z = fclose(fp);

		fp = _tfopen(TEXT("C:\\Users\\Admin\\Documents\\c_api.txt"), TEXT("rt"));
		_fgetts(str2, sizeof(str2) / sizeof(TCHAR), fp);
		_tprintf_s(TEXT("read: %s\n"), str2);
		z = fclose(fp);
	}
	system("pause");
	return EXIT_SUCCESS;
}
