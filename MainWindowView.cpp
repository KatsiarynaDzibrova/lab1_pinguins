#include <windows.h>

#include "MainWindowView.h"
#include <string>
#include "resource.h"
#include "controller.h"


MainWindowView::MainWindowView() {
	Controller = new controller;
}

MainWindowView::~MainWindowView() {
	delete Controller;
}

void MainWindowView::ShowPinguin(std::string s, HWND hDlg) {
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)s.c_str());
}

void MainWindowView::HidePinguin(HWND hDlg) {
	SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, Controller->Size(), 0);
}
