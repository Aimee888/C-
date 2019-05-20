// UseSelfDll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

//#include "selfTrainingDll.h"
//#pragma comment(lib,"selfTrainingDll.lib")

#include <windows.h>

int main()
{
	typedef int (*_print)();
	HINSTANCE hDll = LoadLibrary(L"selfTrainingDll.dll");
	_print pAdd = (_print)GetProcAddress(hDll, "export333");
	int a = pAdd();
	cout << a << endl;
	//arithmetic_operation ao;
	//cout << ao.Add(1,2) << endl;
	//cout << ao.Sub(2,1) << endl;
	//cout << ao.Multi(2,1) << endl;
	//cout << ao.Div(6,4) << endl;
	//cout << export333() << endl;
    cout << "Hello World!\n"; 
	FreeLibrary(hDll);
}