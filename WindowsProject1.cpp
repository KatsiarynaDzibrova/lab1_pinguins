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
controller Controller;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, &About);
}


INT_PTR CALLBACK    About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static Stack stack2;
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		stack2.PushBack("Jake");
		stack2.PushBack("Finn");
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON1) {
			char tipa_string[100];
			GetDlgItemTextA(hDlg, IDC_EDIT1, (LPSTR)tipa_string, 100);
			View.Controller->AddPinguin(std::string(tipa_string));

			View.ShowPinguin(View.Controller->Top(), hDlg);
		}

		if (LOWORD(wParam) == IDC_BUTTON2) {
			View.Controller->PopBack();
			View.HidePinguin(hDlg);
		}

		if (LOWORD(wParam) == IDC_BUTTON3) {
			char buf[100];
			SendDlgItemMessage(hDlg, IDC_LIST2, LB_RESETCONTENT, 0, 0);
			sprintf_s(buf, 100, "%10d", View.Controller->Size());
			SendDlgItemMessage(hDlg, IDC_LIST2, LB_ADDSTRING, 0, (LPARAM)buf);
		}

		if (LOWORD(wParam) == IDC_BUTTON4) {
			if (View.Controller->Compare(stack2)) {
				char tr[100] = "True";
				SendDlgItemMessage(hDlg, IDC_LIST3, LB_RESETCONTENT, 0, 0);
				SendDlgItemMessage(hDlg, IDC_LIST3, LB_ADDSTRING, 0, (LPARAM)tr);
			}
			else {
				char fals[100] = "False";
				SendDlgItemMessage(hDlg, IDC_LIST3, LB_RESETCONTENT, 0, 0);
				SendDlgItemMessage(hDlg, IDC_LIST3, LB_ADDSTRING, 0, (LPARAM)fals);
			}
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