// 判断素数

#include <math.h>
#include <stdio.h>

int IsPrime(int num) {
  int i;
  for (i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  int i = 0;
  for (i = 1; i < 100; i++) {
    if (1 == IsPrime(i)) {
      printf("%d ", i);
    }
  }

  return 0;
}