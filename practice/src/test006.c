// 题目：输出九九乘法表

#include <stdio.h>

int main() {
  int i, j;
  for (i = 1; i <= 9; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d * %d = %-2d  ", j, i, j * i);
    }
    printf("\n");
  }

  return 0;
}