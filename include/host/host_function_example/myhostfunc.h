//
// Created by huaiyu on 5/25/22.
//

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <arpa/inet.h>

#include "common/defines.h"
#include "host/host_function_example/myhostbase.h"
namespace WasmEdge {
namespace Host {
class HostFuncMyHostPrintSocket
    : public HostFuncMyHost<HostFuncMyHostPrintSocket> {
public:
  HostFuncMyHostPrintSocket(HostFuncMyHostEnvironment &HostEnv)
      : HostFuncMyHost(HostEnv) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst, int PacketAmount);
};
}
}
