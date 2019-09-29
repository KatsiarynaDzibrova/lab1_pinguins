// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include <stdio.h>
#include <string>
#include "WindowsProject1.h"
#include "Stack.h"
#include "controller.h"
#include "MainWindowView.h"



// Отправить объявления функций, включенных в этот модуль кода:
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
HINSTANCE hInst;
HBITMAP hBitmap;
HWND hPic;


MainWindowView View;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	hInst = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, &About);

}


INT_PTR CALLBACK    About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	View.setDialog(hDlg);
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		hBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		hPic = GetDlgItem(hDlg, IDC_PICTURE);
		View.UpButton();
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON1) {
			View.NewPinguinPressed();
		}

		if (LOWORD(wParam) == IDC_BUTTON2) {
			View.DeletePinguinPressed();
		}

		if (LOWORD(wParam) == IDC_BUTTON3) {
			
			View.ChangeSize();
		}

		if (LOWORD(wParam) == IDC_BUTTON4) {
			View.IfEqualPressed();
		}

		if (LOWORD(wParam) == IDC_BUTTON5) {
			View.DownButton();
		}

		if (LOWORD(wParam) == IDC_BUTTON6) {
			View.UpButton();
		}

		if (LOWORD(wParam) == IDC_BUTTON8) {
			View.ChangeName();
		}


		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	case WM_PAINT:
		BITMAP bm;
		PAINTSTRUCT ps;

		HDC hdc = BeginPaint(hPic, &ps);
		HDC hdcMem = CreateCompatibleDC(hdc);
		HGDIOBJ hbmOld = SelectObject(hdcMem, hBitmap);
		GetObject(hBitmap, sizeof(bm), &bm);
		BitBlt(hdc, 0, 0, bm.bmWidth, bm.bmHeight, hdcMem, 0, 0, SRCCOPY);
		SelectObject(hdcMem, hbmOld);
		DeleteDC(hdcMem);
		EndPaint(hPic, &ps);
	}
	return (INT_PTR)FALSE;
}