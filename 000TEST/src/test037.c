// 模拟实现strlen

#include <assert.h>
#include <stdio.h>

// 指针减法
int _StrLen(char* str) {
  assert(str);
  char* start = str;
  while (*str++) {
    ;
  }
  char* end = str - 1;
  return end - start;
}
// 创建len变量
int StrLen(char* str) {
  assert(str);
  int len = 0;
  while (*str++) {
    len++;
  }
  return len;
}
int main() {
  char str[] = "I Love XQ";
  int len = _StrLen(str);
  // int len = StrLen(str);
  printf("len = %d\n", len);

  return 0;
}