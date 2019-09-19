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


MainWindowView View;


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, &About);
}


INT_PTR CALLBACK    About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	View.setDialog(hDlg);
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
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


		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}