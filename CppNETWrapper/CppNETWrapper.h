// CppNETWrapper.h
#include <string>
using namespace std;
#pragma once
#pragma unmanaged
#ifdef DLL_EXPORTS
#define DllExport __declspec(dllexport)
#else
#define DllImport __declspec(dllimport)
#endif

/*#ifdef __cplusplus
extern "C"
{
#endif*/
struct rmt_api {
	void* curr_instance;
	std::string last_error;
};
typedef rmt_api* rmt_b;

struct connection_config {
	string id;
	string ip_address;
	unsigned short tcp_port;
};
typedef connection_config* conn_config;

class  RemoteAPI {
private:
	rmt_b rmt;
public:
	RemoteAPI(void);
	virtual ~RemoteAPI(void);
	void Create();
	void  Destroy();
	conn_config GetConfig();
};
/*#ifdef __cplusplus
};
#endif*/
