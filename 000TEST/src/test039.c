// 题目：海滩上有一堆桃子，五只猴子来分。
// 第一只猴子把这堆桃子平均分为五份，多了一个，
// 这只猴子把多的一个扔入海中，拿走了一份。
// 第二只猴子把剩下的桃子又平均分成五份，又多了一个，
// 它同样把多的一个扔入海中，拿走了一份，
// 第三、第四、第五只猴子都是这样做的，
// 问海滩上原来"最少"有多少个桃子？
// 答案应为>3121

#include <stdio.h>

int main(void) {
  int last = 1;
  int i = 0;
  int sum;
  while (i < 5) {
    sum = last * 4;
    for (i = 0; i < 5; i++) {
      if (sum % 4 != 0) {
        last++;
        break;
      }
      sum = (sum / 4) * 5 + 1;
    }
  }
  printf("min_sum = %d\n", sum);

  return 0;
}