// lab4.cpp: ���������� ����� ����� ��� ����������.
//

#include "stdafx.h"
#include "lab4.h"

#define MAX_LOADSTRING 100

// ���������� ����������:
HINSTANCE hInst; // ������� ���������
TCHAR szTitle[MAX_LOADSTRING]; // ����� ������ ���������
TCHAR szWindowClass[MAX_LOADSTRING]; // ��� ������ �������� ����
int colmn = 1, i = 1;

// ��������� ���������� �������, ���������� � ���� ������ ����:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK myDialog(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK myF(HWND, UINT, WPARAM , LPARAM );

HWND  button;
HWND hWnd3;

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
						_In_opt_ HINSTANCE hPrevInstance,
						_In_ LPTSTR lpCmdLine,
						_In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: ���������� ��� �����.
	MSG msg;
	HACCEL hAccelTable;

	// ������������� ���������� �����
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LAB4, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ��������� ������������� ����������:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB4));

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
// �������: MyRegisterClass()
//
// ����������: ������������ ����� ����.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB4));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_LAB4);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
// �������: InitInstance(HINSTANCE, int)
//
// ����������: ��������� ��������� ���������� � ������� ������� ����.
//
// �����������:
//
// � ������ ������� ���������� ���������� ����������� � ���������� ����������, � �����
// ��������� � ��������� �� ����� ������� ���� ���������.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd, button, hWnd2, hWnd3;

	hInst = hInstance; // ��������� ���������� ���������� � ���������� ����������

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
// �������: WndProc(HWND, UINT, WPARAM, LPARAM)
//
// ����������: ������������ ��������� � ������� ����.
//
// WM_COMMAND - ��������� ���� ����������
// WM_PAINT - ��������� ������� ����
// WM_DESTROY - ������ ��������� � ������ � ���������.	
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//HWND  button, hWnd2, hWnd3;
	TCHAR str[] = TEXT("SampleText");
	int responce = 0;


	switch (message)
	{
	case WM_CREATE:
	{
					   button = CreateWindowEx(
						  NULL,
						  TEXT("Button"),
						  TEXT("Press me"),
						  WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
						  100,
						  100,
						  100,
						  24,
						  hWnd,
						  HMENU(IDC_MYBUTTON),
						  hInst,
						  nullptr
						  );
					  ShowWindow(button, 1);

					hWnd3 = CreateWindowEx(
						  NULL,
						  TEXT("Button"),
						  TEXT("Exit"),
						  WS_TABSTOP | WS_VISIBLE |
						  WS_CHILD | BS_DEFPUSHBUTTON,
						  500, 
						  70, 
						  50, 
						  30,
						  hWnd,
						  HMENU(IDC_MYBUTTON_EXIT),
						  hInst,
						  NULL);
					  ShowWindow(hWnd3, 1);

	}
		break;

	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		if (LOWORD(wParam) == IDC_MYBUTTON &&
			HIWORD(wParam) == BN_CLICKED &&
			(HWND)lParam == button)
		{
			DialogBox(hInst, (LPCTSTR)IDD_DIALOG1, hWnd, (DLGPROC)myF);
		}
		if (LOWORD(wParam) == IDC_MYBUTTON_EXIT &&
			HIWORD(wParam) == BN_CLICKED &&
			(HWND)lParam == hWnd3)
		{
			DestroyWindow(hWnd);
			break;
		}
		// ��������� ����� � ����:
		switch (wmId)
		{
		case IDC_MYBUTTON:
		{
							 if (wmEvent == BN_CLICKED) {
								 DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
							 }
							 break;
		}
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;

		case IDM_EXIT:
		{
						 DestroyWindow(hWnd);
						 break;
				}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
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

	//case WM_RBUTTONDOWN: //����� ����������� ���� ���
	//{
	//						 DialogBox(hInst, (LPCTSTR)IDD_DIALOG1, hWnd, (DLGPROC)myDialog);
	//						 break;
	//}

	/*case WM_CHAR:
		switch (wParam){
		case '>':
			hdc = GetDC(hWnd);
			TextOut(hdc, i, colmn, TEXT(" "), 3);
			TextOut(hdc, i += 3, colmn, str, 7);

			ReleaseDC(hWnd, hdc);
			break;*/
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			/*hdc = GetDC(hWnd);
			TextOut(hdc, i, colmn, TEXT(" "), 3);
			TextOut(hdc, i, colmn += 3, str, 7);
			ReleaseDC(hWnd, hdc);
			break;*/
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}

	
	


LRESULT CALLBACK myDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			int z = MessageBoxEx(NULL, TEXT("HELLO"), TEXT("DialogWin"), MB_OK, 0x0409);
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}

		break;
	}
	return FALSE;
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
static HBRUSH hBrush;
LRESULT CALLBACK myF(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			int z = MessageBoxEx(NULL, TEXT("HELLO"), TEXT("DialogWin"), MB_OK, 0x0409);
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		else	if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}

		break;
	}
	return FALSE;
}