// Service_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <Windows.h>//Win32函数
#include <stdio.h>//磁盘文件写入
#pragma comment(lib, "Advapi32")

/**SLEEP_TIME指定两次连续查询可用内存之间的毫秒间隔。在第二步中编写服务工作循环的时候要使用该常量
	LOGFILE指定日志文件的路径
	*/
#define SLEEP_TIME 5000
#define LOGFILE "F:\\vc_work\\20190530\\Service_test\\memstatus.txt"

//声明全局变量
SERVICE_STATUS ServiceStatus;
SERVICE_STATUS_HANDLE hStatus;

//前向定义函数
void ServiceMain(int argc, char** argv);
void ControlHandler(DWORD request);
int InitService();
int WriteToLog(const char* str);

//创建分派表并控制分派机
int main()
{
	/*lpServiceName: 指向表示服务名称字符串的指针；当定义了多个服务时，那么这个域必须指定
	  lpServiceProc: 指向服务主函数的指针（服务入口点）
	  分派表的最后一项必须是服务名和服务主函数域的 NULL 指针，文本例子程序中只宿主一个服务，所以服务名的定义是可选的*/
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

	//指示服务类型，创建Win32服务。赋值SERVICE_WIN32
	ServiceStatus.dwServiceType = SERVICE_WIN32;
	//指定服务的当前状态，因为服务的初始化在这里没有完成，所以状态为SERVICE_START_PENDING；
	ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
	//这个域通知 SCM 服务接受哪个域。本文例子是允许 STOP 和 SHUTDOWN 请求。处理控制请求将在第三步讨论；
	ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
	//dwWin32ExitCode 和 dwServiceSpecificExitCode 这两个域在你终止服务并报告退出细节时很有用。初始化服务时并不退出，因此，它们的值为 0
	ServiceStatus.dwWin32ExitCode = 0;
	ServiceStatus.dwServiceSpecificExitCode = 0;
	//dwCheckPoint 和 dwWaitHint ：这两个域表示初始化某个服务进程时要30 秒以上。本文例子服务的初始化过程很短，所以这两个域的值都为 0 
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

//将内存查询输出到文件
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
