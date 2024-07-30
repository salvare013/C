// 题目：猴子吃桃问题：
// 猴子第一天摘下若干个桃子，当即吃了一半，不过瘾，又多吃了一个,
// 第二天早上又将剩下的桃子吃掉一半，又多吃了一个。
// 以后每天早上都吃了前一天剩下的一半后再吃一个。
// 到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。

#include <stdio.h>

int main() {
  int before;
  int after = 1;
  int day = 9;
  while (day--) {
    before = 2 * (after + 1);
    after = before;
  }
  printf("第一天摘了%d个桃子\n", before);

  return 0;
}
