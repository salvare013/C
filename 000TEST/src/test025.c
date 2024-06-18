// 题目：求1!+2!+3!+...+20!的和。

#include <assert.h>
#include <stdio.h>


// 递归
size_t Factorial(int n) {
  if (n > 0) {
    return n * Factorial(n - 1);
  } else {
    return 1;
  }
}
// 循环
size_t _Factorial(int n) {
  size_t fac = 1;
  for (int i = 1; i <= n; i++) {
    fac *= i;
  }
  return fac;
}
// 1到n的阶乘和
size_t FactorialSum(int n) {
  assert(n > 0);
  size_t fac = 1;
  size_t sum = 0;
  for (int i = 1; i <= n; i++) {
    fac *= i;
    sum += fac;
  }
  return sum;
}
int main() {
  int i, n;
  size_t sum = 0;
  printf("输入:>");
  scanf("%d", &n);
  // for (i = 1; i <= n; i++) {
  //  // sum += Factorial(i);
  //   sum += _Factorial(i);
  // }
  sum = FactorialSum(n);
  printf("sum = %llu", sum);

  return 0;
}