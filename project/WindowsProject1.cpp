// WindowsProject1.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include <stdio.h>
#include <string>
#include "WindowsProject1.h"
#include "Stack.h"

// Отправить объявления функций, включенных в этот модуль кода:
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1),NULL, About);
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static Stack st;
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
	
    case WM_COMMAND:
		if (LOWORD(wParam) == IDC_BUTTON1) {
			BOOL bSuccess;
			BOOL bSigned = FALSE;
			int value  = GetDlgItemInt(hDlg, IDC_EDIT1, &bSuccess, bSigned);
			st.PushBack(value);
			char buf[100];
			sprintf_s(buf, 100, "%10d", st.Top());
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)buf);
		}

		if (LOWORD(wParam) == IDC_BUTTON2) {
			st.PopBack();
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, st.Size(), 0);
		}

		if (LOWORD(wParam) == IDC_BUTTON3) {
			char buf[100];
			SendDlgItemMessage(hDlg, IDC_LIST2, LB_RESETCONTENT, 0, (LPARAM)buf);			
			sprintf_s(buf, 100, "%10d", st.Size());
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

