// 题目：有n个人围成一圈，顺序排号(从1开始)。
// 从第一个人开始报数（从1到3报数），
// 凡报到3的人退出圈子，问最后留下的是原来第几号的那位。

#include <stdio.h>

#define PEOPLE 8
#define OUT 88

int main() {
  int player[PEOPLE] = {0};
  int num = 1;
  int count = 0;
  while (1) {
    for (int i = 0; i < PEOPLE; i++) {
      if (player[i] != OUT) {
        player[i] = num;
        num++;
      }
      if (3 == player[i]) {
        player[i] = OUT;
        count++;
        num = 1;
      }
    }
    if (PEOPLE - 1 == count)
      break;
  }
  for (int i = 0; i < PEOPLE; i++) {
    if (player[i] != OUT)
      printf("win: %d号\n", i + 1);
  }

  return 0;
}