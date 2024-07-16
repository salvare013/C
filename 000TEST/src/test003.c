// 题目：一个整数，它加上 100
// 后是一个完全平方数， 再加上
// 168又是一个完全平方数，请问该数是多少？

#include <math.h>
#include <stdio.h>

#define SQUARE(X) ((X) * (X))

int main() {
  int i;
  int x, y;
  for (i = 1; i < 10000; i++) {
    x = sqrt(i + 100);
    y = sqrt(i + 100 + 168);
    if (SQUARE(x) == (i + 100) && SQUARE(y) == (i + 268))
      printf("%d ", i);
  }

  return 0;
}
