// consol_paint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

#include <windows.h>
#include <conio.h>

HWND HMainwnd = NULL; //������
HWND HButton = NULL;
int run(); //��Ϣѭ������
bool InitWindowsApp(HINSTANCE instanceHandle, int show); //�����ʼ������
LRESULT CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wp, LPARAM lp);//���崦��

int tag = 10;
int tag1 = 12;

//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //��Ҫ�ģ����Ǳ�������


//void color(int a) {//�ı��������ɫ����system("color x")��ö�
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
//	/*
//	<span style="white-space:pre">	</span>��
//		1	����ɫ
//		2	����ɫ
//		3	����ɫ
//		4	���ɫ
//		5	���ɫ
//		6	��ɫ
//		7	���ɫ
//		8	��ɫ
//		9	ǳ��ɫ
//		10	ǳ��ɫ
//		11	ǳ��ɫ
//		12	ǳ��ɫ
//		13	ǳ��ɫ
//		14	ǳ��ɫ
//		15	ǳ��ɫ
//
//		����
//		1~15		��ɫ
//		16~31		����ɫ
//		32~47		����ɫ
//		48~63		����ɫ
//		64~79		���ɫ
//		80~95		���ɫ
//		96~111		���ɫ
//		112~127 	���ɫ
//		128~143 	��ɫ
//		144~159 	ǳ��ɫ
//		160~175 	ǳ��ɫ
//		176~191 	ǳ��ɫ
//		192~207 	ǳ��ɫ
//		208~223 	ǳ��ɫ
//		224~239 	ǳ��ɫ
//		240~255 	ǳ��ɫ
//	*/
//}


//void check(char c) {//���ĳ�������Ƿ��£����¾͸ı������ɫ
//	if (!KEY_DOWN(c))color(7);
//	else color(112);
//	printf("  %c  ", c);
//	color(7);
//}

int main(int argc, char* argv[], HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    cout << "Hello World!\n"; 

	//��ȡ�������뷽ʽ1
	//int ch;
	//while (1) {
	//	if (_kbhit()) {//����а������£���_kbhit()����������
	//		ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
	//		cout << char(ch);
	//		if (ch == 27) { break; }//������ESCʱѭ����ESC���ļ�ֵʱ27.
	//	}
	//}
	//system("pause");

	//��ȡ�������뷽ʽ2
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

	//	Sleep(20);//ѭ��ʱ��������ֹ̫ռ�ڴ� 
	//	system("cls");//���� 
	//}
	
	if (!InitWindowsApp(hInstance, nShowCmd)) {
		cout << "��ʼ��ʧ��" << endl;
	}
	run();
	cout << "aaa";
	return 0;
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
		hwndButton[9] = CreateWindow(L"BUTTON", L"A",
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

