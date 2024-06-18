// 题目：输入三个整数x,y,z，请把这三个数由小到大输出。

#include <stdio.h>

int main() {
  int x, y, z, tmp;
  printf("输入三个整数:>");
  scanf("%d%d%d", &x, &y, &z);
  if (x > y) {
    tmp = x;
    x = y;
    y = tmp;
  }
  if (x > z) {
    tmp = x;
    x = z;
    z = tmp;
  }
  if (y > z) {
    tmp = y;
    y = z;
    z = tmp;
  }
  printf("这三个数由小到大依次为:%d %d %d\n", x,
         y, z);

  return 0;
}
