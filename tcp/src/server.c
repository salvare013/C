#include "inc.h"

int main(void) {
  // 1.创建socket套接字
  int listenSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (-1 == listenSocket) {
    printf("创建失败!");
    exit(-1);
  } else {
    printf("%d\n", listenSocket);
  }

  // 2.给这个socket绑定一个端口号
  struct sockaddr_in local;
  local.sin_family = AF_INET;
  local.sin_port = htons(8080);
  local.sin_addr.s_addr = inet_addr("0.0.0.0");  //全0表示全部接收
  if (-1 == bind(listenSocket, ((struct sockaddr *)&local),
                 sizeof(local))) {
    printf("bind fail");
    exit(-1);
  };

  // 3.给这个socket开启监听属性
  if (-1 == listen(listenSocket, 10)) {
    printf("listen fail");
    exit(-1);
  }
  // 4.等待客户端连接
  while (1) {
    int clientSocket = accept(listenSocket, NULL, NULL);
    if (-1 == clientSocket) {
      continue;
    }
    // 5.开始通讯
    while (1) {
      char buffer[1024];
      int ret = recv(clientSocket, buffer, 1024, 0);
      if (ret <= 0) {
        break;
      }
      printf("%s\n", buffer);
      send(clientSocket, buffer, strlen(buffer), 0);
    }
    // 6.关闭连接
    close(clientSocket);
  }

  return 0;
}