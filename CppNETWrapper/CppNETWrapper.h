// CppNETWrapper.h
#include <string>
using namespace std;
#pragma once
#pragma unmanaged
#define DllExport  __declspec( dllexport ) 
#ifdef __cplusplus
extern "C"
{
#endif
struct rmt_api {
	void* curr_instance;
	std::string last_error;
};
typedef rmt_api* rmt_b;

struct connection_config {
	unsigned short tcp_port;
	string ip_address;
};
typedef connection_config* conn_config;

class DllExport RemoteAPI {
private:
	rmt_b rmt;
public:
	RemoteAPI(void);
	virtual ~RemoteAPI(void);
	void Create();
	void  Destroy();
	conn_config GetConnConfigFromINI();
};
#ifdef __cplusplus
};
#endif
