// 题目：输入一行字符，分别统计出其中
// 英文字母、空格、数字和其它字符的个数。

#include <stdio.h>

int main() {
  char str[99];
  int letter = 0;
  int spaces = 0;
  int digit = 0;
  int rests = 0;
  int i = 0;
  printf("输入:>");
  fgets(str, sizeof(str), stdin);
  for (i = 0; str[i] != '\0'; i++) {
    if (str[i] == ' ') {
      spaces++;
    } else if ((str[i] >= 65 && str[i] <= 90) ||
               (str[i] >= 97 && str[i] <= 122)) {
      letter++;
    } else if (str[i] >= 48 && str[i] <= 57) {
      digit++;
    } else {
      rests++;
    }
  }
  printf("%s", str);
  printf(
      "letter = %d\nspaces = %d\ndigit = "
      "%d\nrests = %d\n",
      letter, spaces, digit, rests);

  return 0;
}
