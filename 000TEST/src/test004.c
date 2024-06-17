// 题目：输入某年某月某日，判断这一天是这一年的第几天？

#include <assert.h>
#include <stdio.h>

int IsLeapYear(int year) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
    return 1;
  }
  return 0;
}

int main() {
  int year, month, day, sum;
  int month_day_sum = 0;
  printf("输入年 月 日:>");
  scanf("%d%d%d", &year, &month, &day);
  if (month == 2) {
    if (1 == IsLeapYear(year)) {
      assert(day < 30);
    } else {
      assert(day < 29);
    }
  }
  assert(month > 0 && month < 13);
  assert(day > 0 && day < 32);
  while (--month) {
    if (month == 2) {
      if (1 == IsLeapYear(year)) {
        month_day_sum += 29;
      } else {
        month_day_sum += 28;
      }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
      month_day_sum += 30;
    } else {
      month_day_sum += 31;
    }
  }
  sum = month_day_sum + day;
  printf("这天是这年的第%d天\n", sum);

  return 0;
}