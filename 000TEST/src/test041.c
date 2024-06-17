// 题目：一个偶数总能表示为两个素数之和。

#include <assert.h>
#include <math.h>
#include <stdio.h>

int IsPrime(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return i;
    }
  }
  return 1;
}
void DecomposeEvenNum(int evenNum) {
  assert(evenNum % 2 == 0);
  int prime1, prime2;
  for (int i = 1; i < evenNum; i++) {
    if (IsPrime(i) == 1) {
      prime1 = i;
      for (int k = 1; k < evenNum; k++) {
        if (IsPrime(k) == 1)
          prime2 = k;
        if (prime1 + prime2 == evenNum) {
          printf("%d = %d + %d\n", evenNum, prime1, prime2);
          return;
        }
      }
    }
  }
}
int main() {
  int evenNum;
  printf("输入>:");
  scanf("%d", &evenNum);
  DecomposeEvenNum(evenNum);

  return 0;
}