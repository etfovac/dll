// This is the main DLL file.
#include "Stdafx.h"
#include "stdio.h"
#include <msclr\marshal_cppstd.h>
#include "CppNETWrapper.h"
#pragma managed
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace ClientApp1;


/*#ifdef __cplusplus
extern "C"
{
#endif*/

RemoteAPI::RemoteAPI(void)
{	// constructor that creates a pointer to .net class and stores it in wrapper class
	ClientApp1::ClientApp1Lib::ClientApp1 ^remote = gcnew  ClientApp1::ClientApp1Lib::ClientApp1();
	IntPtr hptr = (IntPtr)GCHandle::Alloc(remote, GCHandleType::Normal); // class obj to handle, handle to pointer
	this->rmt = new rmt_api;
	this->rmt->curr_instance = hptr.ToPointer();
};

RemoteAPI::~RemoteAPI(void)
{ // deconstructor
	GCHandle hndl = GCHandle::FromIntPtr((IntPtr)this->rmt->curr_instance);
	hndl.Free();
};

void RemoteAPI::Create() 
{ // gets the pointer of derived .net class from wrapper class
	GCHandle hndl = GCHandle::FromIntPtr((IntPtr)this->rmt->curr_instance);
	ClientApp1::ClientApp1Lib::ClientApp1 ^remote = safe_cast<ClientApp1::ClientApp1Lib::ClientApp1^> (hndl.Target);
	ClientApp1::ClientApp1Lib::ClientApp1::Create(remote, remote);
	IntPtr hptr = (IntPtr)GCHandle::Alloc(remote, GCHandleType::Normal); // class obj to handle, handle to pointer
	this->rmt->curr_instance = hptr.ToPointer();
};

conn_config RemoteAPI::GetConfig() 
{ //
	GCHandle hndl = GCHandle::FromIntPtr((IntPtr)this->rmt->curr_instance);
	ClientApp1::ClientBaseLib::ClientBase ^remote = safe_cast<ClientApp1::ClientBaseLib::ClientBase^> (hndl.Target);
	unsigned short tcpPort = 0;
	String^ ipAddress = "";
	String^ ID = "";
	ClientApp1::ClientBaseLib::ClientBase::GetConfig(remote, remote, tcpPort, ipAddress, ID);
	string ipAddress_s = msclr::interop::marshal_as<string>(ipAddress);
	string id_s = msclr::interop::marshal_as<string>(ID);
	conn_config ans = new connection_config;
	ans->id = id_s;
	ans->tcp_port = tcpPort;
	ans->ip_address = ipAddress_s;
	return ans;
};

void RemoteAPI::Destroy() 
{
	GCHandle hndl = GCHandle::FromIntPtr((IntPtr)this->rmt->curr_instance);
	ClientApp1::ClientBaseLib::ClientBase ^remote = safe_cast<ClientApp1::ClientBaseLib::ClientBase^> (hndl.Target);
	ClientApp1::ClientBaseLib::ClientBase::Destroy(remote);
};

/*#ifdef __cplusplus
};
#endif*/
