// 题目：打印出所有的"水仙花数"，
// 所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数本身。
// 例如：153 是一个"水仙花数"，
// 因为 153 = 1^3 ＋ 5^3 ＋ 3^3。

#include <assert.h>
#include <stdio.h>

#define CUBE(X) ((X) * (X) * (X))

int IsNarcissisticNum(int num) {
  assert(num > 100 && num < 1000);
  int hundred, tens, unit;
  hundred = num / 100;
  tens = num / 10 % 10;
  unit = num % 10;
  if (CUBE(hundred) + CUBE(tens) + CUBE(unit) ==
      num) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  int i;
  int count = 0;
  for (i = 101; i < 1000; i++) {
    if (IsNarcissisticNum(i) == 1) {
      printf("%d ", i);
      count++;
    }
  }
  printf("\ncount = %d\n", count);

  return 0;
}