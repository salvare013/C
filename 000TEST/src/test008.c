// 题目：打印楼梯，同时在楼梯上方打印两个$。

#include <stdio.h>
#include <stdlib.h>

#define STAIRS 13

int main() {
  int i, j, k;
  char dollar = (char)36;
  char black = (char)176;
  system("chcp 437");
  printf(" %c%c\n", dollar, dollar);
  for (i = 0; i < STAIRS; i++) {
    for (k = 0; k < 4 * i; k++) {
      printf(" ");
    }
    // 打印台阶
    for (j = 0; j < 4; j++) {
      printf("%c", black);
    }
    // 打印$
    if (i < STAIRS - 1) {
      printf(" %c%c\n", dollar, dollar);
    }
  }

  return 0;
}