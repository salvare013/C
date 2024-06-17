// 斐波那契数列 1 1 2 3 5 8 13 21 ...

#include <assert.h>
#include <stdio.h>

// 递归
long _Fib(int num) {
  assert(num > 0);
  if (num < 3) {
    return 1;
  } else {
    return _Fib(num - 1) + _Fib(num - 2);
  }
}
// 循环
size_t Fib(size_t num) {
  assert(num > 0);

  if (num < 3) {
    return 1;
  } else {
    size_t f1 = 1;
    size_t f2 = 1;
    size_t fn;
    size_t count = num - 2;
    while (count--) {
      fn = f1 + f2;
      f1 = f2;
      f2 = fn;
    }
    return fn;
  }
}
int main() {
  int i = 0;
  for (i = 1; i < 123; i++) {
    printf("%llu ", Fib(i));
  }

  //   size_t num;
  //   printf("输入:>");
  //   scanf("%d", &num);

  //   printf("第%llu个斐波那契数是%llu\n", num, Fib(num));

  return 0;
}