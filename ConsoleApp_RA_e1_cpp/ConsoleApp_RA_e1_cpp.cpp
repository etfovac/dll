// ConsoleApp_RA_e1_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "CppNETWrapper.h"

using namespace std;

int main()
{
	RemoteAPI RmtAcc;
	RmtAcc.Create();
	conn_config apiConnConfig = RmtAcc.GetConnConfigFromINI(); //NOTE: It expects "AppID_Config.ini"
	cout << apiConnConfig->ip_address << " @ " << apiConnConfig->tcp_port <<endl;
 	RmtAcc.Destroy();
	RmtAcc.~RemoteAPI();

    return 0;
}

