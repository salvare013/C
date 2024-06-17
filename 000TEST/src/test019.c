// 题目：一个数如果恰好等于它的因子之和，这个数就称为"完数"。
// 例如6 = 1＋2＋3.编程找出10000以内的所有完数。

#include <stdio.h>
#include <math.h>

int IsPerfectNum(int num) {
    int i;
    int sum = 0;
    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    } if (sum == num) {
        return 1;
    } else {
        return 0;
    }
}
int main() {
    int i, k;
    int count = 0;
    for (i = 3; i < 10000; i++) {
        if (1 == IsPerfectNum(i)) {
            printf("%d = ", i);
            for (k = 1; k <= i / 2; k++) {
                if (i % k == 0) {
                    printf("%d", k);
                    if (k < i / 2) {
                        printf(" + ");
                    }
                }
            }
            printf("\n");
            count++;
        }
    }
    printf("count = %d\n", count);

    return 0;
}