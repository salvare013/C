// 题目：企业发放的奖金根据利润提成。
// 利润低于或等于10万元时，奖金可提10%；
// 利润高于10万元，低于20万元时，高于10万元的部分，可提成7.5%；
// 20万到40万之间时，高于20万元的部分，可提成5%；
// 40万到60万之间时,高于40万元的部分，可提成3%；
// 60万到100万之间时，高于60万元的部分，可提成1.5%，
// 高于100万元时，超过100万元的部分按1%提成，
// 从键盘输入当月利润，求应发放奖金总数？

#include <stdio.h>

// 我写的代码真牛逼!!!
double BonusSum(double profit) {
  if (profit <= 10.0) {
    return profit * 0.1;
  } else if (profit <= 20.0) {
    return (profit - 10.0) * 0.075 +
           BonusSum(10.0);
  } else if (profit <= 40.0) {
    return (profit - 20.0) * 0.05 +
           BonusSum(20.0);
  } else if (profit <= 60.0) {
    return (profit - 40.0) * 0.03 +
           BonusSum(40.0);
  } else if (profit <= 100.0) {
    return (profit - 60.0) * 0.015 +
           BonusSum(60.0);
  } else {
    return (profit - 100.0) * 0.01 +
           BonusSum(100.0);
  }
}

int main() {
  double bonus;   // 奖金
  double profit;  // 利润

  printf("输入利润(万元):>");
  scanf("%lf", &profit);
  bonus = BonusSum(profit);
  printf("bonus = %.2lf (万元)\n", bonus);

  return 0;
}