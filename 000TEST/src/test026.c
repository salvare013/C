// 题目：输入一段字符，以相反顺序打印出来。

#include <stdio.h>

// 可以处理任意单字节字符
void ReverseOut(void) {
  char ch = getchar();
  if (ch == '\n') {
    return;
  }
  ReverseOut();
  putchar(ch);
}
// 只能处理整数
void DigitReverseOut(int num) {
  printf("%d", num % 10);
  if (num > 9) {
    DigitReverseOut(num / 10);
  }
}
int main() {
  // DigitReverseOut演示
  int num = 123456;
  DigitReverseOut(num);
  printf("\n");
  // ReverseOut演示
  printf("输入:>");
  ReverseOut();

  return 0;
}