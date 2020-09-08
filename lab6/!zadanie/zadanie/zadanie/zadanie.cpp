//#include <stdafx.h>
#include <string.h>
#include <stdio.h>
#include <Windows.h>
//#include <tchar.h>
//#include <fstream>
#include <iostream>
using namespace std;
int main()
{
	TCHAR New_Directory[] = TEXT("C:\\OSLABS\\TASK2.1");
	TCHAR New_Directory2[] = TEXT("C:\\OSLABS\\TASK2.2");
	DWORD dwNumberOfBytes;
	BOOL pr2 = 0;
	if (CreateDirectory(New_Directory, NULL) && CreateDirectory(New_Directory2, NULL))
	{
		cout << "directories has been created" << endl;
	}
	else
	{
		cout << "Nothing happened" << endl;
	}
	TCHAR PATH1[40] = TEXT("C:\\OSLABS\\TASK2.1\\Path1.txt");
	TCHAR PATH2[40] = TEXT("C:\\OSLABS\\TASK2.2\\Path2.txt");
	HANDLE HOUT = CreateFile(PATH1 /*����*/, GENERIC_WRITE /*����� �� ����������*/, 0, NULL /*�������� ������������*/, CREATE_NEW /*�������� ������ �����*/, FILE_ATTRIBUTE_NORMAL /*��� ��������*/, NULL /*���� �������*/);
	if (HOUT == INVALID_HANDLE_VALUE)
	{
		cout << "ERROR" << GetLastError() << endl;
		return 2;
	}
	else
	{
		TCHAR NEWTEXT[256] = TEXT("IDET KOZA ROGATAYA...");
		WriteFile(HOUT, NEWTEXT, 256 /*����� ���� ��� ������*/, &dwNumberOfBytes, NULL);
		cout << "File has been created and something has been written into it" << endl;
		CloseHandle(HOUT);

	}

	BOOL CopyText = CopyFile(PATH1, PATH2, pr2);/* �������� ������������� ��� ���*/
	if (CopyText)
	{
		cout << "Success" << endl;
	}
	else
	{
		cout << "Nothing happened" << endl;
	}

	BOOL DELETETEST = DeleteFile(PATH1);//�������� ��������� ��
	if (DELETETEST)
	{
		cout << "Succesfully deleted" << endl;
	}
	else
	{
		cout << "Nothing happened" << endl;
	}

	TCHAR RENAMED[40] = TEXT("C:\\OSLABS\\TASK2.2\\Path3.txt");
	BOOL TRANSFERTEST = MoveFile(PATH2, RENAMED);
	if (TRANSFERTEST)
	{
		cout << "Successfully renamed" << endl;
	}
	else
	{
		cout << "Nothing happened" << endl;
	}
	HANDLE HIN = CreateFile(RENAMED /*����*/, GENERIC_READ /*�� ����� ����������*/, 0, NULL/* �������� ������������*/, OPEN_EXISTING /*������� ������������*/, FILE_ATTRIBUTE_NORMAL/*��� ��������*/, NULL /*���� �������*/);
	TCHAR BUFFER[256];
	DWORD DWNUMBER;
	if (HIN == INVALID_HANDLE_VALUE)
	{
		cout << "ERROR" << GetLastError() << endl;
		return 2;
	}
	else
	{
		ReadFile(HIN, BUFFER, 256, &DWNUMBER, NULL);
		wcout << "we found something incredible in this file..." << BUFFER << endl;
		CloseHandle(HIN);
	}
	return 0;
}