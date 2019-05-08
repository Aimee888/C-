// consol_paint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

#include <windows.h>

HWND HMainwnd = NULL; //窗体句柄
HWND HButton = NULL;
int run(); //消息循环函数
bool InitWindowsApp(HINSTANCE instanceHandle, int show); //窗体初始化函数
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);//窗体处理

int tag = 1;
int tag1 = 12;

int main(int argc, char* argv[], HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    cout << "Hello World!\n"; 
	if (!InitWindowsApp(hInstance, nShowCmd)) {
		cout << "初始化失败" << endl;
	}
	run();
}

bool InitWindowsApp(HINSTANCE stanceHandle, int show) {
	WNDCLASS wc; //窗体类结构体
	wc.style = CS_HREDRAW | CS_VREDRAW; //窗体风格
	wc.lpfnWndProc = WndProc; //窗体处理函数
	wc.cbClsExtra = 0; //窗体类是否由扩展
	wc.cbWndExtra = 0; //窗体实例是否由扩展
	wc.hInstance = stanceHandle; //窗体句柄
	wc.hIcon = LoadIcon(0, IDI_APPLICATION); //窗体图标
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); //窗体鼠标样式
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //窗体背景颜色
	wc.lpszMenuName = NULL; //窗体菜单
	wc.lpszClassName = L"BaseWndClass"; //窗体类名
	if (!RegisterClass(&wc)) {
		MessageBox(0, L"注册失败", 0, 0);
		return false;
	}
	//创建窗体
	HMainwnd = CreateWindowEx(WS_EX_WINDOWEDGE,L"BaseWndClass", //窗体类名
		L"My form", //窗体标题名
		WS_BORDER, //窗体风格
		CW_USEDEFAULT,
		CW_USEDEFAULT, //窗体坐标
		650, //窗体宽
		390, //窗体高
		NULL, //窗体的父窗体
		NULL, //窗体的子菜单
		stanceHandle, //窗体句柄
		NULL); // 如果函数成功，返回值为新窗口的句柄：如果函数失败，返回值为NULL

	//去标题栏
	//SetWindowLong(HMainwnd, GWL_STYLE, GetWindowLong(HMainwnd, GWL_STYLE) & ~WS_CAPTION);

	//去边框
	//SetWindowLong(HMainwnd, GWL_EXSTYLE, GetWindowLong(HMainwnd, GWL_EXSTYLE) & ~(WS_EX_WINDOWEDGE | WS_EX_DLGMODALFRAME));

	if (HMainwnd == 0)//判断创建窗体是否成功
	{
		MessageBox(0, L"创建窗体失败", 0, 0);
		return false;
	}
	ShowWindow(HMainwnd, SW_SHOW); //显示窗体
	ShowWindow(HButton, SW_SHOW); //显示窗体
	UpdateWindow(HMainwnd); //绘制窗体；
	UpdateWindow(HButton); //绘制窗体；
	return true;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HINSTANCE       hInstance;       //窗口实例
	static HWND     hwndButton[10];   //按钮句柄
	static HWND     edit;             //文本框

	switch (message)
	{
	case WM_CREATE: //创建按钮
	{
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		//按钮1
		hwndButton[0] = CreateWindow(L"BUTTON", L"1",
			WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
			530, 20, 75, 20, hwnd, NULL,
			(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL);
		//按钮2
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
		//创建单行文本框控件
		edit = CreateWindowEx(WS_EX_CLIENTEDGE,TEXT("static"), TEXT("11111"),
			WS_CHILD /*子窗口*/ | WS_VISIBLE /*创建时显示*/ | WS_BORDER /*带边框*/ | SS_LEFT /*水平居左*/ ,
			20, 20, 490, 300,
			hwnd, NULL, (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE), NULL
		);
		return 0;
	}
	case WM_COMMAND: //响应按钮消息
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
	case WM_CLOSE: //关闭
		//if (IDYES == MessageBox(hwnd, L"是否关闭程序?", L"提示", MB_YESNO | MB_ICONQUESTION))
		//{
		DestroyWindow(hwnd);
		//}
		return 0;
	case WM_DESTROY: //退出程序
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

int run()
{
	MSG msg = { 0 }; //消息结构
	BOOL bRet = 1; //获取消息
	while ((bRet = GetMessage(&msg, 0, 0, 0)) != 0)//消息循环
	{
		if (bRet == -1)//判断消息是否接收失败
		{
			MessageBox(0, L"接受消息失败", 0, 0);
			break;
		}
		else
		{
			TranslateMessage(&msg); //转换消息为字符消息
			DispatchMessage(&msg); //发送消息给窗口
		}
	}
	return (int)msg.wParam;
}

