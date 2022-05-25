//
// Created by huaiyu on 5/25/22.
//
#include "host/host_function_example/myhostmodule.h"

#include "host/host_function_example/myhostfunc.h"
namespace WasmEdge{
namespace Host{
HostFuncMyHostModule::HostFuncMyHostModule()
:ImportObject("host_function_my_host"){
  addHostFunc("host_function_my_host_print_socket",std::make_unique<HostFuncMyHostPrintSocket>(Env));
}
}
}