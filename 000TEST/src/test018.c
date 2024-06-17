// 对于字符串"***A**B*C***d**ss****h**e"
// 编写函数实现保留A前面的*,删除其他位置的所有*

#include <stdio.h>

void StrTrim(char str[]) {
  int i = 0;
  int flag;
  while (str[i] == '*') {
    i++;
  }
  while (str[i] != '\0') {
    while (str[i] != '*' && str[i] != '\0') {
      i++;
    }
    flag = i;
    while (str[flag] != '\0') {
      str[flag] = str[flag + 1];
      flag++;
    }
  }
}
int main() {
  char str[] = "***A**B*C***d**ss****h**e";
  // char str[99];
  // printf("输入:>");
  // scanf("%s", str);
  printf("前:%s\n", str);
  StrTrim(str);
  printf("后:%s\n", str);

  return 0;
}