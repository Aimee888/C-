// UseDll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

using namespace std;

#include "Dll1.h"
#pragma comment(lib,"Dll1.lib")

int main()
{
	cout << exportDate() << endl;          //调用函数输出666
    cout << "Hello World!\n"; 
}

