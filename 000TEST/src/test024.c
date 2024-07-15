// 题目：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...
// 求出这个数列的前20项之和。

#include <stdio.h>

int main() {
  double molecule = 2.0;
  double denominator = 1.0;
  double sum = 0.0;
  int n = 20;
  while (n--) {
    sum += molecule / denominator;
    double den = molecule;
    molecule = molecule + denominator;
    denominator = den;
  }
  printf("sum = %lf\n", sum);

  return 0;
}