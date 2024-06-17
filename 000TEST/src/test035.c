// 杨辉三角

#include <assert.h>
#include <stdio.h>

#define N 20

size_t Fac(size_t num) {
  if (num > 0)
    return num * Fac(num - 1);
  else
    return 1;
}
size_t CombinatorialNum(int n, int m) {
  assert(m <= n);
  return Fac(n) / (Fac(n - m) * Fac(m));
}
int main() {
  int space = N;
  for (int n = 0; n < N; n++) {
    while (space--) {
      for (int k = 0; k < space; k++)
        printf("%3c", ' ');
      break;
    }
    for (int i = 0; i <= n; i++) {
      if (i > n / 2)
        printf("%-6llu", CombinatorialNum(n, n - i));
      else
        printf("%-6llu", CombinatorialNum(n, i));
    }
    printf("\n");
  }

  return 0;
}