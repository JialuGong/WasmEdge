//
// Created by huaiyu on 5/25/22.
//

#pragma once

#include "host/host_function_example/myhostenv.h"
#include "runtime/importobj.h"

#include <cstdint>

namespace WasmEdge {
namespace Host {

class HostFuncMyHostModule : public Runtime::ImportObject {
public:
  HostFuncMyHostModule();

  HostFuncMyHostEnvironment &getEnv() { return Env; }

private:
  HostFuncMyHostEnvironment Env;
};

} // namespace Host
} // namespace WasmEdge