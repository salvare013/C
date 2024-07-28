// 题目：将一个正整数分解质因数。
// 例如：输入90,打印出90=2*3*3*5。

#include <math.h>
#include <stdio.h>

int IsPrime(int num) {
  int i;
  for (i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return i;
    }
  }
  return 1;
}
// 递归
void Factorization(int num) {
  int divisor = num / IsPrime(num);
  if (IsPrime(num) == 1) {
    printf("%d", divisor);
  } else {
    printf("%d", IsPrime(num));
    printf(" * ");
    Factorization(divisor);
  }
}
// 循环
void _Factorization(int num) {
  while (IsPrime(num) != 1) {
    printf("%d", IsPrime(num));
    printf(" * ");
    num = num / IsPrime(num);
  }
  printf("%d", num);
}
int main() {
  int num;
  printf("输入:>");
  scanf("%d", &num);
  printf("%d = 1 * ", num);
  _Factorization(num);
  // Factorization(num);
  printf("\n");

  return 0;
}