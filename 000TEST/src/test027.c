// 题目：有5个人坐在一起，
// 问第五个人多少岁？他说比第4个人大2岁。
// 问第4个人岁数，他说比第3个人大2岁。
// 问第三个人，又说比第2人大两岁。
// 问第2个人，说比第一个人大两岁。
// 最后问第一个人，他说是10岁。请问第五个人多大？

#include <stdio.h>

int Age(int n) {
  if (n > 1) {
    return 2 + Age(n - 1);
  } else {
    return 10;
  }
}
int main() {
  int n;
  printf("输入:>");
  scanf("%d", &n);
  int age = Age(n);
  printf("age = %d岁\n", age);

  return 0;
}