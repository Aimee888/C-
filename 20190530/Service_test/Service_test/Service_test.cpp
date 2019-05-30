// Service_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <Windows.h>//Win32����
#include <stdio.h>//�����ļ�д��
#pragma comment(lib, "Advapi32")

/**SLEEP_TIMEָ������������ѯ�����ڴ�֮��ĺ��������ڵڶ����б�д������ѭ����ʱ��Ҫʹ�øó���
	LOGFILEָ����־�ļ���·��
	*/
#define SLEEP_TIME 5000
#define LOGFILE "F:\\vc_work\\20190530\\Service_test\\memstatus.txt"

//����ȫ�ֱ���
SERVICE_STATUS ServiceStatus;
SERVICE_STATUS_HANDLE hStatus;

//ǰ���庯��
void ServiceMain(int argc, char** argv);
void ControlHandler(DWORD request);
int InitService();
int WriteToLog(const char* str);

//�������ɱ����Ʒ��ɻ�
int main()
{
	/*lpServiceName: ָ���ʾ���������ַ�����ָ�룻�������˶������ʱ����ô��������ָ��
	  lpServiceProc: ָ�������������ָ�루������ڵ㣩
	  ���ɱ�����һ������Ƿ������ͷ������������ NULL ָ�룬�ı����ӳ�����ֻ����һ���������Է������Ķ����ǿ�ѡ��*/
	SERVICE_TABLE_ENTRY ServiceTable[2];
	ServiceTable[0].lpServiceName = (LPWSTR)(L"MemoryStatus");
	ServiceTable[0].lpServiceProc = (LPSERVICE_MAIN_FUNCTION)ServiceMain;

	ServiceTable[1].lpServiceName = NULL;
	ServiceTable[1].lpServiceProc = NULL;

	StartServiceCtrlDispatcher(ServiceTable);
}

void ServiceMain(int argc, char** argv)
{
	int error;

	//ָʾ�������ͣ�����Win32���񡣸�ֵSERVICE_WIN32
	ServiceStatus.dwServiceType = SERVICE_WIN32;
	//ָ������ĵ�ǰ״̬����Ϊ����ĳ�ʼ��������û����ɣ�����״̬ΪSERVICE_START_PENDING��
	ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
	//�����֪ͨ SCM ��������ĸ��򡣱������������� STOP �� SHUTDOWN ���󡣴�����������ڵ��������ۣ�
	ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
	//dwWin32ExitCode �� dwServiceSpecificExitCode ��������������ֹ���񲢱����˳�ϸ��ʱ�����á���ʼ������ʱ�����˳�����ˣ����ǵ�ֵΪ 0
	ServiceStatus.dwWin32ExitCode = 0;
	ServiceStatus.dwServiceSpecificExitCode = 0;
	//dwCheckPoint �� dwWaitHint �����������ʾ��ʼ��ĳ���������ʱҪ30 �����ϡ��������ӷ���ĳ�ʼ�����̺̣ܶ��������������ֵ��Ϊ 0 
	ServiceStatus.dwCheckPoint = 0;
	ServiceStatus.dwWaitHint = 0;


	hStatus = RegisterServiceCtrlHandler(
		L"MemoryStatus",
		(LPHANDLER_FUNCTION)ControlHandler);
	if (hStatus == (SERVICE_STATUS_HANDLE)0)
	{
		// Registering Control Handler failed
		return;
	}
	// Initialize Service 
	error = InitService();
	if (!error)
	{
		// Initialization failed
		ServiceStatus.dwCurrentState =
			SERVICE_STOPPED;
		ServiceStatus.dwWin32ExitCode = -1;
		SetServiceStatus(hStatus, &ServiceStatus);
		return;
	}
	// We report the running status to SCM. 
	ServiceStatus.dwCurrentState =
		SERVICE_RUNNING;
	SetServiceStatus(hStatus, &ServiceStatus);


	MEMORYSTATUS memory;
	// The worker loop of a service
	while (ServiceStatus.dwCurrentState ==
		SERVICE_RUNNING)
	{
		char buffer[16];
		GlobalMemoryStatus(&memory);
		sprintf_s(buffer, "%d", memory.dwAvailPhys);
		int result = WriteToLog(buffer);
		if (result)
		{
			ServiceStatus.dwCurrentState =
				SERVICE_STOPPED;
			ServiceStatus.dwWin32ExitCode = -1;
			SetServiceStatus(hStatus,
				&ServiceStatus);
			return;
		}
		Sleep(SLEEP_TIME);
	}
	return;
}

void ControlHandler(DWORD request)
{
	switch (request)
	{
	case SERVICE_CONTROL_STOP:
		WriteToLog("Monitoring stopped.");
		ServiceStatus.dwWin32ExitCode = 0;
		ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		SetServiceStatus(hStatus, &ServiceStatus);
		return;


	case SERVICE_CONTROL_SHUTDOWN:
		WriteToLog("Monitoring stopped.");
		ServiceStatus.dwWin32ExitCode = 0;
		ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		SetServiceStatus(hStatus, &ServiceStatus);
		return;


	default:
		break;
	}

	// Report current status
	SetServiceStatus(hStatus, &ServiceStatus);
	return;
}

//���ڴ��ѯ������ļ�
int WriteToLog(const char* str) {
	FILE* log;
	errno_t err;
	err = fopen_s(&log, LOGFILE, "a+");
	if (log == NULL) {
		return -1;
	}
	fprintf(log, "%s\n", str);
	fclose(log);
	return 0;
	
}

int InitService() {
	WriteToLog("Monitoring started.");
	return true;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
