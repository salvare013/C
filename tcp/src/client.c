#include "inc.h"
int main(void) {
  //  1. 创建套接字
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (-1 == clientSocket) {
    printf("create fail\n");
    exit(-1);
  }

  //  2.连接服务器
  struct sockaddr_in target;
  target.sin_family = AF_INET;
  target.sin_port = htons(8080);
  target.sin_addr.s_addr = inet_addr("127.0.0.1");
  if (-1 == connect(clientSocket, (struct sockaddr *)&target,
                    sizeof(target))) {
    printf("connect fail");
    close(clientSocket);
    exit(-1);
  }
  //  3.开始通讯 send recv
  while (1) {
    char sBuf[1024] = {0};
    printf("输入>>>");
    scanf("%s", sBuf);
    send(clientSocket, sBuf, strlen(sBuf), 0);
    char rBuf[1024] = {0};
    int ret = recv(clientSocket, rBuf, 1024, 0);
    if (ret <= 0) {
      break;
    }
    printf("%s\n", rBuf);
  }
  //  4.关闭连接
  close(clientSocket);

  return 0;
}
