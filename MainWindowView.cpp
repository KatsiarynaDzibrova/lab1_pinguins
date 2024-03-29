#include <windows.h>

#include "MainWindowView.h"
#include <string>
#include "resource.h"
#include "controller.h"



MainWindowView::MainWindowView() {
	Controller = new controller(this);
}

MainWindowView::~MainWindowView() {
	delete Controller;
}


void MainWindowView::NewPinguinPressed() {
	char tipa_string[100];
	GetDlgItemTextA(hDlg, IDC_EDIT1, (LPSTR)tipa_string, 100);
	Controller->AddPinguin(std::string(tipa_string));
}

void MainWindowView::DeletePinguinPressed() {
	Controller->PopBack();
}

void MainWindowView::IfEqualPressed() {
	Controller->IfEqual();
}

void MainWindowView::ShowPinguin(std::string s) {
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)s.c_str());
}

void MainWindowView::HidePinguin() {
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, Controller->Size(), 0);
}

void MainWindowView::ChangeSize() {
	char buf[100];
	SendDlgItemMessage(hDlg, IDC_LIST2, LB_RESETCONTENT, 0, 0);
	sprintf_s(buf, 100, "%10d", Controller->Size());
	SendDlgItemMessage(hDlg, IDC_LIST2, LB_ADDSTRING, 0, (LPARAM)buf);
}

void MainWindowView::SetIfEqual(std::string tr) {
	SendDlgItemMessage(hDlg, IDC_LIST3, LB_RESETCONTENT, 0, 0);
	SendDlgItemMessage(hDlg, IDC_LIST3, LB_ADDSTRING, 0, (LPARAM)tr.c_str());
}

void MainWindowView::RandomCrowd() {
	Controller->GenerateCrowd();
}

void MainWindowView::ShowRandomCrowd() {
	SendDlgItemMessage(hDlg, IDC_LIST4, LB_RESETCONTENT, 0, 0);
	for (int i = 0; i < Controller->crowd.GetSize(); i++) {
		SendDlgItemMessage(hDlg, IDC_LIST4, LB_ADDSTRING, 0,
			(LPARAM)(Controller->crowd.GetHumanWithIndex(i)).c_str());
	}
}


void MainWindowView::TimeToVisitCrowd() {
	Controller->CrowdVisit();
}

void MainWindowView::UpdateCrowd() {
	SendDlgItemMessage(hDlg, IDC_LIST4, LB_RESETCONTENT, 0, 0);
	for (int i = 0; i < Controller->crowd.GetSize(); i++) {
		SendDlgItemMessage(hDlg, IDC_LIST4, LB_ADDSTRING, 0,
			(LPARAM)(Controller->crowd.GetHumanWithIndex(i)).c_str());
	}
}


void MainWindowView::TimeToVisitStack() {
	Controller->StackVisit();
}


void MainWindowView::setDialog(HWND dlg) {
	hDlg = dlg;
}

void MainWindowView::UpButton() {
	Controller->GoUp();
}

void MainWindowView::DownButton() {
	Controller->GoDown();
}

void MainWindowView::ShowPicked(std::string tr)
{
	SetDlgItemText(hDlg, IDC_EDIT2, (LPCSTR)tr.c_str());
}


void MainWindowView::ChangeName() {
	char s[100];
	GetDlgItemTextA(hDlg, IDC_EDIT2, (LPSTR)s, 100);
	Controller->ChangeCurrentName(std::string(s));
}

void MainWindowView::ClearView() {
	for (int i = Controller->Size() - 1; i >= 0; --i) {
		SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, i, 0);
	}
}