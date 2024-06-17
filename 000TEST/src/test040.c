// 题目：求0—7所能组成的奇数个数(所有位数)。

#include <stdio.h>

size_t Fac(size_t num) {
  if (num > 1)
    return num * Fac(num - 1);
  else
    return 1;
}
size_t Permutation(int n, int m) {
  return Fac(n) / Fac(n - m);
}
int main(void) {
  int count = 0;
  count += 4;
  for (int i = 2; i < 8; i++) {
    count += 4 * (Permutation(7, i - 1) - Permutation(6, i - 2));
  }
  printf("count = %d\n", count);

  return 0;
}