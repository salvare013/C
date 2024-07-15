// 题目：字符串反转，如将字符串 "www.like.cn"
// 反转为 "nc.ekil.www"

#include <assert.h>
#include <stdio.h>
#include <string.h>

char* ReverseStr(char* str, int len) {
  assert(str);
  char* start = str;
  for (int i = 0; i <= len / 2 - 1; i++) {
    char tmp = *(str + i);
    *(str + i) = *(str + len - 1 - i);
    *(str + len - 1 - i) = tmp;
  }
  return start;
}
int main() {
  // char str[] = "www.like.cn";
  char str[99];
  printf("输入>:");
  scanf("%s", str);
  int len = strlen(str);
  printf("前:%s\n", str);
  char* newStr = ReverseStr(str, len);
  printf("后:%s\n", newStr);

  return 0;
}