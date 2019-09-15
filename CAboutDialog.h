#pragma once
#include "controller.h"
class CAboutDialog
{
public:
	// Отправить объявления функций, включенных в этот модуль кода:
	static INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
	
	static void ShowPinguin(std::string s, HWND hDlg);
	static void HidePinguin(HWND hDlg);
	
};
