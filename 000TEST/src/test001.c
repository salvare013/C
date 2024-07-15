// 题目：有1、2、3、4这四个数字，能组成多少个互不相同
// 且无重复数字的三位数？都是多少？

#include <stdio.h>

int main() {
  int i, j, k;
  int count = 0;
  for (i = 1; i < 5; i++) {
    for (j = 1; j < 5; j++) {
      for (k = 1; k < 5; k++) {
        if (i != j && i != k && j != k) {
          printf("%d%d%d ", i, j, k);
          count++;
        }
      }
    }
  }
  printf("\ncount = %d\n", count);

  return 0;
}