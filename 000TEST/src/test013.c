// 题目：利用条件运算符的嵌套来完成此题：
// 学习成绩>=90分的同学用A表示，
// 60-89分之间的用B表示，60分以下的用C表示。

#include <stdio.h>

int main() {
  int score;
  char grade;
  printf("输入:>");
  scanf("%d", &score);
  grade =
      (score >= 90 ? 'A'
                   : (score >= 60 ? 'B' : 'C'));
  printf("grade = %c\n", grade);

  return 0;
}