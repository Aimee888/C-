// TestDll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "windows.h"

using namespace std;

#include "../IniDll/IniDll.h"

string input(string item) {
	char ch;
	string tmp = "";
	while (ch = cin.get()) {
		if (ch == '\n')
			break;
		tmp = tmp + ch;
	}
	return tmp;
}

float input(float item) {
	char ch;
	float tmp = 0;
	while (ch = cin.get()) {
		if (ch == '\n')
			break;
		tmp = tmp * 10 + ch - '0';
	}
	return tmp;
}

void WriteDataToIni() {
	char sec_str[20];
	char key_str[20];
	char value_str[128];
	char path_str[128];
	cout << "sec = ";
	cin >> sec_str;
	cout << "key = ";
	cin >> key_str;
	cout << "value = ";
	cin >> value_str;
	cout << "path = ";
	cin >> path_str;


	Ini_Write(sec_str, key_str, value_str, path_str);
}

void ReadDataFromIni() {
	char sec_str[20];
	char key_str[20];
	char* value_str;
	char path_str[128];
	cout << "sec = ";
	cin >> sec_str;
	cout << "key = ";
	cin >> key_str;
	cout << "path = ";
	cin >> path_str;

	//char path_str[128] = "F:\\vc_work\\20190516\\TestDll\\Release\\aaa.ini";
	//char sec_str[20] = "83E7";
	//char key_str[20] = "dsgfdh";

	//value_str = Ini_Read(sec_str, key_str, path_str);
	value_str = Ini_Read(sec_str, key_str, path_str);
	//cout << value_str << endl;

}

void GetSection() {
	char path_str[128];
	cout << "path = ";
	cin >> path_str;
	//char * tmp = GetSections(path_str);
	//char path_str[128] = "F:\\vc_work\\20190514\\TestDll\\Release\\aaa.ini";
	//char path_str[128] = "F:\\vc_work\\20190514\\TestDll\\Release\\devdetect_sample.ini";
	char* sec_set;

	int ret = GetSections_num(path_str);
	cout << ret << endl;

	for (int i = 1; i < ret + 1; i++) {
		sec_set = GetSections(path_str, i);
		cout << sec_set << endl;
	}
}

void DeleteFile_d() {
	//char sec_str[20];
	//char key_str[20];
	//char path_str[128];
	//cout << "sec = ";
	//cin >> sec_str;
	//cout << "key = ";
	//cin >> key_str;
	//cout << "path = ";
	//cin >> path_str;
	
	char path_str[128] = "F:\\vc_work\\20190516\\TestDll\\Release\\aaa.ini";
	char sec_str[20] = "83E7";
	//char key_str[20] = "Device3.name";

	//Ini_Del_Key(sec_str, key_str, path_str);
	Ini_Del_Sec(sec_str, path_str);
	//cout << value_str << endl;
}


int main()
{
	//GetSection();
	//ReadDataFromIni();
	//char path_str[128];
	//cout << "path = ";
	//cin >> path_str;
	//WriteDataToIni();
	//ReadDataFromIni();
	//char * tmp = GetSections(path_str);
	//char path_str[128] = "F:\\vc_work\\20190514\\TestDll\\Release\\aaa.ini";
	////char path_str[128] = "F:\\vc_work\\20190514\\TestDll\\Release\\devdetect_sample.ini";
	//char* sec_set;

	//int ret = GetSections_num(path_str);
	//cout << ret << endl;

	//for (int i = 1; i < ret + 1; i++) {
	//	sec_set = GetSections(path_str, i);
	//	cout << sec_set << endl;
	//}
	//sec_set = GetSections(path_str, 5);
	//cout << sec_set << endl;


	DeleteFile_d();

    cout << "Hello World!\n"; 
}

