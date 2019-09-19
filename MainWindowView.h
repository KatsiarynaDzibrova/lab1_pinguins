#pragma once

#include "abstractview.h"
#include "abstractcontroller.h"
#include "framework.h"
class MainWindowView
{
public:
	~MainWindowView();
	MainWindowView();
	void NewPinguinPressed();
	void DeletePinguinPressed();
	void IfEqualPressed();
	void setDialog(HWND dlg);
	void ChangeSize();
	void SetIfEqual(std::string tr);


	void ShowPinguin(std::string s);
	void HidePinguin();

	AbstractController* Controller;
	HWND hDlg;


};
