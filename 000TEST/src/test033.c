// 题目：求一个3*3矩阵对角线元素之和

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PEOPLE 3

int main() {
  int matrix[PEOPLE][PEOPLE];
  int count = 0;
  int sum = 0;
  srand((unsigned int)time(NULL));
  for (int i = 0; i < PEOPLE; i++) {
    for (int j = 0; j < PEOPLE; j++) {
      matrix[i][j] = rand() % 10;
    }
  }
  for (int i = 0; i < PEOPLE; i++) {
    for (int j = 0; j < PEOPLE; j++) {
      printf("%d ", matrix[i][j]);
      count++;
      if (i == j) {
        sum += matrix[i][j];
      }
      if (count % 3 == 0) {
        printf("\n");
      }
    }
  }
  printf("sum = %d\n", sum);

  return 0;
}