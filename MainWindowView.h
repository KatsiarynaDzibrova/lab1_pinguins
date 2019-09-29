#pragma once

#include "abstractview.h"
#include "abstractcontroller.h"
#include "framework.h"

class MainWindowView : public AbstractView
{
public:
	~MainWindowView();
	MainWindowView();
	void NewPinguinPressed() override;
	void DeletePinguinPressed() override;
	void IfEqualPressed() override;
	void setDialog(HWND dlg) override;
	void ChangeSize() override;
	void SetIfEqual(std::string tr) override;
	void ShowPinguin(std::string s) override;
	void HidePinguin() override;

	void UpButton() override;
	void DownButton() override;
	void ShowPicked(std::string tr) override;
	void ChangeName() override;
	void ClearView() override;

private:
	AbstractController* Controller;
	HWND hDlg;
	
};
