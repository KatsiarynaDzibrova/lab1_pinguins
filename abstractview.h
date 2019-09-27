#pragma once
#include <iostream>
#include "framework.h"

class  AbstractView {
public:
	virtual ~AbstractView() = default;

	virtual void NewPinguinPressed() = 0;
	virtual void DeletePinguinPressed() = 0;
	virtual void IfEqualPressed() = 0;
	virtual void ChangeSize() = 0;
	virtual void SetIfEqual(std::string tr) = 0;
	virtual void setDialog(HWND dlg) = 0;
	virtual void ShowPinguin(std::string s) = 0;
	virtual void HidePinguin() = 0;

	virtual void UpButton() = 0;
	virtual void DownButton() = 0;
	virtual void ShowPicked(std::string tr) = 0;
};