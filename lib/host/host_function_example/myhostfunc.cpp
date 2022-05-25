//
// Created by huaiyu on 5/25/22.
//
#include "host/host_function_example/myhostfunc.h"
namespace WasmEdge{
namespace Host{

void packet_print(unsigned char* buffer, int buffer_len){
  printf("\n---------------------------- Packet ----------------------------\n");
  int col = 16;
  int row;
  if(buffer_len%col == 0){
    row = buffer_len/col;
  }else{
    row = buffer_len/col + 1;
  }
  for(int i = 0;i < row;i++){
    int j;
    for(j = 0;j < col-1;j++){
      printf("%.2x  ",(int)buffer[i*16+j]);
    }
    printf("%.2x\n",(int)buffer[i*16+j]);
  }
  printf("\n----------------------- Packet finished ------------------------");
}

Expect<void > HostFuncMyHostPrintSocket::body( [[maybe_unused]] Runtime::Instance::MemoryInstance *MemInst, int PacketAmount){

  int PACKET_LEN = 16000;
  unsigned char buffer[PACKET_LEN];
  struct sockaddr saddr;
  struct packet_mreq mr;

  // create a raw socket
  int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
  Env.RowSock=sock;
  if(sock < 0){
    printf("Error in creating socket.\n");
    return {};
  }

  // turn on the promiscuous mode
  mr.mr_type = PACKET_MR_PROMISC;
  setsockopt(sock, SOL_PACKET, PACKET_ADD_MEMBERSHIP, &mr, sizeof(mr));

  printf("Start sniffing...\n");
  int count = 0;
  while(1){
    if(count > PacketAmount)
      break;

    int saddr_len = sizeof saddr;
    int data_size = recvfrom(sock, buffer, PACKET_LEN, 0,
                             &saddr, (socklen_t*)&saddr_len);

    if(data_size > 0){
      packet_print(buffer,data_size);
    }else{
      printf("Error in recvfrom func\n");
      return {};
    }
    count++;
  }

  close(sock);
  return {};
}
}
}