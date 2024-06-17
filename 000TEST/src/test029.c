// 题目：请输入星期几的第一个字母来判断一下是星期几，
// 如果第一个字母一样，则继续判断第二个字母。
// monday,tuesday,wednesday,thursday,friday,saturday,sunday

#include <stdio.h>

int main() {
  char ch;
  printf("输入:>");
  switch (ch = getchar()) {
  case 'm':
    printf("monday");
    break;
  case 'w':
    printf("wednesday");
    break;
  case 'f':
    printf("friday");
    break;
  case 't':
  t_input:
    ch = getchar();
    if (ch == '\n') {
      printf("继续输入:>");
      goto t_input;
    }
    if (ch == 'u') {
      printf("tuesday");
    } else if (ch == 'h') {
      printf("thursday");
    } else {
      printf("输入错误!\n");
    }
    break;
  case 's':
  s_input:
    ch = getchar();
    if (ch == '\n') {
      printf("继续输入:>");
      goto s_input;
    }
    if (ch == 'a') {
      printf("saturday");
    } else if (ch == 'u') {
      printf("sunday");
    } else {
      printf("输入错误!\n");
    }
    break;
  default:
    printf("输入错误!\n");
    break;
  }

  return 0;
}