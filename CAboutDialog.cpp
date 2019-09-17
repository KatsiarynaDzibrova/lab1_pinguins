#include <windows.h>

#include "CAboutDialog.h"
#include <string>
#include "resource.h"

controller Controller;

CAboutDialog::CAboutDialog() {
	DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), NULL, &CAboutDialog::About);
}

INT_PTR CALLBACK    CAboutDialog::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
			SendDlgItemMessage(hDlg, IDC_LIST2, LB_RESETCONTENT, 0, 0);
			sprintf_s(buf, 100, "%10d", Controller.Size());
			SendDlgItemMessage(hDlg, IDC_LIST2, LB_ADDSTRING, 0, (LPARAM)buf);
		}

		if (LOWORD(wParam) == IDC_BUTTON4) {
			if (Controller.Compare(stack2)) {
				char tr[100] = "True";
				SendDlgItemMessage(hDlg, IDC_LIST3, LB_RESETCONTENT, 0, 0);
				SendDlgItemMessage(hDlg, IDC_LIST3, LB_ADDSTRING, 0, (LPARAM)tr);
			} else {
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
void CAboutDialog::ShowPinguin(std::string s, HWND hDlg) {
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)s.c_str());
}

void CAboutDialog::HidePinguin(HWND hDlg) {
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, Controller.Size(), 0);
}
