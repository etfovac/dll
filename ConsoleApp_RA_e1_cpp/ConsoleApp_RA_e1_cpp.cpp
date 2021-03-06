// ConsoleApp_RA_e1_cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "..\CppNETWrapper\CppNETWrapper.h"

using namespace std;

int main()
{
	RemoteAPI RA;
	RA.Create();
	conn_config apiConnConfig = RA.GetConfig(); 
	//displays: App1 @ 192.168.0.123:4321
	cout << apiConnConfig->id << " @ " << apiConnConfig->ip_address << ":" << apiConnConfig->tcp_port <<endl;
 	RA.Destroy();
	RA.~RemoteAPI();

    return 0;
}

