// 题目：一球从100米高度自由落下，每次落地后反跳回原高度的一半,再落下，
// 求它在第n次落地时，共经过多少米？第n次反弹多高？

#include <stdio.h>

int main() {
  double distance = 100;
  double height = 100;
  int n;
  printf("输入:>");
  scanf("%d", &n);
  while (n) {
    height /= 2;
    if (n > 1) {
      distance = distance + 2 * height;
    }
    n--;
  }
  printf("distance = %lf(m)\nheight = %lf(m)\n",
         distance, height);

  return 0;
}
