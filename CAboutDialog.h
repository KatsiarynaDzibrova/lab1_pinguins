#pragma once
#include "controller.h"
#include "abstractview.h"
class CAboutDialog 
{
public:
	// ��������� ���������� �������, ���������� � ���� ������ ����:
	static INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
	CAboutDialog();
	static void ShowPinguin(std::string s, HWND hDlg);
	static void HidePinguin(HWND hDlg);

	
};
