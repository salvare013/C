// 题目：一个5位数，判断它是不是回文数。
// 如12321是回文数，个位与万位相同，十位与千位相同。

#include <assert.h>
#include <stdio.h>

int IsPalindromicNum(int num) {
  assert(num > 10000 && num < 100000);
  int unit, tens, thousand, myriabit;
  unit = num % 10;
  tens = num / 10 % 10;
  thousand = num / 1000 % 10;
  myriabit = num / 10000;
  if (unit == myriabit && tens == thousand) {
    return 1;
  } else {
    return 0;
  }
}
int main() {
  int num;
  printf("输入:>");
  scanf("%d", &num);
  if (1 == IsPalindromicNum(num)) {
    printf("%d是回文数\n", num);
  } else {
    printf("%d不是回文数\n", num);
  }

  // // 打印所有回文数
  // int i, count;
  // for (i = 10001; i < 100000; i++) {
  //   if (1 == IsPalindromicNum(i)) {
  //     printf("%d ", i);
  //     count++;
  //   }
  // }
  // printf("\ncount = %d\n", count);

  return 0;
}