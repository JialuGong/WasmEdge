//
// Created by huaiyu on 5/25/22.
//

#pragma once

#include "common/errcode.h"
#include "host/host_function_example/myhostenv.h"
#include "runtime/hostfunc.h"

namespace WasmEdge {
namespace Host {

template <typename T> class HostFuncMyHost : public Runtime::HostFunction<T> {
public:
  HostFuncMyHost(HostFuncMyHostEnvironment &HostEnv)
      : Runtime::HostFunction<T>(0), Env(HostEnv) {}

protected:
  HostFuncMyHostEnvironment &Env;
};

} // namespace Host
} // namespace WasmEdge
