// This is the main DLL file.
#include "Stdafx.h"
#include "stdio.h"
#include <msclr\marshal_cppstd.h>
#include "CppNETWrapper.h"
#pragma managed
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace RemoteAccessAPI;

#ifdef __cplusplus
extern "C"
{
#endif

RemoteAPI::RemoteAPI(void)
		{
			RemoteAccessAPILib::RemoteAccessBase ^remote = gcnew  RemoteAccessAPILib::RemoteAccessBase();
			IntPtr hptr = (IntPtr)GCHandle::Alloc(remote, GCHandleType::Normal); // class obj to handle, handle to pointer
			this->rmt = new rmt_api;
			this->rmt->curr_instance = hptr.ToPointer();
		};

RemoteAPI::~RemoteAPI(void)
		{
			GCHandle hndl = GCHandle::FromIntPtr((IntPtr)this->rmt->curr_instance);
			hndl.Free();
		};

void RemoteAPI::Create() {
			GCHandle hndl = GCHandle::FromIntPtr((IntPtr)this->rmt->curr_instance);
			RemoteAccessAPILib::RemoteAccessBase ^remote = safe_cast<RemoteAccessAPILib::RemoteAccessBase^> (hndl.Target);
			RemoteAccessAPILib::RemoteAccessBase::Create(remote, remote);
			IntPtr hptr = (IntPtr)GCHandle::Alloc(remote, GCHandleType::Normal); // class obj to handle, handle to pointer
			this->rmt->curr_instance = hptr.ToPointer();
		};

conn_config RemoteAPI::GetConnConfigFromINI() {
			GCHandle hndl = GCHandle::FromIntPtr((IntPtr)this->rmt->curr_instance);
			RemoteAccessAPILib::RemoteAccessBase ^remote = safe_cast<RemoteAccessAPILib::RemoteAccessBase^> (hndl.Target);
			unsigned short tcpPort = 0;
			String^ ipAddress = "";
			RemoteAccessAPILib::RemoteAccessBase::GetConnConfigFromINI("API", remote, tcpPort, remote, ipAddress);
			string ipAddress_s = msclr::interop::marshal_as<string>(ipAddress);
			conn_config ans = new connection_config;
			ans->tcp_port = tcpPort;
			ans->ip_address = ipAddress_s;
			return ans;
		};

void RemoteAPI::Destroy() {
			GCHandle hndl = GCHandle::FromIntPtr((IntPtr)this->rmt->curr_instance);
			RemoteAccessAPILib::RemoteAccessBase ^remote = safe_cast<RemoteAccessAPILib::RemoteAccessBase^> (hndl.Target);
			RemoteAccessAPILib::RemoteAccessBase::Destroy(remote);
		};

#ifdef __cplusplus
};
#endif
