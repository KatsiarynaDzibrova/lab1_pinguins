#include <windows.h>

#include "CAboutDialog.h"
#include <string>
#include "resource.h"

controller Controller;

INT_PTR CALLBACK    CAboutDialog::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
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
			HidePinguin(hDlg);
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
void CAboutDialog::ShowPinguin(std::string s, HWND hDlg) {
	char buf[1000];
	strcpy_s(buf, s.c_str());
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)buf);
}

void CAboutDialog::HidePinguin(HWND hDlg) {
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, Controller.Size(), 0);
}
