// 公比大于1的等比数列求和

#include <stdio.h>

size_t Power(int a, int n) {
  if (n > 0) {
    return a * Power(a, n - 1);
  } else {
    return 1;
  }
}
int main() {
  int a, n;
  size_t sum = 0;
  printf("输入a,n:>");
  scanf("%d%d", &a, &n);
  //   size_t ret = Power(a, n);
  //   printf("power(a) = %llu", ret);
  while (n) {
    sum += Power(a, n);
    n--;
  }
  printf("sum = %llu\n", sum);

  return 0;
}