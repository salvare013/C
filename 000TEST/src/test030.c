// 题目：删除一个字符串中的指定字符

#include <assert.h>
#include <stdio.h>

char *TrimStr(char str[], char ch) {
  assert(str);
  char *start = str;
  int i = 0;
  int flag;
  while (str[i] != '\0') {
    while (str[i] != ch && str[i] != '\0') {
      i++;
    }
    flag = i;
    while (str[flag] != '\0') {
      str[flag] = str[flag + 1];
      flag++;
    }
  }
  return start;
}
int main() {
  char str[] = "**a*bc**a*abb*cca**aab*bb**c*cc***";
  char ch;
  printf("前:%s\n", str);
  printf("输入:>");
  scanf("%c", &ch);
  char *newStr = TrimStr(str, ch);
  printf("后:%s\n", newStr);

  return 0;
}