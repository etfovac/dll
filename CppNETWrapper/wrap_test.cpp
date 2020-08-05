#include "Stdafx.h"
#include "stdio.h"
#include <msclr\marshal_cppstd.h>
#include "CppNETWrapper.h"

#include <string>
#include <iostream>

#pragma managed
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::Serialization;
using namespace ClientApp1;


using namespace std;

int main()
{
//test
ClientApp1::ClientApp1Lib::ClientApp1^ remote0, ^remote();
//remote0->GetType()->GetTypeHandle
//cout << (remote0).name() << " @ "<< endl;

return 0;
}