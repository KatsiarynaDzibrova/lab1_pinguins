#pragma once
#include "controller.h"
class CAboutDialog
{
public:
	// ��������� ���������� �������, ���������� � ���� ������ ����:
	static INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
	
	static void ShowPinguin(std::string s, HWND hDlg);
	static void HidePinguin(HWND hDlg);
	
};
