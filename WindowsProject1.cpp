// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include <stdio.h>
#include <string>
#include "WindowsProject1.h"
#include "Stack.h"
#include "controller.h"
#include "CAboutDialog.h"



// Отправить объявления функций, включенных в этот модуль кода:
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	CAboutDialog Dialog;
	//DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, &CAboutDialog::About);
}
/*
// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	Stack st;
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
	
    case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON1) {
			char tipa_string[1000];
			GetDlgItemTextA(hDlg, IDC_EDIT1, (LPSTR)tipa_string, 1000);
			Controller.AddPinguin(std::string(tipa_string));
			//st.PushBack(std::string(tipa_string));
			ShowPinguin(Controller.Top(), hDlg);
		}

		if (LOWORD(wParam) == IDC_BUTTON2) {
			Controller.PopBack();
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, Controller.Size(), 0);
		}

		if (LOWORD(wParam) == IDC_BUTTON3) {
			char buf[100];
			SendDlgItemMessage(hDlg, IDC_LIST2, LB_RESETCONTENT, 0, (LPARAM)buf);	
			int size = Controller.Size();
			sprintf_s(buf, 100, "%10d", size);
			SendDlgItemMessage(hDlg, IDC_LIST2, LB_ADDSTRING, 0, (LPARAM)buf);
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

void ShowPinguin(std::string s, HWND hDlg ) {
	char buf[1000];
	strcpy_s(buf, s.c_str());
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)buf);
}
*/
