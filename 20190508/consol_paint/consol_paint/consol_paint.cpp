// consol_paint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

#include <windows.h>
#include <conio.h>

HWND HMainwnd = NULL; //窗体句柄
HWND HButton = NULL;
int run(); //消息循环函数
bool InitWindowsApp(HINSTANCE instanceHandle, int show); //窗体初始化函数
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);//窗体处理

int tag = 10;
int tag1 = 12;

//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的


//void color(int a) {//改变输出的颜色，比system("color x")快得多
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
//	/*
//	<span style="white-space:pre">	</span>字
//		1	深蓝色
//		2	深绿色
//		3	深青色
//		4	深红色
//		5	深粉色
//		6	黄色
//		7	深白色
//		8	灰色
//		9	浅蓝色
//		10	浅绿色
//		11	浅青色
//		12	浅红色
//		13	浅粉色
//		14	浅黄色
//		15	浅白色
//
//		背景
//		1~15		黑色
//		16~31		深蓝色
//		32~47		深绿色
//		48~63		深青色
//		64~79		深红色
//		80~95		深粉色
//		96~111		深黄色
//		112~127 	深白色
//		128~143 	灰色
//		144~159 	浅蓝色
//		160~175 	浅绿色
//		176~191 	浅青色
//		192~207 	浅红色
//		208~223 	浅粉色
//		224~239 	浅黄色
//		240~255 	浅白色
//	*/
//}


//void check(char c) {//检测某个按键是否按下，按下就改变输出颜色
//	if (!KEY_DOWN(c))color(7);
//	else color(112);
//	printf("  %c  ", c);
//	color(7);
//}

int main(int argc, char* argv[], HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    cout << "Hello World!\n"; 

	//获取键盘输入方式1
	//int ch;
	//while (1) {
	//	if (_kbhit()) {//如果有按键按下，则_kbhit()函数返回真
	//		ch = _getch();//使用_getch()函数获取按下的键值
	//		cout << char(ch);
	//		if (ch == 27) { break; }//当按下ESC时循环，ESC键的键值时27.
	//	}
	//}
	//system("pause");

	//获取键盘输入方式2
	//while (1) {
	//	check('Q'); check('W'); check('E'); check('R'); check('T'); check('Y'); check('U'); check('I'); check('O'); check('P');
	//	printf("\n\n ");
	//	check('A'); check('S'); check('D'); check('F'); check('G'); check('H'); check('J'); check('K'); check('L');
	//	printf("\n\n  ");
	//	check('Z'); check('X'); check('C'); check('V'); check('B'); check('N'); check('M');
	//	printf("\n\n  ");
	//	check('0'); check('1'); check('2'); check('3'); check('4'); check('5'); check('6');
	//	printf("\n\n  ");
	//	check('7'); check('8'); check('9'); check('/'); check('*'); check('+'); check('-');
	//	printf("\n\n  ");

	//	Sleep(20);//循环时间间隔，防止太占内存 
	//	system("cls");//清屏 
	//}
	
	if (!InitWindowsApp(hInstance, nShowCmd)) {
		cout << "初始化失败" << endl;
	}
	run();
	cout << "aaa";
	return 0;
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
		hwndButton[9] = CreateWindow(L"BUTTON", L"A",
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
	case WM_CHAR:
		switch (wParam) {
		case 0x30:
			tag1 = 0;
			break;
		case 0x31:
			tag1 = 1;
			break;
		case 0x32:
			tag1 = 2;
			break;
		case 0x33:
			tag1 = 3;
			break;
		case 0x34:
			tag1 = 4;
			break;
		case 0x35:
			tag1 = 5;
			break;
		case 0x36:
			tag1 = 6;
			break;
		case 0x37:
			tag1 = 7;
			break;
		case 0x38:
			tag1 = 8;
			break;
		case 0x39:
			tag1 = 9;
			break;
		case 0x41:
			tag1 = 10;
			break;
		default:
			break;
		}
		if (tag1 == tag) {
			cout << "True" << endl;
		}
		else {
			cout << "False" << endl;
		}
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

