// 题目：编写一个函数，输入n为偶数时，调用函数求1/2+1/4+...+1/n,
// 当输入n为奇数时，调用函数1/1+1/3+...+1/n(使用回调函数实现)。

#include <assert.h>
#include <stdio.h>

double Even(int n) {
  assert(n % 2 == 0);
  double sum = 0;
  for (int i = 2; i <= n; i += 2) {
    sum += 1.0 / i;
  }
  return sum;
}
double Odd(int n) {
  assert(n % 2 != 0);
  double sum = 0;
  for (int i = 1; i <= n; i += 2) {
    sum += 1.0 / i;
  }
  return sum;
}
int main(void) {
  int n;
  double (*pfSum)(int) = NULL;
  printf("输入>>>");
  scanf("%d", &n);
  if (n % 2 != 0) {
    pfSum = Odd;
  } else {
    pfSum = Even;
  }
  printf("sum = %lf\n", pfSum(n));

  return 0;
}