#include <iostream>
#include <Windows.h>
#include "framework.h"
#include "TextWin.h"

#define MAX_LOADSTRING 100
#define IDS_APP_TITLE                   103
#define IDR_MAINFRAME                   128
#define IDD_L41_DIALOG  102
#define IDD_ABOUTBOX                    103
#define IDM_ABOUT                       104
#define IDM_EXIT                        105
#define IDI_L41         107
#define IDI_SMALL                       108
#define IDC_L41         109
#define IDC_MYICON                      2
#ifndef IDC_STATIC
#define IDC_STATIC                      -1
#endif

#ifdef APSTUDIO_INVOKED
#ifdef APSTUDIO_READONLY_SYMBOLS

#define _APS_NO_MFC                    130
#define _APS_NEXT_RECOURCE_VALUE	   129
#define _APS_NEXT_COMMAND_VALUE	       32771
#define _APS_NEXT_CONTROL_VALUE	       1000
#define _APS_NEXT_SYMED_VALUE	       110
#endif
#endif

// ���������� ����������:
HINSTANCE hInst;                                // ������� ���������
WCHAR szTitle[MAX_LOADSTRING];                  // ����� ������ ���������
WCHAR szWindowClass[MAX_LOADSTRING];            // ��� ������ �������� ����

// ��������� ���������� �������, ���������� � ���� ������ ����:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: ���������� ��� �����.

	// ������������� ���������� �����
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_TEXTWIN, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ��������� ������������� ����������:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TEXTWIN));

	MSG msg;

	// ���� ��������� ���������:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  �������: MyRegisterClass()
//
//  ����: ������������ ����� ����.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TEXTWIN));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_TEXTWIN);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   �������: InitInstance(HINSTANCE, int)
//
//   ����: ��������� ������ ���������� � ������� ������� ����
//
//   �����������:
//
//        � ���� ������� ������ ���������� ����������� � ���������� ����������, � �����
//        ��������� � ��������� ������� ���� ���������.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // ��������� ������ ���������� � ���������� ����������

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  �������: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����: ������������ ��������� � ������� ����.
//
//  WM_COMMAND  - ���������� ���� ����������
//  WM_PAINT    - ��������� �������� ����
//  WM_DESTROY  - ��������� ��������� � ������ � ���������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
					   int wmId = LOWORD(wParam);
					   // ��������� ����� � ����:
					   switch (wmId)
					   {
					   case IDM_ABOUT:
						   DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
						   break;
					   case IDM_EXIT:
						   DestroyWindow(hWnd);
						   break;
					   default:
						   return DefWindowProc(hWnd, message, wParam, lParam);
					   }
	}
		break;
	case WM_PAINT:
	{
					 PAINTSTRUCT ps;
					 HDC hdc = BeginPaint(hWnd, &ps);
					 // TODO: �������� ���� ����� ��� ����������, ������������ HDC...
					 EndPaint(hWnd, &ps);
	}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// ���������� ��������� ��� ���� "� ���������".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

