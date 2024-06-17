// 题目：输入两个正整数m和n，求其最大公约数和最小公倍数。

#include <stdio.h>

// 递归
int _GCD(int num1, int num2) {
  if (num2 != 0) {
    int remainder = num1 % num2;
    _GCD(num2, remainder);
  } else {
    return num1;
  }
}
// 循环
int GCD(int num1, int num2) {
  while (num2 != 0) {
    int remainder = num1 % num2;
    num1 = num2;
    num2 = remainder;
  }
  return num1;
}
int main() {
  int m, n;
  printf("输入:>");
  scanf("%d%d", &m, &n);
  // int gcd = _GCD(m, n);
  int gcd = GCD(m, n);
  int lcm = m * n / gcd;
  printf("gcd = %d\nlcm = %d\n", gcd, lcm);

  return 0;
}