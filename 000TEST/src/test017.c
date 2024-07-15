// 题目：求s=a+aa+aaa+aaaa+aa...a的值，
// 其中a是一个数字。例如2+22+222+2222+22222
// (此时共有n =
// 5个数相加)，几个数相加由键盘控制。

#include <stdio.h>

long long GrowDigit(long long a, int n) {
  if (n > 1) {
    return a + GrowDigit(a * 10, n - 1);
  } else {
    return a;
  }
}
int main() {
  int a, n;
  long long sum = 0;
  printf("输入a(-9<a<9)和n:>");
  scanf("%d%d", &a, &n);
  while (n > 0) {
    sum += GrowDigit(a, n);
    n--;
  }
  printf("sum = a + aa + aaa +... = %lld\n",
         sum);

  return 0;
}