// consol_paint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

#include <windows.h>

HWND HMainwnd = NULL; //������
HWND HButton = NULL;
int run(); //��Ϣѭ������
bool InitWindowsApp(HINSTANCE instanceHandle, int show); //�����ʼ������
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);//���崦��

int tag = 1;
int tag1 = 12;

int main(int argc, char* argv[], HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    cout << "Hello World!\n"; 
	if (!InitWindowsApp(hInstance, nShowCmd)) {
		cout << "��ʼ��ʧ��" << endl;
	}
	run();
}

bool InitWindowsApp(HINSTANCE stanceHandle, int show) {
	WNDCLASS wc; //������ṹ��
	wc.style = CS_HREDRAW | CS_VREDRAW; //������
	wc.lpfnWndProc = WndProc; //���崦����
	wc.cbClsExtra = 0; //�������Ƿ�����չ
	wc.cbWndExtra = 0; //����ʵ���Ƿ�����չ
	wc.hInstance = stanceHandle; //������
	wc.hIcon = LoadIcon(0, IDI_APPLICATION); //����ͼ��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); //���������ʽ
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //���屳����ɫ
	wc.lpszMenuName = NULL; //����˵�
	wc.lpszClassName = L"BaseWndClass"; //��������
	if (!RegisterClass(&wc)) {
		MessageBox(0, L"ע��ʧ��", 0, 0);
		return false;
	}
	//��������
	HMainwnd = CreateWindowEx(WS_EX_WINDOWEDGE,L"BaseWndClass", //��������
		L"My form", //���������
		WS_BORDER, //������
		CW_USEDEFAULT,
		CW_USEDEFAULT, //��������
		650, //�����
		390, //�����
		NULL, //����ĸ�����
		NULL, //������Ӳ˵�
		stanceHandle, //������
		NULL); // ��������ɹ�������ֵΪ�´��ڵľ�����������ʧ�ܣ�����ֵΪNULL

	//ȥ������
	//SetWindowLong(HMainwnd, GWL_STYLE, GetWindowLong(HMainwnd, GWL_STYLE) & ~WS_CAPTION);

	//ȥ�߿�
	//SetWindowLong(HMainwnd, GWL_EXSTYLE, GetWindowLong(HMainwnd, GWL_EXSTYLE) & ~(WS_EX_WINDOWEDGE | WS_EX_DLGMODALFRAME));

	if (HMainwnd == 0)//�жϴ��������Ƿ�ɹ�
	{
		MessageBox(0, L"��������ʧ��", 0, 0);
		return false;
	}
	ShowWindow(HMainwnd, SW_SHOW); //��ʾ����
	ShowWindow(HButton, SW_SHOW); //��ʾ����
	UpdateWindow(HMainwnd); //���ƴ��壻
	UpdateWindow(HButton); //���ƴ��壻
	return true;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE       hInstance;       //����ʵ��
	static HWND     hwndButton[10];   //��ť���
	static HWND     edit;             //�ı���

	switch (message)
	{
	case WM_CREATE: //������ť
	{
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		//��ť1
		hwndButton[0] = CreateWindow(L"BUTTON", L"1",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 20, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		//��ť2
		hwndButton[1] = CreateWindow(L"BUTTON", L"2",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 50, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		hwndButton[2] = CreateWindow(L"BUTTON", L"3",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 80, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		hwndButton[3] = CreateWindow(L"BUTTON", L"4",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 110, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		hwndButton[4] = CreateWindow(L"BUTTON", L"5",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 140, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		hwndButton[5] = CreateWindow(L"BUTTON", L"6",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 170, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		hwndButton[6] = CreateWindow(L"BUTTON", L"7",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 200, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		hwndButton[7] = CreateWindow(L"BUTTON", L"8",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 230, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		hwndButton[8] = CreateWindow(L"BUTTON", L"9",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 260, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		hwndButton[9] = CreateWindow(L"BUTTON", L"10",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 290, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		//���������ı���ؼ�
		edit = CreateWindowEx(WS_EX_CLIENTEDGE,TEXT("static"), TEXT("11111"),
			WS_CHILD /*�Ӵ���*/ | WS_VISIBLE /*����ʱ��ʾ*/ | WS_BORDER /*���߿�*/ | SS_LEFT /*ˮƽ����*/ ,
			20, 20, 490, 300,
			hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL
		);
		return 0;
	}
	case WM_COMMAND: //��Ӧ��ť��Ϣ
		if ((HWND)lParam == hwndButton[0])
		{
			tag1 = 1;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if ((HWND)lParam == hwndButton[1])
		{
			tag1 = 2;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if ((HWND)lParam == hwndButton[2])
		{
			tag1 = 3;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if ((HWND)lParam == hwndButton[3])
		{
			tag1 = 4;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if ((HWND)lParam == hwndButton[4])
		{
			tag1 = 5;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if ((HWND)lParam == hwndButton[5])
		{
			tag1 = 6;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if ((HWND)lParam == hwndButton[6])
		{
			tag1 = 7;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if ((HWND)lParam == hwndButton[7])
		{
			tag1 = 8;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if ((HWND)lParam == hwndButton[8])
		{
			tag1 = 9;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		if ((HWND)lParam == hwndButton[9])
		{
			tag1 = 10;
			if (tag1 == tag) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		//_sleep(1 * 1000);
		DestroyWindow(hwnd);
		return 0;
	case WM_CLOSE: //�ر�
		//if (IDYES == MessageBox(hwnd, L"�Ƿ�رճ���?", L"��ʾ", MB_YESNO | MB_ICONQUESTION))
		//{
		DestroyWindow(hwnd);
		//}
		return 0;
	case WM_DESTROY: //�˳�����
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

int run()
{
	MSG msg = { 0 }; //��Ϣ�ṹ
	BOOL bRet = 1; //��ȡ��Ϣ
	while ((bRet = GetMessage(&msg, 0, 0, 0)) != 0)//��Ϣѭ��
	{
		if (bRet == -1)//�ж���Ϣ�Ƿ����ʧ��
		{
			MessageBox(0, L"������Ϣʧ��", 0, 0);
			break;
		}
		else
		{
			TranslateMessage(&msg); //ת����ϢΪ�ַ���Ϣ
			DispatchMessage(&msg); //������Ϣ������
		}
	}
	return (int)msg.wParam;
}

